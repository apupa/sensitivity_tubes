function da = my_polyder(a)
    n = length(a);
    da = a;
    da = da(1:end-1);
%     da = zeros(n-1,1);
    for i = 1:length(a)-1
        da(i) = a(i)*(n-i);
    end
end