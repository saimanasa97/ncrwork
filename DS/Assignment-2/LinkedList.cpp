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
	void Insert_last(int);
	void Insert_after(int, int);
	void Insert_before(int, int);
	int Delete_first();
	int Delete_last();
	void Delete_spec(int);
	void Travel_forward();
	void Travel_backward();
	void Reverse();
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
void _list_::Insert_last(int ele) {
	struct node *temp, *curr = start;
	temp = new node;
	temp->data = ele;
	temp->next = NULL;
	if (start == NULL)
		start = temp;
	else {
		while (curr->next != NULL)
			curr = curr->next;
		curr->next = temp;
	}
}
void _list_::Insert_after(int sele, int ele) {
	if (start != NULL) {
		struct node *temp, *curr = start;
		while (curr != NULL && curr->data != sele)
			curr = curr->next;
		if (curr != NULL) {
			temp = new node;
			temp->data = ele;
			temp->next = curr->next;
			curr->next = temp;
		}
		else
			cout << "Element not found\n";
	}
	else
		cout << "List is empty\n";
}
void _list_::Insert_before(int sele, int ele) {
	if (start != NULL) {
		struct node *temp, *curr = start;
		if (start->data == sele) {
			temp = new node;
			temp->data = ele;
			temp->next = start;
			start = temp;
		}
		else {
			while (curr->next != NULL && curr->next->data != sele)
				curr = curr->next;
			if (curr->next != NULL) {
				temp = new node;
				temp->data = ele;
				temp->next = curr->next;
				curr->next = temp;
			}
			else
				cout << "Element not found\n";
		}
	}
	else
		cout << "List is empty\n";
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
int _list_::Delete_last() {
	int x = -1;
	if (start != NULL) {
		if (start->next == NULL) {
			x = start->data;
			delete start;
			start = NULL;
		}
		else {
			struct  node *curr = start;
			while (curr->next->next != NULL)
				curr = curr->next;
			x = curr->next->data;
			delete curr->next;
			curr->next = NULL;
		}
	}
	return x;
}
void _list_::Delete_spec(int ele) {
	if (start != NULL) {
		struct node *curr = start;
		if (start->data == ele) {
			struct node *curr = start;
			start = start->next;
			delete curr;
			start = curr->next;
		}
		else {
			while (curr->next != NULL && curr->next->data != ele)
				curr = curr ->next;
			if (curr->next != NULL) {
				struct node *temp;
				temp = curr->next;
				curr->next = temp->next;
				delete temp;
			}
			else
				cout << "element not found\n";
		}
	}
	else
		cout << "list is empty\n";
}
void _list_::Travel_forward() {
	struct  node *curr = start;
	while (curr != NULL) {
		cout << curr->data << "->";
		curr = curr->next;
	}
	cout <<"NULL"<< endl;
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
void _list_::Reverse() {
	struct node *rev = NULL,*temp;
	while (start != NULL) {
		temp = start;
		start = start->next;
		temp->next = rev;
		rev = temp;
	}
	start = rev;
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
	int n,ele,sele;
	_list_ l;
	while (1) {
		cout << "1.Insert_first\t2.Insert_last\t3.Insert_after\t4.Inser_before\t5.Delete_first\t6.Delete_last\t7.delete_spec\t8.travel_forward\t9.Travel_backward\t10.reverse_list\t11.exit\n";
		cin >> n;
		switch (n)
		{
		case 1:
			cout << "enter element to insert: ";
			cin >> ele;
			l.Insert_first(ele);
			break;
		case 2:
			cout << "enter element to insert: ";
			cin >> ele;
			l.Insert_last(ele);
			break;
		case 3:
			cout << "enter element to search & insert : ";
			cin >>sele >> ele;
			l.Insert_after(sele,ele);
			break;
		case 4:
			cout << "enter element to search & insert : ";
			cin >> sele >> ele;
			l.Insert_before(sele, ele);
			break;
		case 5:
			ele = l.Delete_first();
			if (ele == -1)
				cout << "List is empty\n";
			else
				cout << "Deleted : " << ele << endl;
			break;
		case 6:
			ele = l.Delete_last();
			if (ele == -1)
				cout << "List is empty\n";
			else
				cout << "Deleted : " << ele << endl;
			break;
		case 7:
			cout << "enter element to delete: ";
			cin >> ele;
			l.Delete_spec(ele);
			break;
		case 8:
			l.Travel_forward();
			break;
		case 9:
			l.Travel_backward();
		case 10:
			l.Reverse();
			break;
		case 11:
			exit(0);
		default:cout << "enter a valid choice\n";
			break;
		}
	}
	return 0;
}