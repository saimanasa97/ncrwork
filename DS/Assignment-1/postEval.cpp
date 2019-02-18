#include<iostream>
#include<ctype.h>
using namespace std;
struct __stack__ {
	int top;
	float *s;
	int size;
};
class _stack_ {
	struct __stack__ stk;
public:
	_stack_(int);
	void push(float);
	float pop();
	float peek();
	bool isEmpty();
	bool isFull();
	~_stack_();
};

_stack_::_stack_(int n) {
	stk.top = -1;
	stk.size = n;
	stk.s = new float[n];
}
void _stack_::push(float ele) {
		stk.s[++stk.top] = ele;
}
float _stack_::pop() {
	return  stk.s[stk.top--];
}
float _stack_::peek() {
	return  stk.s[stk.top];
}
bool _stack_::isEmpty() {
	return stk.top == -1;
}
bool _stack_::isFull() {
	return stk.top == stk.size - 1;
}
_stack_::~_stack_() {
	delete stk.s;
}
float evaluatePostfix(_stack_ &s, char * exp) {
	for (int i = 0;i < strlen(exp);i++) {
		char c=exp[i];
		if (isdigit(c)) {
			s.push(c-'0');
		}
		else if(!s.isEmpty())
		{
			float a = s.pop();
			float b = s.pop();
			switch (c) {
			case '+':
				s.push(b+a);
				break;
			case '-':
				s.push(b-a);
				break;
			case '*':
				s.push(b*a);
				break;
			case '/':
				s.push(b/a);
				break;
			}
		}
	}
	return s.peek();
}
int main() {
	char exp[20];
	cout << "enter a postfix expression\n";
	cin >> exp;
	_stack_ s(strlen(exp));
	cout << evaluatePostfix(s, exp);
}