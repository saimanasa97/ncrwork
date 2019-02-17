#include<iostream>
using namespace std;
class Demo_protected{

protected:
    // these can be accessed only within the same class, derived class
    // cannot be accessed in outside classes
    int n,m;
public:
    //this can be accessed anywhere
    int add(){
    return n+m; //accessing in same class
    }
};
class child : public Demo_protected{
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
    //accessing outside the class is not possible. This will raise error
    //cout<<c.n<<" "<<c.m<<endl;
    return 0;
}
