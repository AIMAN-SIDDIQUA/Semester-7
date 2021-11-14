syms a(t) b(t) c(t)
A = [6 4 4; -7 -2 -1; 7 4 3];

x = [a; b; c];
odes = diff(x) == A*x
[aSol(t),bSol(t),cSol(t)] = dsolve(odes);
aSol(t) = simplify(aSol(t))
bSol(t) = simplify(bSol(t))
cSol(t) = simplify(cSol(t))
C = x(0) == [3;-6; 4];
[aSol(t),bSol(t),cSol(t)] = dsolve(odes,C)