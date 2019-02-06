#include<stdio.h>
int main(){
int x[8]= {10,20,30,40,50,60,70,80};
printf("%d\n%d\n%d\n%d\n%d\n",x,(x+2),*x,(*x+2),*(x+2));
return 0;
}
