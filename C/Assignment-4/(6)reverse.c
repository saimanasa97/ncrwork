#include<stdio.h>
void rev(char *s,int i,int j){
int temp;
if(i>=j)
return ;
temp=s[i];
s[i]=s[j];
s[j]=temp;
rev(s,i+1,j-1);
}
int main()
{
char s[100];
scanf("%[^\n]s",s);
rev(s,0,strlen(s)-1);
printf("%s",s);
return 0;
}
