function cubic_spline
  x = 2*pi*rand (1, 200);
  y = sin (x) + sin (2 * x) + 0.2 * randn (size (x));
  pp = splinefit (x, y, 10);
  xx = linspace (0, 2 * pi, 400);
  yy = ppval (pp, xx);
  plot (x, y, ".", xx, yy)
  axis tight
  ylim auto
  title("Experiment 4")
  xlabel('X value')
  ylabel('Y value')
  title('Cubic Spline Interpolation')
  legend("Data", "Interpolated Spline")
 endfunction