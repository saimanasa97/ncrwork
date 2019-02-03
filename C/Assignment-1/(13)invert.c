#include<stdio.h>
void invertponwards(int n,int p,int b){
unsigned i;
unsigned int x;
int num;
printf("Before Inversion\n");
    for (i = 1 << 31; i > 0; i = i / 2)
        (n & i)? printf("1"): printf("0");
printf("\nAfter Inversion\n");
     num = ((1 << b) - 1) ^ ((1 << (p - 1)) - 1);
    x= n^num;
    for (i = 1 << 31; i > 0; i = i / 2)
        (x & i)? printf("1"): printf("0");

}
int main(){
int n,p,b;
scanf("%d%d%d",&n,&p,&b);
invertponwards (n, p, b);
return 0;
}
