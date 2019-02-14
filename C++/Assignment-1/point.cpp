#include<iostream>
#include<math.h>
using namespace std;
class Points{
int x;
int y;
public:
    Points(int x,int y){
    this->x=x;
    this->y=y;
    }
    friend float dist(Points, Points);
};
float dist(Points p1, Points p2){
    int a,b;
    a=p1.x - p2.x;
    b=p1.y - p2.y;
return sqrt(a*a + b*b);
}
int main(){
int x1,x2,y1,y2;
cout<<"Enter x1,y1,x2,y2\n";
cin>>x1>>y1>>x2>>y2;
Points p1(x1,y1), p2(x2,y2);
cout<<dist(p1,p2);
return 0;
}
