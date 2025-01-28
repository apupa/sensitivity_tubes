function a0 = generateInitialGuess(order, t0, tf, x0, xf)
    n = order+1;
    A = zeros(6,n);
    a0 = [];
    for k = 1:3
        for i = 1:n
            A(1,i) = t0^(n-i);
            A(2,i) = tf^(n-i);
            if (n-i-1)>=0
                A(3,i) = (n-i)*t0^(n-i-1);
                A(4,i) = (n-i)*tf^(n-i-2);
            end
            if (n-i-2)>=0
                A(5,i) = (n-i-1)*(n-i)*t0^(n-i-2);
                A(6,i) = (n-i-1)*(n-i)*tf^(n-i-2);
            end
        end
        b = [x0(k); xf(k); 0; 0; 0; 0];
        a0 = [a0; pinv(A)*b];
    end
    