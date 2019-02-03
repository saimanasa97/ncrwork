#include<stdio.h>
int main(){
int sal;
float hra,da,gross;
scanf("%d",&sal);
if(sal>=1 && sal<=4000)
{
    hra=0.10;
    da=0.50;
}
else if(sal>=4001 && sal<=8000){
    hra=0.20;
    da=0.60;
}
else if(sal>=8001 && sal<12000){
    hra=0.25;
    da=0.70;
}
else if(sal>=12000){
    hra=0.30;
    da=0.80;
}
gross = sal*(1+hra+da);
printf("Gross salary = %f",gross);
return 0;
}
