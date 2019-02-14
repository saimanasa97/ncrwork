#include<iostream>
using namespace std;

class polar{
int r;
int a;
public:
    static int count;
    polar(){
    r=10;
    a=30;
    count++;
    cout<<"Constructor "<<count<<endl;
    }
    ~polar(){
    count--;
    cout<<"Destructor "<<count<<endl;
    }
    void display(){
    polar p;
    cout<<p.r<<" "<<p.a<<endl;
    }
};
 int polar::count=0;
int main(){
polar p1,p2;
p2.display();
return 0;
}

