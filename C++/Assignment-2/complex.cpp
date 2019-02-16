#include<iostream>
using namespace std;

class Complex {
	float real;
	float imag;
public:

	Complex(float r=0, float i=0) {
		real = r;
		imag = i;
	}
	void display();
	Complex operator+(Complex const &c);
	Complex operator-(Complex const &c);
	Complex operator-();
	Complex operator++();
	Complex operator++(int x);
	Complex operator,(Complex c);
	Complex* operator->();
	Complex operator=(Complex &c);
	friend istream & operator>> (istream &, Complex &c);
	friend ostream & operator<<(ostream &, Complex &c);
	~Complex(){
	}
};
void Complex::display(){
cout<<real<<"+"<<imag<<"i\n";
}
Complex Complex::operator+(Complex const &c) {
	Complex res;
	res.real = real + c.real;
	res.imag = imag + c.imag;
	return res;
}
Complex Complex::operator-(Complex const &c) {
	Complex c1;
	c1.real = real - c.real;
	c1.imag = imag - c.imag;
	return c1;
}
Complex Complex::operator-() {
	Complex c1;
	c1.real = -real;
	c1.imag = -imag;
	return c1;
}
Complex Complex::operator++() {
	Complex c1;
	c1.real = ++real ;
	c1.imag = ++imag;
	return c1;
}
Complex Complex::operator++(int x) {
	Complex c1;
	c1.real = real++;
	c1.imag = imag++;
	return c1;
}
Complex Complex::operator,(Complex c) {
	return *this;
}
Complex* Complex::operator->() {
	return this;
}
Complex Complex::operator=(Complex &c){
    real=c.real;
    imag=c.imag;
    return *this;
}
istream & operator>> (istream &in, Complex &c) {
	cout << "enter real and imaginary parts of a Complex number\n";
	in >> c.real >> c.imag;
	return in;
}
ostream & operator<< (ostream &out, Complex &c) {
	out << "("<<c.real<<","<<c.imag<<")\n";
	return out;
}
int main() {
	Complex c1,c2;
	cin>>c1;
	cin>>c2;
    Complex c3=c1+c2;
	cout<<c3;
    Complex c4=c1 - c2;
    cout<<c4;
	Complex c5=-c1;
	cout << c5;
    Complex c6=++c1;
    cout<<c6<<c1;
    Complex c7=c2++;
    cout<<c7<<c2;
    c3=c1,c2;
    cout<<c3;
    c1->display();

	return 0;
}
