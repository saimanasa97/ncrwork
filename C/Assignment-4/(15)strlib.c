#include <stdio.h>
#include<string.h>
char* reverse(char *p){
int i=0,j=strlen(p)-1;
char c;
while(i<j)
  {
    c=p[i];
    p[i]=p[j];
    p[j]=c;
    i++;
    j--;
  }
  return p;
}
char* copy(char *p, char *q){
    int i=0;
while(p[i] != '\0'){
    q[i]=p[i];
    i++;
}
q[i]='\0';
return q;
}
char* concat(char *p,char *q){
    int i=0,j;
    for(i=strlen(p),j=0;j<strlen(q);i++,j++){
        p[i]=q[j];
    }
    p[i]='\0';
return p;
}
int main()
{
  char name[100];
  char *p,q[50];
  scanf("%s",name);
  p = name;
  printf("Copy of  string: %s\n",copy(p,q));
  printf("Reverse of a string: %s\n",reverse(p));
  printf("enter a string to concatenate : ");
  scanf("%s",q);
  printf("concatenation of 2 strings: %s\n",concat(p,q));

  return 0;
}
