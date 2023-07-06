clear; clc;

%-------------- Parâmetros --------------%
g = 9.81;
l = 9.25*10^(-2);
m = 32*10^(-3);
J = 3650.667*10^(-6);
b = 0.1;
M = 241.3*10^(-3);

q = (M+m)*(J+m*l^2)-(m*l)^2;

%-------------- FT do pêndulo --------------%
s  = tf('s');

G_pend = (m*l*s/q)/(s^3 + (b*(J + m*l^2))*s^2/q - ((M + m)*m*g*l)*s/q - b*m*g*l/q)
polos = pole(G_pend);
%rlocus(G_pend);

%-------------- Requisitos --------------%
taco = 0.5;
PSS = 0.1;

Re = 4/taco;
Phi = atand(-pi/log(PSS));
Im = Re*tand(Phi);

%-------------- Projeto do controlador --------------%
phi_PP1 = 90 + atand((Re - abs(polos(2)))/Im);
phi_PP2 = 90 + atand((Re + abs(polos(1)))/Im);
phi_PP3 = 90 + atand((Re - abs(polos(3)))/Im);

Trans_Sol = phi_PP1 + phi_PP2 + phi_PP3 - 360;

a = 7;
%b_teste = 0:0.001:30;
%fun = atand((Re - a)./(Im - b_teste)) + atand((Re - a)./(Im + b_teste));
%plot(b_teste, fun);
%xlabel('b');
%ylabel('fun');

% Controlador PID
b = 6.18;
C = ((s + a + b*1i)*(s + a - b*1i))/s;

Gmf = C*G_pend;
k = 10.7;
%rlocus(Gmf);

%-------------- Discretização --------------%
Ts = 0.005;

Gmfz = c2d(Gmf, Ts, 'tustin');

%rlocus(Gmfz);

%-------------- Ganhos --------------%
Kp = k*2*a;
Ki = k*(a^2 + b^2);
Kd = k;

Kp_z = Kp;
Ki_z = (Ki*Ts)/2;
Kd_z = Kd/Ts;





