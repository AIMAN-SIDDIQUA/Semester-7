X = [-70:70];

b = 5*rand;
c = 8*rand;

y = X.^3 + b*X.^2 + c*X + 100000*rand(size(X));

coefs1 = polyfit(X, y, 1);
Y1 = coefs1(1)*X+coefs1(2);

coefs2 = polyfit(X,y,2);
Y2 = coefs2(1)*X.^2 + coefs2(2)*X + coefs2(3);

coefs3 = polyfit(X,y,3);
Y3 = coefs3(1)*X.^3 + coefs3(2)*X.^2 + coefs3(3)*X + coefs3(4);

scatter(X,y,'.');
hold on
plot(X,Y1,"g", X,Y2,"r:",X,Y3,"k--");

xlabel('X value')
ylabel('Y value')
title('Curve Fitting')
legend('Data', 'Linear Curve', 'Quadratic Curve', 'Cubic Curve')
