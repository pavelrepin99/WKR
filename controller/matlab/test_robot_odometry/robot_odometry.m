clc
clear

e = 1;
i = 1;
j = 2;
z = 3;
y = 1;
x = 1; 
n = 1;
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
for u=1:3
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
    B(1,y) = A(i,1);
    C(1,x) = A(j,1);
    D(1,n) = A(z,1);
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

subplot(3,1,1),plot(V,B), xlabel('t'),ylabel('dist') %dist
subplot(3,1,2),plot(V,C), xlabel('t'), ylabel('speed') %speed
hold on 
plot(V,D,'--')



    