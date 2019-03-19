#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
struct node
{
	int coeff;
	int power;
	struct node *next;
};
class Polynomial
{
	struct node *start;
public:
	Polynomial();
	void Insert_Last(int,int);
	void Traverse_Forward();
	void PolynomialAdd(Polynomial&,Polynomial&);
	~Polynomial();
};
Polynomial::Polynomial()
{
	start = NULL;
}
void Polynomial::Insert_Last(int ele,int p)
{
	struct node *temp;
	temp = new node;
	temp->coeff = ele;
	temp->power = p;
	temp->next = NULL;
	if (start == NULL)
		start = temp;
	else
	{
		struct  node *curr;
		curr = start;
		while (curr->next != NULL)
			curr = curr->next;
		curr->next = temp;
	}
}
void Polynomial::Traverse_Forward()
{
	struct node *curr = start;
	while (curr != NULL)
	{
		cout << curr->coeff << "x^"<<curr->power<<"+";
		curr = curr->next;
	}
	cout << "\n";
}
void Polynomial::PolynomialAdd(Polynomial &p1, Polynomial &p2)
{
	struct node *c1 = p1.start;
	struct node *c2 = p2.start;
	while (c1 != NULL && c2 != NULL)
	{
		if (c1->power > c2->power)
		{
			Insert_Last(c1->coeff,c1->power);
			c1 = c1->next;
		}
		else if (c2->power > c1->power)
		{
			Insert_Last(c2->coeff,c2->power);
			c2 = c2->next;
		}
		else
		{
			Insert_Last(c1->coeff+c2->coeff, c2->power);
			c1 = c1->next;
			c2 = c2->next;
		}
	}
	while (c1 != NULL)
	{
		Insert_Last(c1->coeff, c1->power);
		c1 = c1->next;
	}
	while (c2 != NULL)
	{
		Insert_Last(c2->coeff, c2->power);
		c2 = c2->next;
	}
}
Polynomial::~Polynomial()
{
	struct node *temp;
	while (start != NULL)
	{
		temp = start;
		start = start->next;
		delete temp;
	}
}
int main()
{
	Polynomial p1, p2,p3;
	int c,e,p;
	while (1)
	{
		cout << "enter 1.enter 2.exit for list1\n";
		cin >> c;
		switch (c)
		{
		case 1:cout << "enter ele and power";
			cin >> e >> p;
			p1.Insert_Last(e, p);
		}
		if (c == 2)
			break;
	}
	while (1)
	{
		cout << "enter 1.enter 2.exit for list2\n";
		cin >> c;
		switch (c)
		{
		case 1:cout << "enter ele and power";
			cin >> e >> p;
			p2.Insert_Last(e, p);
		}
		if (c == 2)
			break;
	}
	p3.PolynomialAdd(p1, p2);
	p1.Traverse_Forward(); p2.Traverse_Forward();
	p3.Traverse_Forward();
	return 0;
}