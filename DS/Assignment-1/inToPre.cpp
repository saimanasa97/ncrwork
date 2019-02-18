#include<iostream>
#include<ctype.h>
#include<string.h>
#include<algorithm>
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
}
char _stack_::pop() {

	return  stk.s[stk.top--];
}
char _stack_::peek() {

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
    char res[20];
    int j=0;
	for (int i = 0;i < strlen(exp);i++) {
		char c = exp[i];
		if (isalnum(c)) {
			res[j++]=c;
		}
		else if (c == '+' || c == '-' || c == '*' || c == '/') {
			if (s.isEmpty())
				s.push(c);
			else if (!s.isEmpty() && ((precedence(c) > precedence(s.peek()))))
				s.push(c);
			else
			{
				res[j++]= s.pop();
				s.push(c);
			}
		}
		else if (c == '[' || c == '(' || c == '{')
			s.push(c);
		else {
			if (c == ')') {
				while (s.peek() != '(')
					res[j++]=s.pop();
				s.pop();
			}
			else if (c == ']') {
				while (s.peek() != '[')
					res[j++]= s.pop();
				s.pop();
			}
			else if (c == '}') {
				while (s.peek() != '{')
					res[j++]= s.pop();
				s.pop();
			}
		}
	}

		while(!s.isEmpty())
		res[j++]= s.pop();
		res[j]='\0';
		reverse(res, &res[ strlen( res )] );
		cout<<res;
}
int main() {
	char exp[20];
	int len;
	cout << "enter an infix expression\n";
	cin >> exp;
	len=strlen(exp);
	_stack_ s(len);
	for(int i=0;i<len;i++){
        if(exp[i] == '(')
            exp[i] = ')';
        else if((exp[i]== '[') || (exp[i]=='{'))
            exp[i] = exp[i]+2;
        else if(exp[i]==']' || exp[i]=='}')
            exp[i]=exp[i]-2;
        else if(exp[i]==')')
            exp[i]='(';
	}
	reverse(exp, &exp[ strlen( exp )] );
	infixToPostfix(s,exp);
	return 0;
}
