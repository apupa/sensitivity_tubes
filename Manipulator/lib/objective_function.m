function f = objective_function(x, order, q0, qf, t0, tf, ts, pn, var, order_sq, value)
global x_last myf myc myceq
if ~isequal(x,x_last) % Check if computation is necessary
    [myf,myc,myceq] = sensitivity_function_mex(x, order, q0, qf, t0, tf, ts, pn, var, order_sq, value);
    x_last = x;
end
f = myf;