#include<stdio.h>
#include<math.h>
float si(int n,float t,float r){
    return (n*t*r*0.01);
}
float ci(int n,float t,float r){
 return n*pow((1+r*0.01),t);
 }
int main(){
int n=500000;
float r,s,c;
scanf("%f",&r);
s=si(n,1.0,r); c=ci(n,1.0,r);
printf(" Annually \n SI : %f\n CI : %f\n Total for 10years:%f\n ",s,c,s+c);
s=si(n,0.5,r);c=ci(n,0.5,r);
printf(" Semi-Annually \n SI : %f\n CI : %f\n Total for 10years:%f\n ",s,c,s+c);
s=si(n,0.25,r); c=ci(n,0.25,r);
printf(" Quarterly \n SI : %f\n CI : %f\n Total for 10years:%f\n ",s,c,s+c);
s=si(n,0.0833,r);c=ci(n,0.0833,r);
printf(" Monthly \n SI : %f\n CI : %f\n Total for 10years:%f\n ",s,c,s+c);
s=si(n,0.00273,r);c=ci(n,0.00273,r);
printf(" Daily \n SI : %f\n CI : %f\n Total for 10years:%f\n ",s,c,s+c);
return 0;
}
