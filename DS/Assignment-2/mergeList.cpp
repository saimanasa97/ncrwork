#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
struct node
{
	int data;
	struct node *next;
};
class List
{
	struct node *start;
public:
	List();
	void createList();
	void merge(List&, List&);
	void Insert_Last(int);
	void display();
	~List();
};
List::List()
{
	start = NULL;
}
void List::createList()
{
	int c, ele;
	while (1)
	{
		cout << "enter choice 1.add an element 2.exit\n";
		cin >> c;
		if (c == 1)
		{
			struct node *temp;
			temp = new node;
			cout << "enter element to add\n";
			cin >> ele;
			temp->data = ele;
			temp->next = NULL;
			if (start == NULL)
				start = temp;
			else
			{
				struct node *curr = start;
				while (curr->next != NULL)
					curr = curr->next;
				curr->next = temp;
			}
		}
		else
			break;
	}
}
void List::Insert_Last(int ele)
{
	struct node *temp;
	temp = new node;
	temp->data = ele;
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
void List::merge(List &l1, List &l2)
{
	struct node *p1 = l1.start;
	struct node *p2 = l2.start;
	struct node *p3=NULL;

	while ((p1 != NULL) && (p2 != NULL))
	{
		//cout << "Hello";
		if (p1->data < p2->data)
		{
			Insert_Last(p1->data);
			p1 = p1->next;
		}
		else
		{
			Insert_Last(p2->data);
			p2 = p2->next;
		}
	}
	while (p1 != NULL)
	{
		Insert_Last(p1->data);
		p1 = p1->next;
	}
	while (p2 != NULL)
	{
		Insert_Last(p2->data);
		p2 = p2->next;
	}
	
}
void List::display()
{
	struct node *curr = start;
	while (curr != NULL)
	{
		cout << curr->data << " ";
		curr = curr->next;
	}
	cout << "\n";
}
List::~List()
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
	List l1, l2, l3;
	l1.createList();
	l2.createList();
	l3.merge(l1,l2);
	cout << "List 1 :"; l1.display();
	cout << "List 2 :"; l2.display();
	l3.display();
	return 0;
}