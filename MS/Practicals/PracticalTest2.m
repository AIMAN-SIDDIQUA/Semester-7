[x, y] = meshgrid(-2:0.2:5, -1:0.2:3); 
f = -2.*y.^2 + 2.*x 
scale = sqrt(1+f.^2)    #rescaling the arrows

quiver(x,y,1./scale,f./scale,0.5)
axis tight

xlabel('X value') 
ylabel('Y value') 
title('Direction Field for f(x,y) = -2y^2+2x')