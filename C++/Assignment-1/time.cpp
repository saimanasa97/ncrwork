#include<iostream>
#include<conio.h>
using namespace std;
class Time {
	int hour;
	int min;
	int sec;

public:
	Time() {
		hour = min = sec = 0;
	}
	Time(int h, int m, int s) {
		hour = h;
		min = m;
		sec = s;
	}
	void display() {
		cout << hour << ":" << min<< ":"<< sec  << endl;
	}
	void add(Time t1, Time t2) {
		hour = t1.hour + t2.hour;
		min = t1.min + t2.min;
		sec = t1.sec + t2.sec;
	}
};
int main() {
	Time A(5, 12, 13), B(6, 7, 20), C;
	C.add(A, B);
	C.display();
	getchar();
	return 0;
}