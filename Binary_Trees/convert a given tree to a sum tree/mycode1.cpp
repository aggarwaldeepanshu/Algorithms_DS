#include<iostream>
using namespace std;

struct node
{
	int data;
	struct node *lchild,*rchild,*next;
};

class tree
{
	public:

		int sumtree(struct node *,int *);
		void print(struct node *);
};

int isleaf(struct node *root)
{
	if(root&&root->lchild==NULL&&root->rchild==NULL)
		return 1;
	else
		return 0;
}

int tree::sumtree(struct node *root,int *sum)
{
	int ls=0,rs=0;

	if(root==NULL)
	{
		*sum=0;
		return 1;
	}

	if(root->lchild==NULL&&root->rchild==NULL)
	{
		*sum=root->data;
		return 1;
	}

	if(sumtree(root->lchild,&ls)&&sumtree(root->rchild,&rs))
	{

		if(isleaf(root->lchild))
		{
			root->lchild->data=0;
		}

		if(isleaf(root->rchild))
		{
			root->rchild->data=0;
		}

		*sum=root->data+ls+rs;
		root->data=ls+rs;
		return 1;
	}
}

void tree::print(struct node *root)
{
	if(root==NULL)
		return;

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
	ptr->next=NULL;
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
	int i,val,size=0;
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

	ob.sumtree(root,&size);
	ob.print(root);
}
