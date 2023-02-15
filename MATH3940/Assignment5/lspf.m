function [A] = lspf(X, Y, m)

sumxmy = 0;
sumx2m = 0;
for i = 1:length(X)
  sumxmy += (X(i)^m) * Y(i);
  sumx2m += X(i)^(2*m);
end
A = sumxmy / sumx2m;
