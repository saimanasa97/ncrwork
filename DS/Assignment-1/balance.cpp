#include<iostream>
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
bool balanced(_stack_ &s,char *str) {
	int flag = 0;
	
	for (int i = 0;i < strlen(str);i++) {
			char x = str[i],c;
			
			switch (x) {
			case '(':
			case '{':
			case '[':
				if(!s.isFull())
				s.push(x);
				break;
			case ')':
				if (!s.isEmpty() && s.peek() == '(')
					c = s.pop();
				else
					flag = 1;
				break;
			case '}':
				if (!s.isEmpty() && s.peek() == '{')
					c = s.pop();
				else
					flag = 1;
				break;
			case ']':
				if (!s.isEmpty() && s.peek() == '[')
					c = s.pop();
				else
					flag = 1;
				break;
			}
			if (flag == 1) {
				break;
			}
			
	}
	if (flag == 0 && s.isEmpty())
		return true;
	
	return false;
}
int main() {
	char str[50];
	cout << "enter an expression\n";
	cin >> str;
	_stack_ s(strlen(str));
	if (balanced(s,str))
		cout << "the expression is balanced";
	else
		cout << "the expression is not balanced";
	return 0;
}