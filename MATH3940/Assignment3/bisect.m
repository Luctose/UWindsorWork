function [c,err,yc,k]=bisect(f,a,b,delta,maxl)
%Input - f is the function input as a string ’f’
%- a and b are the left and right endpoints
%- delta is the tolerance
%Output - c is the zero
%- yc=f(c)
%- err is the error estimate for c
ya=feval(f,a);
yb=feval(f,b);
if ya*yb>0
  return
  end
max1=1+round((log(b-a)-log(delta))/log(2));
for k=1:max1
  c=(a+b)/2;
  yc=feval(f,c);
  if yc==0
    a=c;
    b=c;
  elseif yb*yc>0
    b=c;
    yb=yc;
  else
    a=c;
    ya=yc;
  end
  if b-a < delta, break,end
  end
c=(a+b)/2;
err=abs(b-a);
yc=feval(f,c);

