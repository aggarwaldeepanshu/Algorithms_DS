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

		void BoundaryTraversal(struct node *);
		void traverse_left(struct node *);
		void traverse_leaf(struct node *);
		void traverse_right(struct node *);
};

void tree::BoundaryTraversal(struct node *root)
{
	if(root==NULL)
		return ;
        
        cout<<root->data<<" ";
	traverse_left(root->lchild);
	traverse_leaf(root->lchild);
	traverse_leaf(root->rchild);
	traverse_right(root->rchild);
}

void tree::traverse_left(struct node *root)
{
	if(root==NULL)
		return ;

	if(root->lchild)
	{
		cout<<root->data<<" ";
		traverse_left(root->lchild);
	}
	else if(root->rchild)
	{
		cout<<root->data<<" ";
		traverse_left(root->rchild);
	}
}

void tree::traverse_right(struct node *root)
{
	if(root==NULL)
		return ;

	if(root->rchild)
	{
		traverse_right(root->rchild);
		cout<<root->data<<" ";
	}
	else if(root->lchild)
	{
		traverse_right(root->lchild);
		cout<<root->data<<" ";
	}
}

void tree::traverse_leaf(struct node *root)
{
	if(root==NULL)
		return ;

	if(root->lchild)
		traverse_leaf(root->lchild);

	if(root->lchild==NULL&&root->rchild==NULL)
		cout<<root->data<<" ";

	if(root->rchild)
		traverse_leaf(root->rchild);
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
	int i,val,size;
	struct node *root;
	root=NULL;
	tree ob;
	cout<<"Enter the values"<<endl<<"Enter -1 to exit"<<endl;
	cin>>val;
	while(val!=-1)
	{
		root=insert(root,val);
		cin>>val;
	}
	ob.BoundaryTraversal(root);
}
