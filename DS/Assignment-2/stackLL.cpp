#include<iostream>
using namespace std;
struct node {
	int data;
	struct node *next;
};
class _list_ {
	struct node *start;
public:
	_list_();
	void Insert_first(int);
	int Delete_first();
	void Travel_backward();
	int peek();
	~_list_();
};
_list_::_list_() {
	start = NULL;
}
void _list_::Insert_first(int ele) {
	struct node *temp;
	temp = new node;
	temp->data = ele;
	temp->next = start;
	start = temp;
}
int _list_::Delete_first() {
	int x = -1;
	if (start != NULL) {
		struct  node *temp = start;
		start = start->next;
		x = temp->data;
		delete temp;
	}
	return x;
}
void print(struct node *temp) {
	if (temp != NULL) {
		print(temp->next);
		cout << temp->data << "->";
	}
}
void _list_::Travel_backward() {
	struct node *temp = start;
	print(start);
	cout << "NULL" << endl;
}
int _list_::peek() {
	int x = -1;
	if (start != NULL)
		x = start->data;
	return x;
}
_list_::~_list_() {
	struct node *temp;
	while (start != NULL) {
		temp = start;
		start = start->next;
		delete temp;
	}
}
int main() {
	int n;
	int ele;
	_list_ stack;
	while (1) {
		cout << "1.push\t2.pop\t3.peek\t4.display\t5.exit\n";
		cin >> n;
		switch (n) {
		case 1:
			
			cout<< "enter element to push\n";
			cin >> ele;
			stack.Insert_first(ele);
			break;
		case 2:
			ele = stack.Delete_first();
			if (ele != -1)
				cout << "Popped: " << ele << endl;
			else
				cout << "stack is empty\n";
			break;
		case 3:
			 ele = stack.peek();
			if (ele != -1)
				cout << "top element : " << ele << endl;
			else
				cout << "stack is empty\n";
			break;
		case 4:
			stack.Travel_backward();
			break;
		case 5:
			exit(0);
		default:
			cout << "enter valid choice\n";
			break;
		}
	}
}