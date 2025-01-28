clear all
close all
clc

import casadi.*
addpath("lib/")
addpath("computed_files/")

filename = "computed_files/functions_sensitivity.mat";
load(filename)

box = false;
order_sq = 50;
variation = 0.25;
x0 = [0;0;0];
xf = x0+[1;3;-1];
t0 = 0;
tf = 5;
ts = 0.005;
time = t0:ts:tf;
pn = [10; 5];
pr = pn;

order = 8;

opti = casadi.Opti();
a_cas = MX.sym('a_cas',3*(order+1),1);
a = MX.zeros(order+1,3);
for i = 1:3
    a(:,i) = a_cas((order+1)*(i-1)+1:(order+1)*i);
end
Pi = MX.zeros(2*length(x0),length(pr));
Pi_xi = MX.zeros(0,length(pr));
q = [x0;0*x0];
x_des = MX.zeros(length(x0), length(time));
dx_des = MX.zeros(length(x0), length(time));
ddx_des = MX.zeros(length(x0), length(time));
W = diag(pn*variation).^2;
for j = 1:3
    x_des(j,:) = polyval(a(:,j),time);
    dx_des(j,:) = polyval(my_polyder(a(:,j)),time);
    ddx_des(j,:) = polyval(my_polyder(my_polyder(a(:,j))),time);
end

x = MX.sym('x');
n = MX.sym('n');

alpha = MX.zeros(length(q)/2,1);
constr = MX.zeros(length(q)*length(time),1);
idx = 1;

disp("Creating Function")
for i = 1:length(time)
    hvars = [q; pn; x_des(:,i); dx_des(:,i); ddx_des(:,i)];
    gvars = [];
    u = h_fun(hvars);
    fvars = [q;u;pr];
    dq = f(fvars);
    fvars = [q;u;pn]; %The derivative must be computed with pr=pn
    Theta_i = dh_q(hvars) * Pi + dh_xi(hvars)*Pi_xi;
    dPi_i = df_q(fvars)*Pi+df_u(fvars)*Theta_i+df_p(fvars);
    dPi_xi_i = 0*Pi_xi;

    %Build Tube constraint
    if i > 3
        Ktheta = Theta_i*W*Theta_i.';
        P = Theta_i*sqrtm(W);
        N = eye(length(u));
        for j = 1:length(N)
            n = N(:,j);
            if box
                alpha(j) = abs(n.'*Theta_i)*sqrt(diag(W));
            else
                alpha(j) = nthroot_cas(n.'*P*nthroot_cas(P.'*n,(2*order_sq-1)),(2*order_sq)/(2*order_sq-1));
            end
        end
    end
    for j = 1:length(u)
        for k = 1:2
            s = (-1)^k;
            constr(idx) = u(j)+s*alpha(j);
            idx = idx +1;
        end
    end

    Theta = Theta_i;
    Pi = Pi+dPi_i*ts;
    Pi_xi = Pi_xi + dPi_xi_i*ts;
    q = q+dq*ts;
end

a0 = generateInitialGuess(order, t0, tf, x0, xf);
lbx = -1000*ones(size(a_cas));
ubx = 1000*ones(size(a_cas));
J = simplify(norm_fro(Pi*W*Pi.'));
g = [x_des(:,1); x_des(:,end); dx_des(:,1); dx_des(:,end); ddx_des(:,1); ddx_des(:,end); simplify(constr)];
lbg = [x0; xf; zeros(12,1); -16*ones(length(constr),1)];
ubg = [x0; xf; zeros(12,1); 16*ones(length(constr),1)];

disp("Starting Solver")
prob = struct('f', J, 'x', a_cas, 'g', g);
options = struct;
options.ipopt.max_iter = 10000; %For this specific case, 500 iterations are enough
% options.ipopt.print_level = 0;
% options.print_time = 0;
options.expand = true;
solver = nlpsol('solver', 'ipopt', prob, options);
sol = solver('x0', a0, 'lbx', lbx, 'ubx', ubx, ...
    'lbg', lbg, 'ubg', ubg);
%
res = full(sol.x);
if box
    name = "res_box.mat";
else
    name = "res_sq.mat";
end
save(name, "res")
for i = 1:3
    A(:,i) = res((order+1)*(i-1)+1:(order+1)*i);
end
A

x_des = [];
dx_des = [];
ddx_des = [];
for i = 1:3
    x_des(i,:) = polyval(A(:,i),time);
    dx_des(i,:) = polyval(polyder(A(:,i)),time);
    ddx_des(i,:) = polyval(polyder(polyder(A(:,i))),time);
end
q = [x0; 0*x0];
for i = 1:length(time)
    Qhistory(:,i) = q;
    hvars = [q; pn; x_des(:,i); dx_des(:,i); ddx_des(:,i)];
    gvars = [];
    u = h_fun_mex(hvars);
    fvars = [q;u;pr];
    dq = f_mex(fvars);
    q = q+dq*ts;
    Uhistory(:,i) = u;
end
figure
plot(time,Qhistory(1:3,:), "LineWidth",2)
title("$$x$$", "Interpreter", "latex", "FontSize",30)
grid on

figure
plot(time,Qhistory(4:6,:), "LineWidth",2)
title("$$\dot{x}$$", "Interpreter", "latex", "FontSize",30)
grid on


tube_f = Function('tube_f', {a_cas},{constr});
tube_tmp = full(tube_f(res));
tubes = [];

idx = 1;
for k = 1:length(time)
    for i = 1:length(u)
        for j = 1:2
            tubes(k,j,i) = tube_tmp(idx);
            idx = idx + 1;
        end
    end
end

figure
for i = 1:3
    subplot(2,2,i)
    plot(time,tubes(:,:,i), "--", "LineWidth",2, "Color","k")
    hold on
    plot(time,Uhistory(i,:), "LineWidth",2)
    grid on
    plot(time, 16*ones(length(time),1), "r", "LineWidth",3)
    plot(time, -16*ones(length(time),1), "r", "LineWidth",3)
end
sgtitle("$$u$$", "Interpreter", "latex", "FontSize",30)

%% SIMULATION USED IN THE PAPER
% Qhistory = [];
% Uhistory = [];
% for k = 1:100
%     % k
%     q = [x0;0*x0];
%     Qhistory_tmp = [];
%     Uhistory_tmp = [];
%     pr = pn .* (1+(-variation+2*variation*rand(size(pn))));
%     for i = 1:length(time)
%         hvars = [q; pn; x_des(:,i); dx_des(:,i); ddx_des(:,i)];
%         gvars = [];
%         u = full(h_fun(hvars));
%         fvars = [q;u;pr];
%         dq = full(f(fvars));
%         Qhistory_tmp(:,i) = q;
%         Uhistory_tmp(:,i) = u;
%         q = q + dq*ts;
%     end
%     Qhistory{k} = Qhistory_tmp;
%     Uhistory{k} = Uhistory_tmp;
% end
% 
% 
% figure
% for i = 1:3
%     if i == 1
%         subplot(2,11,[1,5])
%     elseif i == 2
%         subplot(2,11,[7,11])
%     else
%         subplot(2,11,[15,19])
%     end
%     set(gca,"TickLabelInterpreter",'latex')
%     set(gca,"FontSize", 21)
%     hold on
%     for k = 1:length(Uhistory)
%         plot(time,Uhistory{k}(i,:), "LineWidth",1, "Color", rand*[1 1 1])
%     end
%     plot(time,tubes(:,:,i), "-", "LineWidth",2, "Color",[0.9290 0.6940 0.1250])
%     grid on
%     plot(time, 16*ones(length(time),1), "r", "LineWidth",3)
%     plot(time, -16*ones(length(time),1), "r", "LineWidth",3)
%     axis([0,5,-20,20])
%     if i == 3
%         xlabel("time $[s]$", "Interpreter","latex")
%     end
%     ylabel(string("$u_"+i+"$ $[N]$"), "Interpreter","latex")
%     % if i == 2
%     %     ax = gca;
%     %     ax.YAxisLocation = "right";
%     % end
% end
% sgtitle("\boldmath$u$", "Interpreter", "latex", "FontSize",40)
% 
% %Volume of superquadric
% % V = (l^n) * (gamma(1 + 1/(2*k))^n) / gamma(1 + n/(2*k))
% 
% if box
%     load("res_box.mat")
%     res_box = res;
%     load("res_sq.mat")
%     res_sq = res;
%     cost_fun = Function('cost_fun',{a_cas},{J});
%     cf_box = cost_fun(res_box);
%     cf_sq = cost_fun(res_sq);
%     constr_fun = Function('constr_fun',{a_cas},{g});
%     ub_dev_box = min(ubg-constr_fun(res_box));
%     ub_dev_sq = min(ubg-constr_fun(res_sq));
%     lb_dev_box = min(constr_fun(res_box)-lbg);
%     lb_dev_sq = min(constr_fun(res_sq)-lbg);
% 
%     Category = ["Box"; "Superquadric"];
%     Cost = [full(cf_box); full(cf_sq)];
%     UBInfesibility = [full(ub_dev_box); full(ub_dev_sq)];
%     LBInfesibility = [full(lb_dev_box); full(lb_dev_sq)];
%     t = table(Category, Cost, UBInfesibility, LBInfesibility)
% 
% end
% 
