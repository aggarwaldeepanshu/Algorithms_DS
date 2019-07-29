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

		struct node *LCA(struct node *,int,int);
};

struct node *tree::LCA(struct node *root,int n1,int n2)
{
	struct node *left=NULL,*right=NULL;
	if(root==NULL)
		return NULL;

	if(root->data==n1||root->data==n2)
		return root;

	left=LCA(root->lchild,n1,n2);
	right=LCA(root->rchild,n1,n2);
	if(left && right)
		return root;
	else if(left)
		return left;
	else 
		return right;
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
	int i,val,n1,n2;
	struct node *root,*ptr;
	root=NULL;
	tree ob;
	cout<<"Enter the values for tree"<<endl<<"Enter -1 to exit"<<endl;
	cin>>val;
	while(val!=-1)
	{
		root=insert(root,val);
		cin>>val;
	}
	cout<<"Enter the two values"<<endl;
	cin>>n1>>n2;
	ptr=ob.LCA(root,n1,n2);
	cout<<ptr->data<<endl;
}
