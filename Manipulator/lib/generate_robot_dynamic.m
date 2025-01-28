function [Mfun, Cfun, Gfun, Dfun, Tfun, Jfun, dJfun, dJdqfun] = generate_robot_dynamic(robot)
import casadi.*
disp("Generating Functions...")

n = length(robot.links);
mr = MX.sym('mr',1,n);
for i = 1:n
    robot.links(i).m = mr(i);
end
pr = mr;
q = MX.sym('q',n,1);
dq = MX.sym('dq',n,1);

tic()
Mcomp = MX.zeros(n,n);
Gcomp = MX.zeros(n,1);
for i = 1:n
    Links = robot.links(1:i);
    mi = Links(end).m;
    comi = Links(end).r;
    Ti = MX.eye(4);
    for j = 1:i
        thetaj = Links(j).offset+q(j);
        alphaj = Links(j).alpha;
        aj = Links(j).a;
        dj = Links(j).d;
        Ti = simplify(Ti*[cos(thetaj) -sin(thetaj)*cos(alphaj)  sin(thetaj)*sin(alphaj) aj*cos(thetaj);...
            sin(thetaj)  cos(thetaj)*cos(alphaj) -cos(thetaj)*sin(alphaj) aj*sin(thetaj);...
            0           sin(alphaj)             cos(alphaj)            dj;...
            0           0                      0                     1]);
    end
    Tcomp = Ti;
    Ti = Ti*trvec2tform(comi);
    Ri = Ti(1:3,1:3);
    Jvi = simplify(jacobian(Ti(1:3,4),q));
    Jvi = Jvi(:,1:i);
    Jomegai = MX.zeros(3,i);
    for j = 1:i
        dR = jacobian(Ri, q);
        jR = reshape(dR(:,j),3,3);
        %         jR = [dR(1:3,j) dR(4:6,j) dR(7:9,j)];
        S = simplify(jR * Ri');
        Jomegai(:,j) = [S(3,2); S(1,3); S(2,1)];
    end
    Ii = Links(end).I;
    Mcomp(1:i,1:i) = Mcomp(1:i,1:i)+simplify(mi*Jvi.'*Jvi+Jomegai.'*Ri*Ii*Ri.'*Jomegai);
    Gcomp(1:i) = Gcomp(1:i) + simplify((Jvi.'*mi*[0; 0; 9.81]));
end

Jcomp = [jacobian(Tcomp(1:3,4),q);Jomegai];
dJ = jacobian(Jcomp(:),q);
dJcomp = zeros(6,n);
for i = 1:n
    dJcomp = dJcomp+reshape(dJ(:,i),6,n)*dq(i);
end
dJdqcomp = dJcomp*dq;
for k = 1:n
    Chris{k} = MX.zeros(n,n);
end
for i = 1:n
    for j = 1:n
        for k = 1:n
            dMk = jacobian(Mcomp(i,j),q);
            dMj = jacobian(Mcomp(i,k),q);
            dMi = jacobian(Mcomp(j,k),q);
            Chris{k}(i,j) = simplify(0.5*(dMk(k) + dMj(j) - dMi(i)));
        end
    end
end

Ccomp = MX.zeros(n,n);
for i = 1:n
    for j = 1:n
        for k = 1:n
            Ccomp(i,j) = (Ccomp(i,j) + Chris{k}(i,j)*dq(k));
        end
    end
end

Mfun = simplify(Mcomp);
Gfun = simplify(Gcomp);
Cfun = simplify(Ccomp);
Mfun = Function('Mfun', {q, pr},{Mcomp});
Mfun = Mfun.expand();
Gfun = Function('Gfun', {q, pr},{Gcomp});
Gfun = Gfun.expand();
Cfun = Function('Cfun', {q,dq, pr},{Ccomp});
Cfun = Cfun.expand();
Tfun = Function('Tfun', {q},{Tcomp});
Tfun = Tfun.expand();
Jfun = Function('Jfun', {q},{Jcomp});
Jfun = Jfun.expand();
dJfun = Function('dJfun', {q,dq},{dJcomp});
dJfun = dJfun.expand();
dJdqfun = Function('dJdqfun', {q,dq},{dJdqcomp});
dJdqfun = dJdqfun.expand();
% Dfun = Function('Dfun',{pr},{Dcomp});
end