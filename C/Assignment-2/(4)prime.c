#include<stdio.h>
#include<math.h>
void findPrimes(int l,int r){
    int i,flag;
if(l==0)
    l++;
while(l<=r){
    flag=0;
    for(i=2;i<=sqrt(l);i++){
        if(l%i==0)
        {
            flag=1;
            break;
        }
    }
    if(flag==0)
        printf("%d ",l);
    l++;
}
}
int main(){
int l,r;
scanf("%d%d",&l,&r);
findPrimes(l,r);
return 0;
}
