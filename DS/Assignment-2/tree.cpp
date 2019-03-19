#include<algorithm>
#include<iostream>
using namespace std;
struct node
{
	int data;
	struct node *right;
	struct node *left;
};
class BST
{
	struct node *start;
public:
	BST();
	void insert(int);
	void delete_ele(int);
	void preorder();
	void inorder();
	void postorder();
	~BST();
	int height();
	int FindMax();
	int FindMin();
	int no_of_leafs();
	int no_of_nonleafs();
	friend struct node* ins(struct node*, int);
	friend void preod(struct node*);
	friend void inod(struct node*);
	friend void postod(struct node*);
	friend int findmax(struct node*);
	friend void delete_node(struct node*);
	friend struct node* delete1(struct node*, int);
	friend int leafs(struct node*);
	friend int nonleafs(struct node*);
	friend int bstheight(struct node*);
};
BST::BST()
{
	start = NULL;
}
struct node* ins(struct node *curr, int ele)
{
	if (curr == NULL)
	{
		struct node *temp;
		temp = new node;
		temp->data = ele;
		temp->left = NULL;
		temp->right = NULL;
		return temp;
	}
	if (ele < curr->data)
		curr->left = ins(curr->left, ele);
	else
		curr->right = ins(curr->right, ele);
	return curr;

}
void BST::insert(int ele)
{
	start = ins(start, ele);

}
int findMax(struct node *curr)
{
	if (curr != NULL)
	{
		while (curr->right != NULL)
			curr = curr->right;
		return curr->data;
	}
	return -1;

}
struct node* delete1(struct node *curr, int ele)
{
	if (curr == NULL)
		return NULL;
	if (ele < curr->data)
		curr->left = delete1(curr->left, ele);
	else if (ele > curr->data)
		curr->right = delete1(curr->right, ele);
	else
	{
		if (curr->left != NULL && curr->right != NULL)
		{
			curr->data = findMax(curr->left);
		//	cout << curr->data << "\n";
			curr->left=delete1(curr->left, curr->data);
		}
		else
		{
			struct node *temp = curr;
			if (curr->left == NULL)
				curr = curr->right;
			else
				curr = curr->left;
			delete temp;
		}
	}
	return curr;
}
void BST::delete_ele(int ele)
{
	start = delete1(start, ele);
}
void preod(struct node *curr)
{
	if (curr == NULL)
		return;
	cout << curr->data << " ";
	preod(curr->left);
	preod(curr->right);
}
void BST::preorder()
{
	preod(start);
}
void inod(struct node *curr)
{
	if (curr == NULL)
		return;
	inod(curr->left);
	cout << curr->data << " ";
	inod(curr->right);
}
void BST::inorder()
{
	inod(start);
}
void postod(struct node *curr)
{
	if (curr == NULL)
		return;
	postod(curr->left);
	postod(curr->right);
	cout << curr->data << " ";
}
void BST::postorder()
{
	postod(start);
}
void delete_node(struct node *curr)
{
	if (curr == NULL)
		return;
	preod(curr->left);
	preod(curr->right);
	delete curr;
}
BST::~BST()
{
	delete_node(start);
}
int BST::FindMax()
{
	if (start != NULL)
	{
		struct node *curr = start;
		while (curr->right != NULL)
			curr = curr->right;
		return curr->data;
	}
	return -1;

}
int BST::FindMin()
{
	if (start != NULL)
	{
		struct node *curr = start;
		while (curr->left != NULL)
			curr = curr->left;
		return curr->data;
	}
	return -1;
}
int leafs(struct node *curr)
{
	if (curr == NULL)
		return 0;
	else if (curr->left == NULL && curr->right == NULL)
		return 1;
	else
		return leafs(curr->left) + leafs(curr->right);
}
int BST::no_of_leafs()
{
	return leafs(start);
}
int nonleafs(struct node *curr)
{
	if (curr == NULL)
		return 0;
	else if (curr->left == NULL && curr->right == NULL)
		return 0;
	else
		return 1 + nonleafs(curr->left) + nonleafs(curr->right);
}
int BST::no_of_nonleafs()
{
	return nonleafs(start);
}
int bstheight(struct node *curr)
{
	if (curr == NULL)
		return 0;
	if (curr->left == NULL && curr->right == NULL)
		return 0;
	else
		return 1 + std::max(bstheight(curr->left), bstheight(curr->right));
}
int BST::height()
{
	return bstheight(start);
}
int main()
{
	BST bst;
	int c,ele;
	while (1)
	{
		cout << "enter 1.insert 2.inorder 3.preorder 4.postorder 5.delete 6.height 7.findmax 8.findmin 9.leafs 10.non-leafs 11.exit\n";
		cin >> c;
		switch (c)
		{
		case 1:cout << "enter ele to insert\n";
			cin >> ele;
			bst.insert(ele);
			break;
		case 2:bst.inorder(); cout << "\n";
			break;
		case 3:bst.preorder(); cout << "\n";
			break;
		case 4:bst.postorder(); cout << "\n";
			break;
		case 5:cout << "enter ele to delete\n";
			cin >> ele;
			bst.delete_ele(ele);
			break;
		case 6:cout << "Height of bst : " << bst.height() << "\n";
			break;
		case 7:cout << "Maximum ele in tree : " << bst.FindMax() << "\n";
			break;
		case 8:cout << "Minimum ele in tree : " << bst.FindMin() << "\n";
			break;
		case 9:cout << "No of leafs : " << bst.no_of_leafs() << endl;
			break;
		case 10:cout << "No of non leaf nodes : " << bst.no_of_nonleafs() << endl;
			break;
		}
		if (c == 11)
			break;
	}
	return 0;
}