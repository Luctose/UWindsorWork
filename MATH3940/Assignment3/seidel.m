function [P,iter] = seidel(G,P,delta, max1)
%Input - G is the nonlinear system saved in the M-file G.m
%- P is the initial guess at the solution
%- delta is the error bound
%- max1 is the number of iterations
%Output - P is the Seidel approximation to the solution
%- iter is the number of iterations required
N=length(P);
for k=1:max1
  X=P;
  %X is the kth approximation to the solution
  for j=1:N
    A=feval(’G’,X);
    %Update the terms of X as they are calculated
    X(j)=A(j);
  end
  err=abs(norm(X-P));
  relerr=err/(norm(X)+eps);
  P=X;
  iter=k;
  if(err<delta)|(relerr<delta)
    break
  end
end
