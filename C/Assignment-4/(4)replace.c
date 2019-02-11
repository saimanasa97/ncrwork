#include<stdio.h>
int replace(char *s){
int i,c=0;
for(i=0;i<strlen(s);i++)
if(s[i]==' ')
{
s[i]='-';
c++;
}
return c;
}
int main(){
int n;
char *cat = "The cat sat";
n = replace( cat );
printf("%s\n",cat);
printf("%d",n);
return 0;
}
