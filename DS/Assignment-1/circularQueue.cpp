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
	void enQueue(int);
	int deQueue();
	bool Overflow();
	bool Underflow();
	void display();
	~Queue();
};
Queue::Queue()
{
	q = NULL;
	front = -1;
	rear = -1;
}
void Queue::getSize(int n)
{
	q = new int[n];
	SIZE = n;
}
bool Queue::Overflow()
{
	return (front == ((rear + 1) % SIZE));
}
void Queue::enQueue(int ele)
{
	if (!Overflow())
	{
		if ((front == rear) && (front == -1))
			front = 0;
		rear = (rear + 1) % SIZE;
		q[rear] = ele;
	}
	else
		cout << "queue full\n";
}
bool Queue::Underflow()
{
	return (front == -1);
}
int Queue::deQueue()
{
	int x = -999;
	if (!Underflow())
	{
		if (front == rear)
		{
			x = q[front];
			front = rear = -1;
		}
		else
		{
			x = q[front];
			front = (front + 1) % SIZE;
		}
	}
	else
		cout << "No elements\n";
	return x;
}
void Queue::display()
{
	int i;
	if (front != -1)
	{
		for (i = front; i != rear; i = (i + 1) % SIZE)
			cout << q[i] << " ";
		cout << q[i];
	}
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
		cout << "enter 1.enqueue 2.dequeue 3.display 4.exit" << "\n";
		cin >> c;
		switch (c)
		{
		case 1:cout << "enter ele to push" << "\n";
			cin >> ele;
			que.enQueue(ele);
			break;
		case 2:ele = que.deQueue();
			cout << "popped ele" << ele << endl;
			break;
		case 3:que.display();
			break;
		}
		if (c == 4)
			break;
	}
	return 0;
}