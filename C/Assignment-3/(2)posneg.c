#include<stdio.h>
int main(){
int n,i,j=0,t;
int a[100];
scanf("%d",&n);
for(i=0;i<n;i++)
scanf("%d",&a[i]);
for(i=0;i<n;i++){
if(a[i]<0){
if(i!=j){
t=a[i];
a[i]=a[j];
a[j]=t;
}
j++;
}
}
for(i=0;i<n;i++)
printf("%d ",a[i]);
return 0;
}
