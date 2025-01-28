clear all
close all
clc

import casadi.*

x = MX.sym('x',3,1);
dx = MX.sym('dx',3,1);

mr = MX.sym('mr');
br = MX.sym('br');
Mr = eye(3)*mr;
Br = eye(3)*br;

u = MX.sym('u',3,1);

iMr = diag(1./diag(Mr));
ddx = iMr*(u-Br*dx);

q = [x;dx];
dq = [dx;ddx];


mn = MX.sym('mn');
bn = MX.sym('bn');
Mn = eye(3)*mn;
Bn = eye(3)*bn;

x_des = MX.sym('x_des',3,1);
dx_des = MX.sym('dx_des',3,1);
ddx_des = MX.sym('ddx_des',3,1);

f = dq;
h = Bn*dx+Mn*(ddx_des+100*(x_des-x)+10*(dx_des-dx));

pr = [mr;br];
pn = [mn;bn];

df_q = (jacobian(f,q));
df_u = simplify(jacobian(f,u));

dh_q = simplify(jacobian(h,q));

xi = MX.zeros(0);
dh_xi = simplify(jacobian(h,xi));

g = MX.zeros(0);
dg_q = simplify(jacobian(g, q));

dg_xi = simplify(jacobian(g, xi));

df_p = simplify(jacobian(f,pr));

fvars = [q; u; pr];
hvars = [q; pn; x_des; dx_des; ddx_des];
gvars = [];

f = Function('f',{fvars}, {f});
h_fun = Function('h_fun',{hvars}, {h});

df_q = Function('df_q',{fvars}, {df_q});
df_u = Function('df_u',{fvars}, {df_u});
df_p = Function('df_p', {fvars}, {df_p});

dh_q = Function('dh_q',{hvars}, {dh_q});
dh_xi = Function('dh_xi',{hvars}, {dh_xi});

dg_q = Function('dg_q',{gvars}, {dg_q});
dg_xi = Function('dg_xi',{gvars}, {dg_xi});

names = ["f","h_fun","df_q","df_u","df_p","dh_q","dh_xi","dg_q","dg_xi"];

opts = struct('main', true,...
              'mex', true);
mkdir("computed_files/")
for i = 1:length(names)
    command = names(i)+"="+names(i)+".expand();";
    eval(command);
    cfile = char(names(i)+".c");
    command = names(i)+".generate(cfile,opts);";
    eval(command);
    command = "mex -output computed_files/" + names(i) + "_mex " + cfile + " -largeArrayDims";
    eval(command);
    command = "movefile " + cfile + " computed_files/" + cfile;
    eval(command);
end
filename = "computed_files/functions_sensitivity.mat";
save(filename,"f","h_fun","df_q","df_u","df_p","dh_q","dh_xi","dg_q","dg_xi");
