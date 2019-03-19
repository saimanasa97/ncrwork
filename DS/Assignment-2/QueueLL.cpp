#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
struct node
{
	int data;
	struct node *next;
};
class Queue
{
	struct node *start;
public:
	Queue();
	void enQueue(int);
	int deQueue();
	void display();
	~Queue();
};
Queue::Queue()
{
	start = NULL;
}
void Queue::enQueue(int ele)
{
	struct node *temp;
	temp = new node;
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
int Queue::deQueue()
{
	int x = -999;
	if (start != NULL)
	{
		struct node *temp;
		temp = start;
		x = temp->data;
		start = start->next;
		delete temp;
	}
	else
		cout << "Queue is empty\n";
	return x;
}
void Queue::display()
{
	struct node *curr = start;
	while (curr != NULL)
	{
		cout << curr->data << " ";
			curr = curr->next;
	}
	cout << "\n";
}
Queue::~Queue()
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
	Queue s;
	int c, ele;
	while (1)
	{
		cout << "enter choice 1.enQueue 2.deQueue 3.display 4.exit\n";
		cin >> c;
		switch (c)
		{
		case 1:cout << "enter ele to push\n";
			cin >> ele;
			s.enQueue(ele);
			break;
		case 2:ele = s.deQueue();
			cout << "poped ele = " << ele;
			break;
		case 3:s.display();
			break;
		}
		if (c == 4)
			break;
	}
	return 0;
}