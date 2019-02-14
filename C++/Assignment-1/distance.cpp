#include<iostream>
using namespace std;
class Distance2;
class Distance1 {
 float m;
public:
 Distance1(int a) {
  m = a;
 }
 friend  void add(Distance1 &,Distance2 &,int choice);
};
class Distance2 {
 float feet;
public:
 Distance2(int a) {
  feet = a;
 }
 friend void add(Distance1 &, Distance2 &,int choice);
};
void add(Distance1 &d1, Distance2 &d2,int choice) {
    float x;
 if (choice == 1) {
d1.m += (d2.feet * 0.3048);
cout<<"Distance in meters: "<<d1.m<<endl;
 }
 else {
d2.feet += (d1.m * 3.280399);
cout<<"Distance in feet: "<<d2.feet<<endl;
 }
}
int main() {
 float m, f,c;
 cout << "enter 2 numbers(m & ft)\n";
 cin >> m >>  f ;
 Distance1 d1(m);
 Distance2 d2(f);
 cout << "Enter your choice of measurement\n1.meters2.Feet\n";
 cin >> c;
 add(d1, d2,c);
 return 0;
}
