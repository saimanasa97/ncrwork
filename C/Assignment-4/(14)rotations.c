#include<stdio.h>
int main(){
char s[50];
int i,j;
scanf("%s",s);
for(i=0;i<strlen(s);i++)
{
	for(j=i;j<strlen(s);j++)
	printf("%c",s[j]);
	for(j=0;j<i;j++)
	printf("%c",s[j]);
printf("\n");
}
return 0;
}
