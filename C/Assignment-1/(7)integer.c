#include<stdio.h>
#include<limits.h>

int main(){
    int c=0;
    int min=INT_MAX;
    int max=INT_MIN;
while(1){
    int n;
    scanf("%d",&n);
    if(n<=0)
        break;
    else{
        c++;
        if(n<=min)
            min=n;
        if(n>=max)
            max=n;
    }
}
printf("Count of integers = %d\n",c);
printf("Maximum = %d\n",max);
printf("Minimum = %d",min);
return 0;
}
