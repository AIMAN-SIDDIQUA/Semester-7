n = 10000;
x = rand(n,1);
y = rand(n,1);

x = x-0.5;
y = y-0.5;
r = x.^2 + y.^2;
m = 0;

hold on
for i=1:n
  if r(i)<=0.25
    m = m+1
    plot(x(i),y(i),'b.')
  else
    plot(x(i),y(i),'r.')
  end
end

pi = m/(0.25*n)


