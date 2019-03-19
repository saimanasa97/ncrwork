#include<stdio.h>
#include<iostream>
using namespace std;
class Queue
{
	int rear;
	int front;
	int *q;
	int SIZE;
public:
	Queue();
	void getSize(int);
	void push_front(int);
	void push_back(int);
	int pop_front();
	int pop_back();
	bool Overflow_pushback();
	bool Overflow_pushfront();
	bool Underflow_popfront();
	bool Underflow_popback();
	void display();
	~Queue();
};
Queue::Queue()
{
	q = NULL;
	front = -1;
	rear = -1;
}
bool Queue::Overflow_pushback()
{
	return (rear == (SIZE - 1));
}
bool Queue::Overflow_pushfront()
{
	return (front == 0);
}
void Queue::push_back(int ele)
{
	if (!Overflow_pushback())
	{
		if ((front == rear) && (front == -1))
			front = 0;
		q[++rear] = ele;
	}
	else
		cout << "queue full\n";
}
void Queue::push_front(int ele)
{
	if (!Overflow_pushfront())
	{
		if ((front == rear) && (front == -1))
		{
			front = rear = 0;
			q[front] = ele;
		}
		else
		q[--front] = ele;
	}
	else
		cout << "queue full\n";
}
bool Queue::Underflow_popfront()
{
	return (front == -1);
}
bool Queue::Underflow_popback()
{
	return (rear == -1);
}
int Queue::pop_front()
{
	int x = -999;
	if (!Underflow_popfront())
	{
		if (front == rear)
		{
			x = q[front];
			front = rear = -1;
		}
		else
			x = q[front++];
	}
	else
		cout << "No elements\n";
	return x;
}
int Queue::pop_back()
{
	int x = -999;
	if (!Underflow_popback())
	{
		if (front == rear)
		{
			x = q[front];
			front = rear = -1;
		}
		else
			x = q[rear--];
	}
	else
		cout << "No elements\n";
	return x;
}
void Queue::getSize(int n)
{
	q = new int[n];
	SIZE = n;
}
void Queue::display()
{
	int i;
	for (i = front; i <= rear; i++)
		cout << q[i] << " ";
	cout << "\n";
}
Queue::~Queue()
{
	if (q != NULL)
		delete q;
}
int main()
{
	int n, c, ele;
	Queue que;
	cout << "enter size of queue" << "\n";
	cin >> n;
	que.getSize(n);
	while (1)
	{
		cout << "enter 1.push_front 2.push_back 3.pop_front 4.pop_back 5.display 6.exit" << "\n";
		cin >> c;
		switch (c)
		{
		case 1:cout << "enter ele to push" << "\n";
			cin >> ele;
			que.push_front(ele);
			break;
		case 2:cout << "enter ele to push" << "\n";
			cin >> ele;
			que.push_back(ele);
			break;
		case 3:ele = que.pop_front();
			cout << "popped ele" << ele << endl;
			break;
		case 4:ele = que.pop_back();
			cout << "popped ele" << ele << endl;
			break;
		case 5:que.display();
			break;
		}
		if (c == 6)
			break;
	}
	return 0;
}