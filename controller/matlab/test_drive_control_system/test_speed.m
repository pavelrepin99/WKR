clc 
clear 

time = 0;
e = 1;
p = 1; 
A = [];     
B = [];
C = [];
V = [];
E = [];
T = [];

serial_com = serial('COM4');
set(serial_com, 'BaudRate', 115200); 
serial_com.InputBufferSize = 65535;
fopen(serial_com);
flag = 's';
fwrite(serial_com, flag, 'uint8'); 
disp(1);
time=0;
task = 'x'; %задание скорости 10см/с
fwrite(serial_com, task, 'uint8'); 
t1 = clock;
while time < 3
    A = fread(serial_com,[10,1],'float');
    E = [E;A];
    H = ones([10,1])*(-15);
    B = [B;H];
    t2 = clock;
    time = t2(1,6) - t1(1,6);
end;
disp(3);
time = 0;
task = ' '; %задание скорости 0см/с
fwrite(serial_com, task, 'uint8'); 
t1 = clock;
while time < 3
    A = fread(serial_com,[10,1],'float');
    E = [E;A];
    H = ones([10,1])*0;
    B = [B;H];
    t2 = clock;
    time = t2(1,6) - t1(1,6);
end;
disp(4);
time = 0;
task = 'c'; %задание скорости 0см/с
fwrite(serial_com, task, 'uint8'); 
t1 = clock;
while time < 3
    A = fread(serial_com,[10,1],'float');
    E = [E;A];
    H = ones([10,1])*(15);
    B = [B;H];
    t2 = clock;
    time = t2(1,6) - t1(1,6);
end;
disp(5);
time = 0;
task = ' '; %задание скорости 0см/с
fwrite(serial_com, task, 'uint8'); 
t1 = clock;
while time < 3
    A = fread(serial_com,[10,1],'float');
    E = [E;A];
    H = ones([10,1])*0;
    B = [B;H];
    t2 = clock;
    time = t2(1,6) - t1(1,6);
end;

A = E;
u = 0;
fclose(serial_com);
disp(6)
q = length(A(:,1));
for u = 1:q
    V(1,e) = u*0.01;
    e = e+1;
end
k = length(B(:,1));
for u = 1:k
    T(1,p) = u *0.01;
    p = p +1;
end

plot(T,B), xlabel('t'),ylabel('input speed') %input
hold on 
plot(V,A), xlabel('t'), ylabel('output speed') %output
grid on


