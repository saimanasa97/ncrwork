#include<stdio.h>
int main(){
int n,i,a[100],req,sum=0,j=0;
printf("enter size of array: ");
scanf("%d",&n);
printf("enter array elements: \n");
for(i=0;i<n;i++)
    scanf("%d",&a[i]);
printf("enter required sum: ");
scanf("%d",&req);
i=0;
for(j=0;(j<=n && sum!=req);)
{
    if(sum>req){
       sum -= a[i];
       i++;
    }
    else {
      sum+=a[j];
      j++;
    }
}
if(sum==req)
printf("Indices are : %d,%d",i,j-1);
else
printf("sum not found");
return 0;
}
