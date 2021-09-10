X=[-100:1:100];
a=100*rand;
b=300*rand + 420;
c=200*rand +360;
d=300*rand;
y=a*X.^3+b*X.^2-c*X-d+500*rand(size(X));
coefs=polyfit(X,y,3);
Y=coefs(1)*X.^3+coefs(2)*X.^2+coefs(3)*X+coefs(4);
Rsq=1-sum((y-Y).^2)/sum((y-mean(y)).^2)

scatter(X,y,'.')
hold on
plot(X,Y)
xlabel('X value')
ylabel('Y value')
title('Cubic Regression')
