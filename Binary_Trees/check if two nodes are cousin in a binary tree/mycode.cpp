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

		int Cousins(struct node *,struct node *,struct node *);
};

int FindLevel(struct node *root,struct node *a,int level)
{
	int left,right;
	if(root==NULL)
		return -1;

	if(root==a)
		return level;

	left=FindLevel(root->lchild,a,level+1);

	if(left!=-1)
		return left;

	right=FindLevel(root->rchild,a,level+1);
	return right;
}

int CheckCousin(struct node *root,struct node *a,struct node *b)
{
	if(root==NULL)
		return 0;

	if((root->lchild==a && root->rchild==b)||(root->lchild==b && root->rchild==a))
		return 1;

	return (CheckCousin(root->lchild,a,b)||CheckCousin(root->rchild,a,b));
}

int tree::Cousins(struct node *root,struct node *a,struct node *b)
{
	if(root==NULL)
		return 0;

	if(FindLevel(root,a,0)==FindLevel(root,b,0) && !CheckCousin(root,a,b))
		return 1;
	else
		return 0;
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
	struct node *root,*a,*b;
	root=NULL;
	tree ob;
	cout<<"Enter the values for tree"<<endl<<"Enter -1 to exit"<<endl;
	cin>>val;
	while(val!=-1)
	{
		root=insert(root,val);
		cin>>val;
	}
	a=root->lchild->lchild;
	b=root->lchild;
	if(ob.Cousins(root,a,b))
		cout<<"true"<<endl;
	else
		cout<<"false"<<endl;
}
