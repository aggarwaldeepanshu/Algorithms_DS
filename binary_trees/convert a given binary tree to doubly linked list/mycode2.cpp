#include<iostream>
using namespace std;

struct node
{
	int data;
	struct node *lchild,*rchild;
};

class tree
{
	public:

		void BinarytoDLL(struct node *,struct node **);
};

void tree::BinarytoDLL(struct node *root,struct node **start)
{
	if(root==NULL)
		return;

	static struct node *prev=NULL;
	BinarytoDLL(root->lchild,start);

	if(prev==NULL)
		*start=root;
	else
	{
		prev->rchild=root;
		root->lchild=prev;
	}
	prev=root;

	BinarytoDLL(root->rchild,start);
}

void PrintDLL(struct node *start)
{
	struct node *ptr=start;
	while(ptr)
	{
		cout<<ptr->data<<" ";
		ptr=ptr->rchild;
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
	int i,val;
	struct node *root,*start;
	root=NULL;
	start=NULL;
	tree ob;
	cout<<"Enter the values for tree"<<endl<<"Enter -1 to exit"<<endl;
	cin>>val;
	while(val!=-1)
	{
		root=insert(root,val);
		cin>>val;
	}
	ob.BinarytoDLL(root,&start);
	PrintDLL(start);
}
