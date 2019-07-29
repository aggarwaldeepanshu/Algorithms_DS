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

		struct node *RemoveLeaves(struct node *);
		void ExtractLeaves(struct node *,struct node **,struct node **);
};

struct node *new_node(int val)
{
	struct node *ptr=new node;
	ptr->data=val;
	ptr->lchild=NULL;
	ptr->rchild=NULL;
	return ptr;
}

struct node *tree::RemoveLeaves(struct node *root)
{
	if(root==NULL)
		return NULL;
	if(root->data==-1)
	{
		delete root;
		return NULL;
	}
	root->lchild=RemoveLeaves(root->lchild);
	root->rchild=RemoveLeaves(root->rchild);
}

void tree::ExtractLeaves(struct node *root,struct node **start,struct node **ptr)
{
	if(root==NULL)
		return;

	struct node *temp;
	ExtractLeaves(root->lchild,start,ptr);
	ExtractLeaves(root->rchild,start,ptr);

	if(!root->lchild && !root->rchild)
	{
		if(*start==NULL)
		{
			*ptr=new_node(root->data);
			*start=*ptr;
		}
		else
		{
			temp=new_node(root->data);
			(*ptr)->rchild=temp;
			temp->lchild=*ptr;
			*ptr=temp;
		}

		root->data=-1;
	}
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

void PrintDLL(struct node *start)
{
	struct node *ptr;
	ptr=start;
	while(ptr)
	{
		cout<<ptr->data<<" ";
		ptr=ptr->rchild;
	}
}

void inorder(struct node *root)
{
	if(root==NULL)
		return;

	inorder(root->lchild);
	cout<<root->data<<" ";
	inorder(root->rchild);
}

int main(void)
{
	int i,val,tree_ExtractLeaves;
	struct node *root,*start,*ptr;
	root=NULL;
	start=NULL;
	ptr=NULL;
	tree ob;
	cout<<"Enter the values for tree"<<endl<<"Enter -1 to exit"<<endl;
	cin>>val;
	while(val!=-1)
	{
		root=insert(root,val);
		cin>>val;
	}
	ob.ExtractLeaves(root,&start,&ptr);
	root=ob.RemoveLeaves(root);
	inorder(root);
	cout<<endl;
	PrintDLL(start);
}
