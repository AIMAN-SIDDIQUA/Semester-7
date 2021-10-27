f = @(t,y) [(1-.4*y(2))*y(1); (-1+.4*y(1))*y(2)];
[ts,ys] = ode45(f,[0,20],[8;4]);
figure(1);
plot(ts,ys)
legend('Deer','Lion')
xlabel('Time t')
title('Solution to Predator-Prey Differential Equation')
figure(2);
opt = odeset('RelTol',1e-10,'AbsTol',1e-10);
[ts,ys] = ode45(f,[0,20],[8;4],opt);
plot(ys(:,1),ys(:,2)); 
hold on
xlabel('Deet') 
ylabel('Lion')
title('Phase Plane Plot')