function [dydt] = sir(t,y)
  a = 0.01;
  b = 0.1;
  dydt(1) = -a*y(1)*y(2);
  dydt(2) = a*y(1)*y(2)-b*y(2);
  dydt(3) = b*y(2);
  
  dydt = [dydt(1) dydt(2) dydt(3)]';
end
 
y0 = [99 1 0];
a = 0.01;
b = 0.1;
 
[t,y] = ode45('Sir',[0,50],y0);
plot(t,y(:,1),t,y(:,2),t,y(:,3))

xlabel('time');
ylabel('values');
legend('susceptible','infected','recovered');


