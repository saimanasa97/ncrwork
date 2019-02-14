#include<iostream>
using namespace std;
void swap_value(int a, int b){
a=a+b;
b=a-b;
a=a-b;
}
void swap_reference(int &a, int &b){
a=a+b;
b=a-b;
a=a-b;
}
int main(){
int m,n,c;
cin>>m>>n;
cout<<"enter choice\n1.Swap by value\n2.Swap by reference\n";
cin>>c;
if(c==1)
    swap_value(m,n);
else
    swap_reference(m,n);
cout<<m<<" "<<n;
return 0;
}
