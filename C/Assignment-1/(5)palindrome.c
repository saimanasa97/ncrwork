#include<stdio.h>

int main(){
int n,rev=0,temp;
scanf("%d",&n);
temp=n;
while(n>0){
rev= (rev*10)+n%10;
n=n/10;
}
if(rev==temp)
printf("%d is a palindrome ",temp);
else
printf("%d is not a palindrome ",temp);
return 0;
}
