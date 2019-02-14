#include<iostream>
using namespace std;
class Employee{
int empno;
char name[20];
int sal;
public:
    Employee(){
        empno=0;
        sal=5000;
    }
    ~Employee(){
    }
    void display(){
            cout<<"employee no: "<<empno<<endl;
            cout<<"name: "<<name<<endl;
            cout<<"salary: "<<sal<<endl;
    }
    friend istream & operator>>(istream &, Employee &);
};
istream & operator>>(istream &in, Employee &e){
    cout<<"enter employee no, name, salary\n";
    in>>e.empno>>e.name>>e.sal;
    return in;
}
int main(){
    Employee e[5];
    for(int i=0;i<5;i++)
        cin>>e[i];
    for(int i=0;i<5;i++)
    e[i].display();
return 0;
}
