X = [0:1:100];
m = 200*rand;
c = 500*rand;
y = m*X+c+200*rand(size(X));
coef = polyfit(X,y,1);
Y = coef(1)*X + coef(2);
Rsq = 1-sum((y-Y).^2/sum((y-mean(Y)).^2))

scatter(X,y,'.')
hold on
plot(X,Y)
xlabel('X Value')
ylabel('Y Value')
title('Linear Regression')
