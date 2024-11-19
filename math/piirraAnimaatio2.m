% piirraAnimaatio(deltaTheta, T) Piirtää demo-animaation
%
% deltaTheta: vektorin kiertokulma animointiaskeleiden välillä (rad)
% T: animaation kestoaika (s)
function piirraAnimaatio2 (deltaTheta, T)
% HUOM! Koodi pitkälti kommentoimaton (tarkoituksella)

% Rotaatiomatriisi annetulle kiertokulmalle
RdT = [cos(deltaTheta) -sin(deltaTheta);sin(deltaTheta) cos(deltaTheta)];

x0 = [1;0];

t = 0;
dt = 0.1;
theta = 0;

   figure(1)
   clf % Pyyhkii kuvaajan
   %plot(x(1), x(2), 'r.') % Alustuspiirto
   h = gcf; % Kahva piirtoikkunaan
   axis([-2 2 -2 2])
   axis equal
   hold on

    x = x0;

    while t < T
        
        x = RdT*x; % Vektorin rotaatio
        plot(x(1), x(2), 'r.')
        plot([0 x(1)], [0 x(2)], 'b-')
        drawnow

        pause(dt)
        t = t + dt;

    end

end
piirraAnimaatio2(0.5, 5)