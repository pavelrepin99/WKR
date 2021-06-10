
a = 0;
tic=[];
for i=0:609
    a=a+0.01;
    tic=[tic;a];
end
plot(tic,A)
hold on
plot(tic,B)
