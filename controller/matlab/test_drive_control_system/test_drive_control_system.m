clc
clear

e = 1;
p = 1;
A = [];     
B = [];
V = [];
E = [];
T = [];

serial_com = serial('COM7');
set(serial_com, 'BaudRate', 115200); 
serial_com.InputBufferSize = 65536;
fopen(serial_com);
flag = 's';
fwrite(serial_com, flag, 'uint8'); 
disp(1);

task = 'c'; %задание угла 20
fwrite(serial_com, task, 'uint8'); 
t1 = clock;
time = 0;
while time <= 5
    A = fread(serial_com,[10,1],'float');
    E = [E;A];
    H = ones([10,1])*5;
    B = [B;H];
    t2 = clock;
    time = t2(1,6) - t1(1,6);
end;
disp(2);

% task = 'o'; %задание угла 0
% fwrite(serial_com, task, 'uint8'); 
% time = 0;
% t1 = clock;
% while time <= 5
%     A = fread(serial_com,[10,1],'float');
%     E = [E;A];
%     H = ones([10,1])*0;
%     B = [B;H];
%     t2 = clock;
%     time = t2(1,6) - t1(1,6);
% end;
disp(3);
% task = 'v'; %задание угла -20
% fwrite(serial_com, task, 'uint8'); 
% time = 0;
% t1 = clock;
% while time < 5
%     A = fread(serial_com,[10,1],'float');
%     E = [E;A];
%     H = ones([10,1])*(-20);
%     B = [B;H];
%     t2 = clock;
%     time = t2(1,6) - t1(1,6);
% end;

% fwrite(serial_com, task, 'uint8'); 
% for u=1:2
%     A = fread(serial_com,[1000,1],'float');
%     E = [E;A];
% end
A = E;
u = 0;
fclose(serial_com);
disp(4);
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

plot(T,B), xlabel('t'),ylabel('input angle') %input
hold on 
plot(V,A), xlabel('t'), ylabel('output angle') %output
grid on
