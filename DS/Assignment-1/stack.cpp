#include<iostream>
using namespace std;
struct __stack__ {
	int top;
	int *s;
	int size;
};
class _stack_ {
	struct __stack__ stk;
public:
	_stack_();
	_stack_(int);
	void push(int);
	int pop();
	int peek();
	bool isEmpty();
	bool isFull();
	void display();
	~_stack_();
};
_stack_::_stack_() {
	stk.top = -1;
}
_stack_::_stack_(int n) {
	stk.top = -1;
	stk.size = n;
	stk.s = new int[n];
}
void _stack_::push(int ele) {
	if(!isFull())
		stk.s[++stk.top] = ele;
	else 
		throw out_of_range("overflow");
}
int _stack_::pop() {
	if (isEmpty())
		throw out_of_range("undeflow");
	return  stk.s[stk.top--];
}
int _stack_::peek() {
	if (isEmpty())
		throw out_of_range("undeflow");
	return  stk.s[stk.top];
}
bool _stack_::isEmpty() {
	return stk.top == -1;
}
bool _stack_::isFull() {
	return stk.top == stk.size - 1;
}
void _stack_::display() {
	for (int i = 0;i <= stk.top;i++) {
		cout << stk.s[i] << " ";
	}
	cout << endl;
}
_stack_::~_stack_() {
	delete stk.s;
}
int main() {
	int n;
	try {
		cout << "enter the size of the stack: ";
		cin >> n;
		_stack_ s(n);
		while (1) {
			int c, ele;
			cout << "1.push\t2.pop\t3.display\n4.peek\t5.exit\n";
			cin >> c;
			switch (c) {
			case 1:
				cout << "enter element to push : ";
				cin >> ele;
				s.push(ele);
				break;
			case 2:
				cout << "element popped is : " << s.pop() << endl;
				break;
			case 3:
				s.display();
				break;
			case 4:
				cout << "the element on the top of the stack is : " << s.peek()<<endl;
				break;
			case 5:
				exit(0);
			default:
				cout << "enter a valid choice\n";
			}
		}
	}
	catch (char *e) {
		cout <<e ;
	}
	return 0;
}