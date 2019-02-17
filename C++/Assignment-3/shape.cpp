#include<iostream>
#include<math.h>
using namespace std;
class Shape{

protected:
    int dim1,dim2,dim3;
public:
    virtual void display_area()=0;
};
class Triangle : public Shape{
public:
    Triangle(int d1=0,int d2=0,int d3=0){
        dim1=d1;
        dim2=d2;
        dim3=d3;
    }
    void display_area(){
    float s = (dim1+dim2+dim3)/2;
    s= sqrt(s*(s-dim1)*(s-dim2)*(s-dim3));
    cout<<"Area of triangle = "<<s<<endl;
    }
};
class Rectangle : public Shape{
public:
    Rectangle(int d1=0,int d2=0){
        dim1=d1;
        dim2=d2;
    }
    void display_area(){

    cout<<"Area of rectangle = "<<dim1 * dim2<<endl;
    }
};
class Square : public Shape{
public:
    Square(int d1=0){
    dim1=d1;
    }
    void display_area(){

    cout<<"Area of square = "<<dim1 * dim1<<endl;
    }
};
int main(){
    Shape *sh;
    Triangle t(3,4,5);
    sh= &t;
    sh->display_area();
    Rectangle r(3,4);
    sh= &r;
    sh->display_area();
    Square s(4);
    sh= &s;
    sh->display_area();
return 0;
}
