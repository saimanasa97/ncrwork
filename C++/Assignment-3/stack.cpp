#include<iostream>
using namespace std;
#define SIZE 20

class Complex {
	float real;
	float imag;
public:

	Complex(float r=0, float i=0) {
		real = r;
		imag = i;
	}
};
template <class T>
class Stack{
T s[SIZE];
int top;
public:
    Stack(){
    top=-1;
    }
    void push(T ele){
        if(top == SIZE-1)
            throw std::out_of_range("overflow");
        s[++top]=ele;
    }

    T pop(){
    if(this->isempty()){
        throw std::out_of_range("underflow");
    }
    T ele = s[top];
    top--;
    return ele;
    }
    T top_ele(){
    if(this->isempty())
        throw std::out_of_range("underflow");
    return s[top];
    }
    bool isempty(){
    return (top==-1)? true : false;
    }
    void display(){
    for(int i=0;i<=top;i++)
        cout<<s[i]<<" ";
    cout<<endl;
    }

};
int main(){
    Stack <int> stk;
    try{
    stk.push(1);
    stk.push(2);
    stk.push(3);
    stk.display();
    cout<<stk.pop()<<endl;
    cout<<stk.top_ele()<<endl;

    Stack <float> f;
    f.push(1.2);
    f.push(9.78);
    f.display();
    cout<<f.pop()<<endl;
    f.push(3.666);
    f.display();
    }
    catch(char *e){
        cout<<e;
    }

    Stack <char *> str;
    str.push("abc");
    str.push("def");
    str.display();
    cout<<str.pop()<<endl;
    cout<<str.top_ele();

//    Stack <Complex> c;
//    Complex a(2,3), b(1,2);
//    c.push(a);
//    c.push(b);
//    //cout<<c.top_ele()<<endl;
//    //cout<<c.pop()<<endl;
//    //c.display();
return 0;
}
