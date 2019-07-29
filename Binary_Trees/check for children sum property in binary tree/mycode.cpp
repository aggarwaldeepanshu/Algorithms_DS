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

		int sum_property(struct node *);
};


int tree::sum_property(struct node *root)
{
	int left=0,right=0;
	if(root==NULL)
		return 1;

	if(root->lchild==NULL&&root->rchild==NULL)
		return root->data;
	else
	{
		if(root->lchild)
			left=root->lchild->data;
		if(root->rchild)
			right=root->rchild->data;

		if((root->data==left+right)&&sum_property(root->lchild)&&sum_property(root->rchild))
			return 1;
		else
			return 0;
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
	else if(val<=root->data)
		root->lchild=insert(root->lchild,val);
	else
		root->rchild=insert(root->rchild,val);

	return root;
}

int main(void)
{
	int i,val;
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

	if(ob.sum_property(root))
		cout<<"Property is followed"<<endl;
	else
		cout<<"Violates the property"<<endl;
}
