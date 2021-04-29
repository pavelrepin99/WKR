clc
clear

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
task = 'a';
fwrite(serial_com, task, 'uint8'); 
for u=1:2
    A = fread(serial_com,[1000,1],'float');
    E = [E;A];
end
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
    i = i+3;
    j = j+3;
    z = z+3;
    y = y+1;
    x = x+1;
    n = n+1;
    e = e+1;
    if j > q
        break
    end
end

plot(V,B), xlabel('t'),ylabel('input angle') %input
hold on 
plot(V,C), xlabel('t'), ylabel('output angle') %output
