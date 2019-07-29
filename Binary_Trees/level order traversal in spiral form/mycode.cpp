#include<iostream>
#include<stack>
using namespace std;

struct node
{
	int data;
	struct node *lchild,*rchild;
};

class tree
{
	public:

		void spiral_form(struct node *);
};


void tree::spiral_form(struct node *root)
{
	if(root==NULL)
		return;

	stack<struct node *>arr1;
	stack<struct node *>arr2;

	struct node *ptr;

	arr1.push(root);
	while(!arr1.empty()||!arr2.empty())
	{
		while(!arr1.empty())
		{
			ptr=arr1.top();
			arr1.pop();
			cout<<ptr->data<<" ";
			if(ptr->rchild)
				arr2.push(ptr->rchild);
			if(ptr->lchild)
				arr2.push(ptr->lchild);
		}

		while(!arr2.empty())
		{
			ptr=arr2.top();
			arr2.pop();
			cout<<ptr->data<<" ";
			if(ptr->lchild)
				arr1.push(ptr->lchild);
			if(ptr->rchild)
				arr1.push(ptr->rchild);
		}
	}
}

struct node *new_node(int val)
{
	struct node *ptr=new node;
	ptr->data=val;
	ptr->lchild=NULL;
	ptr->rchild=NULL;
	return ptr;
}

struct node *insert(struct node *root,int val)
{
	if(root==NULL)
		return new_node(val);
	else if(val<root->data)
		root->lchild=insert(root->lchild,val);
	else
		root->rchild=insert(root->rchild,val);

	return root;
}

int main(void)
{
	int i,val,count;
	struct node *root;
	root=NULL;
	tree ob;
	cout<<"Enter the values for tree"<<endl<<"Enter -1 to exit"<<endl;
	cin>>val;
	while(val!=-1)
	{
		root=insert(root,val);
		cin>>val;
	}
	ob.spiral_form(root);
}
