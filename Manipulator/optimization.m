clear all
close all
clc

n_dofs = 6;
addpath("lib/")
addpath("computed_files_"+n_dofs+"dofs/")

box = false;
order_sq = 10;
variation = 0.2;

q0 = [0 -pi*0.6 pi*0.6 -pi/2 -pi/2 0].';
q0 = q0(1:n_dofs);

qf = [pi/2 -pi*0.6 pi*0.6 -pi/2 -pi/2 0].';
qf = qf(1:n_dofs);

t0 = 0;
tf = 1;
ts = 0.005;

ur = import_model(n_dofs);
for i = 1:n_dofs
    pn(i,1) = ur.links(i).m;
end

pr = pn;

order = 8;

a0 = generateInitialGuess(order, t0, tf, q0, qf);

options = optimoptions('fmincon','SpecifyObjectiveGradient',false,...
    'SpecifyConstraintGradient',false,'Display','iter',...
    'UseParallel', true, 'MaxFunctionEvaluations',1);

cd lib
codegen -v sensitivity_function.m -args {a0, order, q0, qf, t0, tf, ts, pn, variation, order_sq, 0}
cd ..

[f, c, ceq] = sensitivity_function_mex(a0, order, q0, qf, t0, tf, ts, pn, variation, order_sq, 0);

value = floor(max(abs(c)))*0.92;
cost_function = @(a)objective_function(a, order, q0, qf, t0, tf, ts, pn, variation, order_sq, value);
nl_constr = @(a)nonlinear_constraint(a, order, q0, qf, t0, tf, ts, pn, variation, order_sq, value);
lbx = -1000*ones(size(a0));
ubx = 1000*ones(size(a0));
disp("Starting Solver")
tic()
[x,fval] = fmincon(cost_function,a0,[],[],[],[],lbx,ubx,nl_constr,options);
toc()

options = optimoptions('fmincon','SpecifyObjectiveGradient',false,...
    'SpecifyConstraintGradient',false,'Display','iter',...
    'UseParallel', true, 'MaxFunctionEvaluations',10e4,...
    'StepTolerance',1e-5);
tic()
[x,fval] = fmincon(cost_function,a0,[],[],[],[],lbx,ubx,nl_constr,options);
toc()


res = x;
%%
time = t0:ts:tf;
for i = 1:n_dofs
    A(:,i) = res((order+1)*(i-1)+1:(order+1)*i);
end

q_des = [];
dq_des = [];
ddq_des = [];
for i = 1:n_dofs
    q_des(i,:) = polyval(A(:,i),time);
    dq_des(i,:) = polyval(polyder(A(:,i)),time);
    ddq_des(i,:) = polyval(polyder(polyder(A(:,i))),time);
end
x = [q0; 0*q0];

q_total = [];
u_total = [];

for k = 1:500
    x = [q0; 0*q0];
    pr = pn .*(1-variation+2*variation*rand(length(pr),1));
    for i = 1:length(time)
        q_history(:,i) = x;
        q = x(1:n_dofs);
        dq = x(n_dofs+1:end);
        hvars = [x; pn; q_des(:,i); dq_des(:,i); ddq_des(:,i)];
        gvars = [];
        u= h_fun_mex(hvars);
        fvars = [x;u;pr];
        dx = f_mex(fvars);
        x = x+dx*ts;
        u_history(:,i) = u;
    end
    q_total(:,:,k) = q_history;
    u_total(:,:,k) = u_history;
end


close all
figure



plot(time,q_history(1:n_dofs,:), "LineWidth",2)
title("$$x$$", "Interpreter", "latex", "FontSize",30)
grid on

figure
plot(time,q_history(n_dofs+1:end,:), "LineWidth",2)
title("$$\dot{x}$$", "Interpreter", "latex", "FontSize",30)
grid on

[myf,myc,myceq] = sensitivity_function_state(res, order, q0, qf, t0, tf, ts, pn, variation, order_sq,0);

idx = 1;
for k = 1:length(time)
    for i = 1:length(x)
        for j = 1:2
            tubes_s(k,j,i) = myc(idx);
            idx = idx + 1;
        end
    end
end

[myf,myc,myceq] = sensitivity_function_state(res, order, q0, qf, t0, tf, ts, pn, variation, 1,0);

idx = 1;
for k = 1:length(time)
    for i = 1:length(x)
        for j = 1:2
            tubes_s_ell(k,j,i) = myc(idx);
            idx = idx + 1;
        end
    end
end

figure 
for i = 1:n_dofs
    subplot(ceil(n_dofs/2),2,i)
    hold on
    for k = 1:size(q_total,3)
        plot(time,q_total(i,:,k), "LineWidth",1, "Color", rand*[1 1 1])           
    end
    plot(time,tubes_s(:,:,i), "-", "LineWidth",2, "Color",[0.9290 0.6940 0.1250])
    plot(time,tubes_s_ell(:,:,i), "-", "LineWidth",2, "Color",[0.4660 0.6740 0.1880])
    grid on
    set(gca,"TickLabelInterpreter",'latex')
    set(gca,"FontSize", 25)
    xlabel("time $[s]$", "Interpreter","latex")
    ylabel(string("$q_"+i+"$ $[rad]$"), "Interpreter","latex")

end
sgtitle("\boldmath$q$", "Interpreter", "latex", "FontSize",40)

[myf,myc,myceq] = sensitivity_function(res, order, q0, qf, t0, tf, ts, pn, variation, order_sq,0);


idx = 1;
for k = 1:length(time)
    for i = 1:length(u)
        for j = 1:2
            tubes(k,j,i) = myc(idx);
            idx = idx + 1;
        end
    end
end



[myf,myc,myceq] = sensitivity_function(res, order, q0, qf, t0, tf, ts, pn, variation, 1,0);
idx = 1;
for k = 1:length(time)
    for i = 1:length(u)
        for j = 1:2
            tubes_ell(k,j,i) = myc(idx);
            idx = idx + 1;
        end
    end
end


figure
for i = 1:n_dofs
    subplot(ceil(n_dofs/2),2,i)
     hold on
    for k = 1:size(u_total,3)
        plot(time,u_total(i,:,k), "LineWidth",1,"Color", rand*[1 1 1])
    end
    plot(time,tubes(:,:,i), "-", "LineWidth",2, "Color",[0.9290 0.6940 0.1250])
    plot(time,tubes_ell(:,:,i), "-", "LineWidth",2, "Color",[0.4660 0.6740 0.1880])
    grid on
    set(gca,"TickLabelInterpreter",'latex')
    set(gca,"FontSize", 25)
    if i == 2 || i == 3
        plot(time, -value*ones(length(time),1), "r", "LineWidth",3)
    end
    xlabel("time $[s]$", "Interpreter","latex")
    ylabel(string("$u_"+i+"$ $[Nm]$"), "Interpreter","latex")

end
sgtitle("\boldmath$u$", "Interpreter", "latex", "FontSize",40)

