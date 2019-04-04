#include<stdio.h>
int main(){
//sample test program
int *p,*q,a,b,_ct;
char a[10];
p=(int*)malloc(sizeof(int)*4);
q=(int*)calloc(6);
free(p);
char *b = "hello";
printf("%d %d",*p,sum(a,b));
scanf("%d", &a, &b);
gets(a);
return 0;
}
int sum(int number1, int n2)
{
	return number1 + n2;
}