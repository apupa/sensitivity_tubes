function [myf,myc,myceq] = sensitivity_function(a, order, q0, qf, t0, tf, ts, pn, var, order_sq, value)
n = length(q0);


cas = true;

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
    q = x(1:n);
    dq = x(n+1:end);
    hvars = [x; pn; q_des(:,k); dq_des(:,k); ddq_des(:,k)];
    u = h_fun_mex(hvars);
    fvars = [x;u;pr];
    dx = f_mex(fvars);
    dh_q = dh_q_mex(hvars);
    df_q = full(df_q_mex(fvars));
    df_u = full(df_u_mex(fvars));
    df_p = full(df_p_mex(fvars));



    Theta_k = dh_q * Pi;
    dPi_k = df_q*Pi+df_u*Theta_k+df_p;
    P = Theta_k*sqrt(W);
    N = eye(length(u));
    for j = 1:length(N)
        v = N(:,j);
        alpha = nthroot(v.'*P*nthroot(P.'*v,(2*order_sq-1)),(2*order_sq)/(2*order_sq-1));
        constr(idx) = u(j)+alpha;
        constr(idx+1) = u(j)-alpha;
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
