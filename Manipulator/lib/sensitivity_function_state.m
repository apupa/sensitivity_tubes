function [myf,myc,myceq] = sensitivity_function_state(a, order, q0, qf, t0, tf, ts, pn, var, order_sq, value)
% tic()
n = length(q0);
% addpath(string("new_manual_computed_files_"+n+"dofs\"));
% 
% n = length(q0);
% A = zeros(order+1,n);
% for i = 1:n
%     A(:,i) = a((order+1)*(i-1)+1:(order+1)*i);
% end
% q = q0;
% dq = 0*q0;
% x = [q;dq];
% 
% pr = pn;
% Pi = zeros(2*length(q), length(pr));
% W = diag(var*pn).^2;
% 
% time = t0:ts:tf;
% 
% q_des = zeros(n,length(time));
% dq_des = q_des;
% ddq_des = dq_des;
% for j = 1:n
%     q_des(j,:) = polyval(A(:,j),time);
%     dq_des(j,:) = polyval(my_polyder(A(:,j)),time);
%     ddq_des(j,:) = polyval(my_polyder(my_polyder(A(:,j))),time);
% end
% breaks = [t0-1 t0 tf tf+1];
% coefs = [[zeros(n,order) q0];A.';[zeros(n, order) qf]];
% pp = mkpp(breaks,coefs,n);
% fun = @(t,x0)system_model(t, x0, pn, pr, pp, W, order_sq);
% Pi = zeros(2*length(q), length(pr));
% x0 = [x; reshape(Pi,[],1)];    
% [t_ode,q_ode] = ode23(fun,time,x0);
% 
% constr = zeros(2*n*length(t_ode),1);
% for i = 1:length(t_ode)
%     [dx C] = fun(t_ode(i),q_ode(i,:).');
%     constr(2*n*(i-1)+1:2*n*i) = C;
% end
% q_ode(:,1:2*length(q)) = [];
% q_ode = q_ode.';
% Pi = reshape(q_ode, 2*length(q), length(pr), length(time));
% 
% myf = norm(Pi(:,:,end)*W*Pi(:,:,end).');
% myc = [constr-value; -value-constr];
% myceq = [q_des(:,1)-q0; q_des(:,end)-qf;...
%     dq_des(:,1)-zeros(n,1); dq_des(:,end)-zeros(n,1);...
%     ddq_des(:,1)-zeros(n,1); ddq_des(:,end)-zeros(n,1)];
% toc()
% end

cas = true;
% if cas
%     addpath(string("new_manual_computed_files_"+n+"dofs\"));
% end
A = zeros(order+1,n);
for i = 1:n
    A(:,i) = a((order+1)*(i-1)+1:(order+1)*i);
end
q = q0;
dq = 0*q0;
x = [q;dq];

pr = pn;
Pi = zeros(2*length(q), length(pr));
W = diag(var*pn).^2;
% , length(time));
% Theta = zeros(length(q), length(pr), length(time));

time = t0:ts:tf;

q_des = zeros(n,length(time));
dq_des = q_des;
ddq_des = dq_des;
for j = 1:n
    q_des(j,:) = polyval(A(:,j),time);
    dq_des(j,:) = polyval(my_polyder(A(:,j)),time);
    ddq_des(j,:) = polyval(my_polyder(my_polyder(A(:,j))),time);
end

constr = zeros(n*length(time)*2,1);
idx = 1;

coder.extrinsic("h_fun_mex")
coder.extrinsic("f_mex")
coder.extrinsic("dh_q_mex")
coder.extrinsic("df_q_mex")
coder.extrinsic("df_u_mex")
coder.extrinsic("df_p_mex")
u = q;
dx = 0*x;
dh_q = zeros(length(u),length(x));
df_q = zeros(length(x),length(x));
df_u = zeros(length(x),length(u));
df_p = zeros(length(x),length(pn));
for k = 1:length(time)
    % Qhistory_temp(:,k) = x;
    q = x(1:n);
    dq = x(n+1:end);
    if cas
        hvars = [x; pn; q_des(:,k); dq_des(:,k); ddq_des(:,k)];
        u = h_fun_mex(hvars);
        fvars = [x;u;pr];
        dx = f_mex(fvars);
        dh_q = dh_q_mex(hvars);
        df_q = full(df_q_mex(fvars));
        df_u = full(df_u_mex(fvars));
        df_p = full(df_p_mex(fvars));

    else
        rvars = [x;pr];
        nvars = [x;pn];
        Mr = Mr_mex(rvars);
        Cr = Cr_mex(rvars);
        Gr = Gr_mex(rvars);

        Mn = Mn_mex(nvars);
        Cn = Cn_mex(nvars);
        Gn = Gn_mex(nvars);

        iMr = pinv(Mr);
        u = Mn*(ddq_des(:,k)+100*(q_des(:,k)-q)+10*(dq_des(:,k)-dq))...
            +Cn*dq+Gn;
        dx = [dq; iMr*(u-Cr*dq-Gr)];


        dMr_q = dMr_q_mex(rvars);
        dCr_q = dCr_q_mex(rvars);
        dCr_dq = dCr_dq_mex(rvars);
        dGr_q = dGr_q_mex(rvars);

        dMr_p = dMr_p_mex(rvars);
        dCr_p = dCr_p_mex(rvars);
        dGr_p = dGr_p_mex(rvars);

        dMn_q = dMn_q_mex(nvars);
        dCn_q = dCn_q_mex(nvars);
        dCn_dq = dCn_dq_mex(nvars);
        dGn_q = dGn_q_mex(nvars);

        df_q = [zeros(n) eye(n);...
            zeros(n) -iMr*Cr];
        df_p = [zeros(n,n);...
            zeros(n,n)];
        df_u = [zeros(n,n);iMr];
        dh_q = [-100*Mn -10*Mn+Cn];
        for i = 1:n
            df_q(n+1:end,i)=-iMr*dMr_q(:,n*(i-1)+1:n*i)*iMr*(u-Cr*dq-Gr)...
                -iMr*(dCr_q(:,n*(i-1)+1:n*i)*dq+dGr_q(:,i));

            df_q(n+1:end,i+n) = df_q(n+1:end,i+n) - iMr*dCr_dq(:,n*(i-1)+1:n*i)*dq;


            df_p(n+1:end,i)=-iMr*dMr_p(:,n*(i-1)+1:n*i)*iMr*(u-Cr*dq-Gr)...
                -iMr*(dCr_p(:,n*(i-1)+1:n*i)*dq+dGr_p(:,i));

            dh_q(:,i)=dh_q(:,i)+dMn_q(:,n*(i-1)+1:n*i)*(ddq_des(:,k)...
                +100*(q_des(:,k)-q)+10*(dq_des(:,k)-dq))...
                +(dCn_q(:,n*(i-1)+1:n*i)*dq+dGn_q(:,i));

            dh_q(:, i+n) = dh_q(:, i+n)+dCn_dq(:,n*(i-1)+1:n*i)*dq;
        end
    end

    % Theta_k = dh_q * Pi(:,:,k);
    % dPi_k = df_q*Pi(:,:,k)+df_u*Theta_k+df_p;
    % Theta(:,:,k) = Theta_k;
    % Pi(:,:,k+1) = Pi(:,:,k)+dPi_k*ts;
    Theta_k = dh_q * Pi;
    dPi_k = df_q*Pi+df_u*Theta_k+df_p;
    P = Pi*sqrt(W);
    N = eye(length(x));
    for j = 1:length(N)
        v = N(:,j);
        alpha = nthroot(v.'*P*nthroot(P.'*v,(2*order_sq-1)),(2*order_sq)/(2*order_sq-1));
        % alpha = nthroot(v.'*Theta_k*nthroot(W.^order_sq*Theta_k.'*v,2*order_sq-1),(2*order_sq)/(2*order_sq-1));
        constr(idx) = x(j)+alpha;
        constr(idx+1) = x(j)-alpha;
        idx = idx +2;
    end

    Pi = Pi+dPi_k*ts;
    x = x+dx*ts;


end
myf = norm(Pi*W*Pi.');
myc = [constr-value; -value-constr];
myceq = [q_des(:,1)-q0; q_des(:,end)-qf;...
    dq_des(:,1)-zeros(n,1); dq_des(:,end)-zeros(n,1);...
    ddq_des(:,1)-zeros(n,1); ddq_des(:,end)-zeros(n,1)];
% toc()