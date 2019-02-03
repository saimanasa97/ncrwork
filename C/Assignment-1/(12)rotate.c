#include<stdio.h>
#include<math.h>

int rotate(int n,int ro){
    int temp=n,count=0,i,r;
    while(n>0){
        count++;
        n=n/10;
    }
    for(i=0;i<(ro%count);i++){
        r=temp%10;
        temp=temp/10;
        r*= (int)pow(10,count-1) ;
        temp+= r;
    }
    return temp;
}

int main(){
    int n,r;
    scanf("%d",&n);
    scanf("%d",&r);
    printf("%d",rotate(n,r));
return 0;
}
