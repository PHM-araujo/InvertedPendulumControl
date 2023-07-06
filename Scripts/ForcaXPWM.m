clear; clc;
massa = 0.24130; % Massa em Kg

%-------------- Curva não linear --------------%

pwm = [90 95 100 105 110 115 120 125 130 135 140 145 150 155 160 165 170 175 180 185 190 195 200 205 210 215 220 225 230 235 240 245 250 255];

% Acelerações em m/s
aceleracoes = [0.10209 0.15092 0.18578 0.20554 0.23541 0.25192 0.27479 0.29449 0.31680 0.34175 0.36450 0.37891 0.39792 0.40998 0.44231 0.46465 0.48936 0.52154 0.55024 0.53488 0.54245 0.54374 0.54502 0.54118 0.53488 0.54374 0.54893 0.54374 0.54374 0.55156 0.53488 0.53488 0.53364 0.54502];
forca = aceleracoes*massa;

%plot(pwm, forca);
%title  ('Força X PWM')
%xlabel ('PWM')
%ylabel ('Força no carro (N)')

%-------------- Curva linear --------------%
pwm_linear = [90, 255];
aceleracoes_linear = [0.10209 0.54502];
forca_linear = aceleracoes_linear * massa;

plot(pwm_linear, forca_linear);
title  ('Força X PWM (Linear)')
xlabel ('PWM')
ylabel ('Força no carro (N)')

