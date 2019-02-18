#include<iostream>
#include<ctype.h>
using namespace std;
struct __stack__ {
	int top;
	char *s;
	int size;
};
class _stack_ {
	struct __stack__ stk;
public:
	_stack_();
	_stack_(int);
	void push(char);
	char pop();
	char peek();
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
	stk.s = new char[n];
}
void _stack_::push(char ele) {
	if (!isFull())
		stk.s[++stk.top] = ele;
	else
		throw "overflow";
}
char _stack_::pop() {
	if (isEmpty())
		throw "undeflow";
	return  stk.s[stk.top--];
}
char _stack_::peek() {
	if (isEmpty())
		throw "undeflow";
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
int precedence(char c) {
	if (c == '*' || c == '/')
		return 3;
	else if (c == '+' || c == '-')
		return 2;
	
		return 1;
}
void infixToPostfix(_stack_ &s, char *exp) {
	for (int i = 0;i < strlen(exp);i++) {
		char c = exp[i];
		if (isalnum(c)) {
			cout << c;
		}
		else if (c == '+' || c == '-' || c == '*' || c == '/') {
			if (s.isEmpty())
				s.push(c);
			else if (!s.isEmpty() && ((precedence(c) > precedence(s.peek()))))
				s.push(c);
			else
			{
				cout << s.pop();
				s.push(c);
			}
		}
		else if (c == '[' || c == '(' || c == '{')
			s.push(c);
		else {
			if (c == ')') {
				while (s.peek() != '(')
					cout << s.pop();
				s.pop();
			}
			else if (c == ']') {
				while (s.peek() != '[')
					cout << s.pop();
				s.pop();
			}
			else if (c == '}') {
				while (s.peek() != '{')
					cout << s.pop();
				s.pop();
			}
		}
	}
	
		while(!s.isEmpty())
		cout << s.pop();
}
int main() {
	char exp[20];
	cout << "enter an infix expression\n";
	cin >> exp;
	_stack_ s(strlen(exp));
	infixToPostfix(s,exp);
	return 0;
}