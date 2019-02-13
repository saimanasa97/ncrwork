#include<iostream>
using namespace std;
class Inline {
	int a, b;
public:
	Inline(int x, int y) {
		a = x;
		b = y;
	}
	inline int add() {
		return a + b;
	}
	inline int sub()
	{
		return a - b;
	}
	inline int mul() {
		return a*b;
	}
	inline float div() {
		return a / b;
	}
	inline int mod() {
		return a%b;
	}
};
int main() {
	Inline obj(10, 5);
	cout << obj.add() << endl;
	cout << obj.sub() << endl;
	cout << obj.mul() << endl;
	cout << obj.div() << endl;
	cout << obj.mod() << endl;
	return 0;
}