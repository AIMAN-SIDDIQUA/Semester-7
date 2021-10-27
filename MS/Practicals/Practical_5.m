function meshGrid
  x1 = 1:1:20
  x2 = 1:1:20
  a = 100*rand
  b = 100*rand
  c = 100*rand
  y = a*x1+b*x2+c

  X = [ones(size(x1));x1;x2]

  size(X)
  size(y)
  b = regress(y',X')
  scatter3(x1,x2,y,'filled')
  hold on 

  [X1FIT,X2FIT] = meshgrid(x1,x2);
  YFIT = b(1) + b(2)*X1FIT + b(3)*X2FIT;
  mesh(X1FIT,X2FIT,YFIT)
  xlabel('x1')
  ylabel('x2')
  zlabel('y')
  view(50,100)
endfunction
