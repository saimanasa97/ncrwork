#include<iostream>
using namespace std;
class Demo_public{
public:
    // these can be accessed everywhere
    // within the same class, derived class and outside this class
    int n,m;

    int add(){
    return n+m; //accessing in same class
    }
};
class child : public Demo_public{
public:
    child(int a=10, int b=5){
        n=a;
        m=b;
    }
void display(){
cout<<n<<" "<<m<<endl; //accessing in derived class
}
};
int main(){
    child c(20,30);
    cout<<c.add()<<endl;
    c.display();
    cout<<c.n<<" "<<c.m<<endl; //accessing outside the class
    return 0;
}
