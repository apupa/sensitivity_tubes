function y = nthroot_cas(x, n)
%This function is basically a copy of nthroot matlab to be sure that it
%works with CASADI MX

% Be sure that the number is positive with even exponent
y = if_else(rem(n, 2) == 0, ...
    if_else(x >= 0, x^(1/n), nan), ...  % For even n, check if x is non-negative
    sign(x) * abs(x)^(1/n));  

% y = (sign(x) + (x==0)) .* (abs(x).^(1./n));

% Correct numerical errors (since, e.g., 64^(1/3) is not exactly 4)
% by one iteration of Newton's method
y = y - (y.^n - x) ./ (n .* y.^(n-1));
