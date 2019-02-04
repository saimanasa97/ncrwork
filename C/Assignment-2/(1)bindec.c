#include<stdio.h>

void bintodec(  int n ){
int d=0,r,base=1;
while(n>0){
    r=n%10;
    d+= r*base;
    n =n/10;
    base = base*2;
}
printf("%d \n",d);
}

void dectobin(int n){
int b=0,base=1;
while(n!=0){
    b += (n%2)*base;
    n=n/2;
    base*=10;
}
printf("%d \n",b);
}

int main(){
int b;
int d;
printf("enter binary number : ");
scanf("%d",&b);
printf("Binary to decimal\n");
bintodec(b);
fflush(stdin);
printf("enter decimal number : ");
scanf("%d",&d);
printf("Decimal to binary\n");
dectobin(d);
return 0;
}
