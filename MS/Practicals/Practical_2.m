X = [0:1:100];
a = 300*rand;
b = 200*rand;
c = 500*rand;
y = a*X.^2 + b*X + c + 500*rand(size(X));
coef = polyfit(X,y,2);
Y = coef(1)*X.^2 + coef(2)*X + coef(3);
Rsq = 1-sum((y-Y).^2/sum((y-mean(Y)).^2))

scatter(X,y,'.')
hold on
plot(X,Y)
xlabel('X Value')
ylabel('Y Value')
title('Quadratic Regression')
