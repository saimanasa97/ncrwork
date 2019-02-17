#include<iostream>
using namespace std;
class Demo_private{

private:
    // these can be accessed only within the same class
    // cannot be accessed in derived clasees & outside classes
    int n,m;
protected:
    //this can be accessed by the dervied class but any outside class
    int pro1;

public:
    //this can be accessed anywhere
    void set_data(int x,int y){
        n=x;
        m=y; //accessing in same class
    }
    void display(){
    cout<<n<<" "<<m<<endl; //accessing in the same class
    }
};
class child : public Demo_private{
public:
    child(int a=10, int b=5){
    //this is not possible as n and m can be used only within the Demo_private class
    /*
        n=a;
        m=b;
    */
    //the private members can be accessed using a member function of the base class which is either public or protected
    set_data(5,6);
    //pro1 can be accessed here
        pro1=40;
    }

};
int main(){
    child c(20,30);
    c.display();
    //accessing outside the class is not possible. This will raise error
    //cout<<c.n<<" "<<c.m<<endl;
    return 0;
}
