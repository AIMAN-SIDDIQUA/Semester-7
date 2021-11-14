beta = 0.0015
gamma = 0.008
N_t = 7200

t = linspace(0, 720, N_t+1);
S = zeros(N_t+1, 1);
I = zeros(N_t+1, 1);
R = zeros(N_t+1, 1);

S(1) = 50;
I(1) = 1;
R(1) = 0;

for n = 1:N_t
   S(n+1) = S(n) - 0.1*beta*S(n)*I(n); 
   I(n+1) = I(n) + 0.1*beta*S(n)*I(n) - 0.1*gamma*I(n);
   R(n+1) = R(n) + 0.1*gamma*I(n);
end

plot(t, S, t, I, t, R);
legend('Susceptible', 'Infected', 'Removed');
xlabel('hours');
title('Solution to SIR Model')

