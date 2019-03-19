#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
struct node
{
	int data;
	struct node *prev;
	struct node *next;
};
class DLL
{
	struct node *start;
public:
	DLL();
	void Insert_First(int);
	void Insert_Last(int);
	void Insert_After(int, int);
	void Insert_Before(int, int);
	int Delete_First();
	int Delete_Last();
	void Delete_Spec(int);
	void Traverse_Forward();
	void Traverse_Backward();
	~DLL();
};
DLL::DLL()
{
	start = NULL;
}
void DLL::Insert_First(int ele)
{
	struct node *temp;
	temp = new node;
	temp->data = ele;
	temp->prev = NULL;
	temp->next = start;
	if (start != NULL)
		start->prev = temp;
	start = temp;
}
void DLL::Insert_Last(int ele)
{
	struct node *temp;
	temp = new node;
	temp->data = ele;
	temp->next = NULL;
	if (start == NULL)
	{
		temp->prev = NULL;
		start = temp;
	}
	else
	{
		struct node *curr = start;
		while (curr->next != NULL)
			curr = curr->next;
		temp->prev = curr;
		curr->next = temp;
	}
}
void DLL::Insert_After(int sele, int ele)
{
	if (start != NULL)
	{
		struct node *curr;
		curr = start;
		while (curr != NULL && curr->data != sele)
			curr = curr->next;
		if (curr != NULL)
		{
			struct node *temp;
			temp = new node;
			temp->data = ele;
			temp->prev = curr;
			temp->next = curr->next;
			if (curr->next != NULL)
				curr->next->prev = temp;
			curr->next = temp;
		}
		else
			cout << "Element not found\n";
	}
	else
		cout << "List empty\n";
}
void DLL::Insert_Before(int sele, int ele)
{
	if (start != NULL)
	{
		struct node *curr;
		curr = start;
		while (curr != NULL && curr->data != sele)
			curr = curr->next;
		if (curr != NULL)
		{
			struct node *temp;
			temp = new node;
			temp->data = ele;
			temp->next = curr;
			temp->prev = curr->prev;
			if (curr->prev != NULL)
				curr->prev->next = temp;
			else
				start = temp;
			curr->prev = temp;
		}
		else
			cout << "element not found\n";
	}
	else
		cout << "list empty\n";
}
int DLL::Delete_First()
{
	int x = -999;
	if (start != NULL)
	{
		struct node *temp = start;
		x = temp->data;
		start = start->next;
		if (start != NULL)
			start->prev = NULL;
		delete temp;
	}
	else
		cout << "List empty\n";
	return x;
}
int DLL::Delete_Last()
{
	int x = -999;
	if (start != NULL)
	{
		struct node *curr = start;
		while (curr->next != NULL)
			curr = curr->next;
		x = curr->data;
		if (curr->prev != NULL)
			curr->prev->next = NULL;
		else
			start = NULL;
		delete curr;
	}
	else
		cout << "List empty\n";
	return x;
}
void DLL::Delete_Spec(int ele)
{
	if (start != NULL)
	{
		struct node *curr = start; int x;
		while (curr != NULL && curr->data != ele)
			curr = curr->next;
		x = curr->data;
		if (curr->prev != NULL)
			curr->prev->next = curr->next;
		else
			start = curr->next;
		if (curr->next != NULL)
			curr->next->prev = curr->prev;
		delete curr;
	}
	else
		cout << "List empty\n";
}
void DLL::Traverse_Forward()
{
	struct node *curr = start;
	while (curr != NULL)
	{
		cout << curr->data << " ";
		curr = curr->next;
	}
}
void DLL::Traverse_Backward()
{
	struct node *curr = start;
	while (curr->next != NULL)
		curr = curr->next;
	while (curr->prev != NULL)
	{
		cout << curr->data << " ";
		curr = curr->prev;
	}
}
DLL::~DLL()
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
	int c, ele, sele; DLL l;
	while (1)
	{
		cout << "enter 1.insert at begin 2.insert at end 3.insert after 4.insert before 5.delete first 6.delete last 7.delete specific 8.traverse forward 9.traverse backward 10.exit\n";
		cin >> c;
		switch (c)
		{
		case 1:cout << "enter ele to insert";
			cin >> ele;
			l.Insert_First(ele);
			break;
		case 2:cout << "enter ele to insert";
			cin >> ele;
			l.Insert_Last(ele);
			break;
		case 3:cout << "enter ele to insert";
			cin >> ele;
			cout << "enter search ele";
			cin >> sele;
			l.Insert_After(sele, ele);
			break;
		case 4:cout << "enter ele to insert";
			cin >> ele;
			cout << "enter search ele";
			cin >> sele;
			l.Insert_Before(sele, ele);
			break;
		case 5:ele = l.Delete_First();
			cout << "Deleted ele = " << ele;
			break;
		case 6:ele = l.Delete_Last();
			cout << "Deleted ele = " << ele;
			break;
		case 7:cout << "enter ele to delete";
			cin >> ele;
			l.Delete_Spec(ele);
			break;
		case 8:l.Traverse_Forward();
			break;
		case 9:l.Traverse_Backward();
			break;
		
		}
		if (c == 10)
			break;
	}
	return 0;
}