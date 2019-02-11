#include<stdio.h>
#include<string.h>
int main(){
int i=0,j,count=0;
char *s[] = { "we will teach you how to " , "Move a mountain " , "Level a building " , "Erase the past ", "Make a million"};
for(i=0;i<5;i++)
{
for(j=0;j<strlen(s[i]);j++)
	{if(s[i][j] == 'e' || s[i][j] == 'E')
		{++count;}
	}
}
printf("%d",count);
return 0;
}
