clear all
clc
close all

addpath("..\..\..\casadi_matlab\")
addpath("lib")
import casadi.*

n = 6;
robot = import_model(n);
[Mfun, Cfun, Gfun] = generate_robot_dynamic(robot);

q = MX.sym('q',n,1);
dq = MX.sym('dq',n,1);

mr = MX.sym('mr',n,1);
mn = MX.sym('mn',n,1);

pr = mr;
pn = mn;

Mr = Mfun(q,pr);
Cr = Cfun(q,dq,pr);
Gr = Gfun(q,pr);

Mn = Mfun(q,pn);
Cn = Cfun(q,dq,pn);
Gn = Gfun(q,pn);

u = MX.sym('u',n,1);
ddq = simplify(inv(Mr,'symbolicqr')*(u-Cr*dq-Gr));

q_des = MX.sym('q_des',n,1);
dq_des = MX.sym('dq_des',n,1);
ddq_des = MX.sym('ddq_des',n,1);

h_fun = simplify(Mn*(ddq_des+100*(q_des-q)+10*(dq_des-dq))+Cn*dq+Gn);

x = [q;dq];
f = [dq; ddq];
df_q = simplify(jacobian(f,x));
df_u = simplify(jacobian(f,u));
df_p = simplify(jacobian(f,pr));
dh_q = simplify(jacobian(h_fun,x));

names = ["f","df_q","df_u","df_p", "h_fun", "dh_q"];
fvars = [x; u; pr];
hvars = [x; pn; q_des; dq_des; ddq_des];

path = "computed_files_"+n+"dofs/";
opts = struct('main', true,...
              'mex', true);
mkdir(path)
for i = 1:length(names)
    if i <= 4
        vars = "[x; u; pr]";
    else
        vars = "[x; pn; q_des; dq_des; ddq_des]";
    end
    command = names(i)+"=Function('"+names(i)+"',{"+vars+"},{"+names(i)+"});";
    eval(command);
    command = names(i)+"="+names(i)+".expand();";
    eval(command);
    cfile = char(names(i)+".c");
    command = names(i)+".generate(cfile,opts);";
    eval(command);
    command = "mex -output "+ path + names(i) + "_mex " + cfile + " -largeArrayDims";
    eval(command);
    command = "movefile " + cfile + " " +path + cfile;
    eval(command);
end

