clear all
close all
clc

import casadi.*

addpath("computed_files/")


x0 = [0;0;0];
xf = x0+[1;3;-1];
t0 = 0;
tf = 5;
ts = 0.001;
time = t0:ts:tf;

[x_des, dx_des, ddx_des] = quinticpolytraj([x0 xf], [t0 tf], time);

pn = [10; 5];

for j = 1:4
    x = x0;
    dx = 0*x0;
    q = [x;dx];
    pr = pn;
    if j < 3
        pr(1) = pr(1)+(j-1)*1e-8;
    else
        pr(2) = pr(2)+(j-3)*1e-8;
    end
    Pi = zeros(2*length(x), length(pr), length(time));
    Pi_xi = zeros(0, length(pr), length(time));
    for i = 1:length(time)
        Qhistory_temp(:,i) = q;
        hvars = [q; pn; x_des(:,i); dx_des(:,i); ddx_des(:,i)];
        gvars = [];
        u= h_fun_mex(hvars);
        fvars = [q;u;pr];
        dq = f_mex(fvars);
        fvars = [q;u;pn]; %The derivative must be computed with pr=pn
        Theta_i = dh_q_mex(hvars) * Pi(:,:,i) + dh_xi_mex(hvars)*Pi_xi(:,:,i);
        dPi_i = df_q_mex(fvars)*Pi(:,:,i)+df_u_mex(fvars)*Theta_i+df_p_mex(fvars);
        dPi_xi_i = 0*Pi_xi(:,:,i);
        Theta(:,:,i) = Theta_i;
        Pi(:,:,i+1) = Pi(:,:,i)+dPi_i*ts;
        Pi_xi(:,:,i+1) = Pi_xi(:,:,i) + dPi_xi_i*ts;
        q = q+dq*ts;
    end
    if rem(j,2)
        for i = 1:length(time)
            Pihistory_temp(:,i) = Pi(:,ceil(j/2),i);
        end
        Pi_history{ceil(j/2)} = Pihistory_temp;
    end
    Qhistory{j} = Qhistory_temp;
end
for j = 1:2
    Pi_comp = (Qhistory{2*j}-Qhistory{2*j-1})/1e-8;
    figure
    for i = 1:length(q)
        subplot(length(q)/2,2,i)
        plot(time,Pi_comp(i,:), "LineWidth",2)
        hold on
        plot(time,Pi_history{j}(i,:), "--", "LineWidth",2)
        grid on
    end
    sgtitle(string("$$\Pi_"+j+"$$"), "Interpreter", "latex", "FontSize",30)
end
hold off