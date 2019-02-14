#include<iostream>
#include<cstring>
using namespace std;
class employee {
	char name[50];
	int id;
public:
	employee() {
		strcpy_s(name,sizeof(name), "boss");
		id = 0;
		cout << "default constructor\n";
	}
	employee(employee &e) {
		strcpy_s(this->name, sizeof(name), e.name);
		this->id = e.id;
		cout << "copy constructor\n";
	}
	employee(char n[],int i) {
		strcpy_s(name, sizeof(name), n);
		id = i;
		cout << "parameterized constructor\n";
	}
	~employee() {
		cout << "destructor\n";
	}
};
int main() {
	employee e1("john", 1), e2("peter", 2);
	employee e3(e2),e4(e1);
	cout << sizeof(e4)<<endl;
	cout << sizeof(e3);
	getchar();
	return 0;
}