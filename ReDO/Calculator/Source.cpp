#include<stdio.h>
#include<iostream>
#include<stack>
#pragma warning(disable:4996)
using namespace std;
int add(int, int);
int sub(int, int);
int mul(int, int);
int division(int, int);
int precedence(char op) {
	if (op == '+' || op == '-')
		return 1;
	if (op == '*' || op == '/')
		return 2;
	return 0;
}
int applyOp(int a, int b, char op) {
	switch (op) {
	case '+': return add(a,b);
	case '-': return sub(a,b);
	case '*': return mul(a,b);
	case '/': return division(a,b);
	}
}

int evaluate(char *expr)
{
	stack<int> operand;
	stack<char> operators;
	int i;
	for (i = 0; expr[i] != '\0'; i++)
	{
		if (expr[i] == ' ')
			continue;
		else if (expr[i] == '(')
			operators.push(expr[i]);
		else if (isdigit(expr[i]))
		{
			int var = 0;
			while (expr[i] != '\0' && isdigit(expr[i]))
			{
				var = var * 10 + expr[i] - '0';
				i++;
			}
			i--;
			operand.push(var);
			
		}
		else if (expr[i] == ')')
		{
			while ((!operators.empty()) && operators.top() != '(')
			{
				int op1 = operand.top();
				operand.pop();
				int op2 = operand.top();
				operand.pop();

				char op = operators.top();
				operators.pop();

				operand.push(applyOp(op2, op1, op));
			}
			operators.pop();

		}
		else
		{
			while (!operators.empty() && precedence(operators.top()) >= precedence(expr[i]))
			{
				int op1 = operand.top();
				operand.pop();
				int op2 = operand.top();
				operand.pop();

				char op = operators.top();
				operators.pop();
				
				operand.push(applyOp(op2, op1, op));
			}
			operators.push(expr[i]);
		}
	}
	while (!operators.empty())
	{
		int op1 = operand.top();
		operand.pop();
		int op2 = operand.top();
		operand.pop();

		char op = operators.top();
		operators.pop();
		
		operand.push(applyOp(op2, op1, op));
	}
	
	return operand.top();
}
int main()
{
	char expr[50];
	printf("Enter expression to evaluate\n");
	scanf("%[^\t\n]s", expr);
	printf("Result = %d\n", evaluate(expr));
	return 0;
}