//with recursion

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

		void DownRight(struct node *);
		void print(struct node *);
};

void tree::DownRight(struct node *root)
{
	if(root==NULL)
		return ;

	DownRight(root->lchild);
	DownRight(root->rchild);

	if(!root->lchild)
		root->lchild=root->rchild;

	else
		root->lchild->rchild=root->rchild;

	root->rchild=NULL;
}

void tree::print(struct node *root)
{
	if(root==NULL)
		return ;

	print(root->lchild);
	cout<<root->data<<" ";
	print(root->rchild);
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
	ob.DownRight(root);
	ob.print(root);
}
