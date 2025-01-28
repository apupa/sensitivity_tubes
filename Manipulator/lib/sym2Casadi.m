function M = sym2Casadi(M,p)
import casadi.*

for i = 1:length(p)
    tmp = p(i);
    name = tmp.name;
    eval(string(name+"=p(i);"))
end
Ms = string(M);
M = SX.zeros(size(Ms));
for i = 1:size(M,1)
    for j = 1:size(M,2)
        M(i,j) = eval(Ms(i,j));
    end
end