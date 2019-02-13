#include<iostream>
using namespace std;
class Complex {
	float real;
	float imag;
public:
	Complex() {
		real = imag = 0;
	}
	Complex(float val) {
		real = imag = val;
	}
	Complex(float r, float i) {
		real = r;
		imag = i;
	}
	friend void add(Complex &, Complex &);
	friend void multiply(Complex &, Complex &);
};
void add(Complex &c1, Complex &c2) {
	 cout << "Sum : ";
	 cout<<c1.real + c2.real <<"+"<< c1.imag+c2.imag<<"i"<<"\n";
}
void multiply(Complex &c1, Complex &c2) {
	float real = (c1.real * c2.real) - (c1.imag * c2.imag);
	float imag = (c1.real * c2.imag) + (c2.real * c1.imag);
	cout << "Product : ";
	cout << real << "+" << imag << "i" << endl;
}
int main() {
	Complex a(2, 3), b(1,6);
	add(a, b);
	multiply(a, b);
	getchar();
	return 0;
}