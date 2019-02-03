#include<stdio.h>

int main(){

int n,sumOfCubes=0,r,x;
scanf("%d",&x);
n=x;
while(n>0){
r=n%10;
sumOfCubes+= r*r*r;
n=n/10;
}
if(sumOfCubes == x)
printf("%d is an Armstrong number",x);
else
printf("%d is not an Armstrong number",x);
return 0;

}
