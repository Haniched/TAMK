%% E-kirjaimen piiros- ja rotaatioskripti
% Tietotekniikan matematiikka, syksy 2024
% Ref: TKjP ss. 181-183

% E-kirjaimen kärkipisteiden mallinnus
x = [1, 1, 1, 2, 2, 2; 1, 2, 3, 1, 2, 3];
t = pi / 4; % Kiertokulma radiaaneina
u = [0; -1]; % Piste, jonka ympäri kierretään
u = repmat(u, 1, size(x, 2));

% 2D-Rotaatiomatriisi
R = [cos(t), -sin(t); sin(t), cos(t)];

% Rotaatio pisteen u ympäri
y = u + R * (x - u);

% Kuvan piirto:
%--------------------
% piirretään kärkipisteet
% alkuperäinen kuvio punaisella
% ja uusi kuvio sinisellä
hold all
plot(x(1, :), x(2, :), 'r.') % Alkup. kuvion kärkipisteet
plot(y(1, :), y(2, :), 'b.') % Kierretyn kuvion kärkipisteet
plot(u(1, 1), u(2, 1), 'g.') % Kiertopiste
% pisteitä yhdistävät janat,

%% Kirjaimen viivojen mallinnusperiaate
% Ensin E:n vasen pystyviiva
% Toisena E:n alaviiva
% Kolmantena E:n keskiviiva
% Neljäntenä E:n yläviiva

% alkuperäinen kuvio:
plot([x(1, 1), x(1, 3)], [x(2, 1), x(2, 3)], 'r')
plot([x(1, 1), x(1, 4)], [x(2, 1), x(2, 4)], 'r')
plot([x(1, 2), x(1, 5)], [x(2, 2), x(2, 5)], 'r')
plot([x(1, 3), x(1, 6)], [x(2, 3), x(2, 6)], 'r')

% uusi (kierretty) kuvio:
plot([y(1, 1), y(1, 3)], [y(2, 1), y(2, 3)], 'b')
plot([y(1, 1), y(1, 4)], [y(2, 1), y(2, 4)], 'b')
plot([y(1, 2), y(1, 5)], [y(2, 2), y(2, 5)], 'b')
plot([y(1, 3), y(1, 6)], [y(2, 3), y(2, 6)], 'b')
hold off

axis([-2 2 0 4]) % Piirtokoordinaatisto hyvään kohtaan
axis equal % Akselien skaalat samoiksi 
grid % Ruudukko tilanteen hahmottamisen helpottamiseksi
