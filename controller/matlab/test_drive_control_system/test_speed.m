clc 
clear 

time = 0;
e = 1;
i = 1;
j = 2;
y = 1;
x = 1; 
A = [];     
B = [];
C = [];
V = [];
E = [];

serial_com = serial('COM7');
set(serial_com, 'BaudRate', 115200); 
serial_com.InputBufferSize = 65536;
fopen(serial_com);
flag = 's';
fwrite(serial_com, flag, 'uint8'); 
disp(1);

task = 'c'; %задание скорости 10см/с
fwrite(serial_com, task, 'uint8'); 
t1 = clock;
while time < 5
    A = fread(serial_com,[100,1],'float');
    E = [E;A];
    t2 = clock;
    time = t2(1,6) - t1(1,6);
end;

time = 0;
task = 'o'; %задание скорости 0см/с
fwrite(serial_com, task, 'uint8'); 
t1 = clock;
while time < 2
    A = fread(serial_com,[100,1],'float');
    E = [E;A];
    t2 = clock;
    time = t2(1,6) - t1(1,6);
end;

% time = 0;
% task = 'v'; %задание скорости 0см/с
% fwrite(serial_com, task, 'uint8'); 
% t1 = clock;
% while time < 5
%     A = fread(serial_com,[100,1],'float');
%     E = [E;A];
%     t2 = clock;
%     time = t2(1,6) - t1(1,6);
% end;
% 
% time = 0;
% task = 'o'; %задание скорости 0см/с
% fwrite(serial_com, task, 'uint8'); 
% t1 = clock;
% while time < 3
%     A = fread(serial_com,[100,1],'float');
%     E = [E;A];
%     t2 = clock;
%     time = t2(1,6) - t1(1,6);
% end;

A = E;
u = 0;
disp(2);
fclose(serial_com);
disp(3)
q = length(A(:,1));
for u = 1:q
    B(1,y) = A(i,1); %input
    C(1,x) = A(j,1); %output
    V(1,e) = u*0.01;
    i = i+2;
    j = j+2;
    y = y+1;
    x = x+1;
    e = e+1;
    if j > q
        break
    end
end

plot(V,B), xlabel('t'),ylabel('input angle') %input
hold on 
plot(V,C), xlabel('t'), ylabel('output angle') %output
grid on


