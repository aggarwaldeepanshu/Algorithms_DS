#include<iostream>
using namespace std;

struct node
{
	int data;
	struct node *lchild,*rchild;
};

struct node1 
{
	int data;
	struct node1 *left,*right;
};

class tree
{
	public:

		void BTtoDLL(struct node *);
};

void push(struct node *root,struct node1 **start,struct node1 **ptr)
{
	struct node1 *ptr1=new struct node1;
	ptr1->data=root->data;
	ptr1->right=NULL;
	if(*start==NULL)
	{
		ptr1->left=NULL;
		*start=ptr1;
		*ptr=ptr1;
		return;
	}
	ptr1->left=*ptr;
	(*ptr)->right=ptr1;
	*ptr=ptr1;
	return;
}

void inorder(struct node *,struct node1 **,struct node1 **);

void tree::BTtoDLL(struct node *root)
{
	struct node1 *start=NULL;
	struct node1 *ptr;
	inorder(root,&start,&ptr);
	ptr=start;
	cout<<"The inorder traversal of tree"<<endl;

	while(ptr->right!=NULL)
	{
		cout<<ptr->data<<" ";
		ptr=ptr->right;
	}
	cout<<ptr->data<<endl;

	cout<<"The reverse inorder traversal of tree"<<endl;
	while(ptr!=NULL)
	{
		cout<<ptr->data<<" ";
		ptr=ptr->left;
	}
}

void inorder(struct node *root,struct node1 **start,struct node1 **ptr)
{
	if(root==NULL)
		return ;

	inorder(root->lchild,start,ptr);
	push(root,start,ptr);
	inorder(root->rchild,start,ptr);
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
	int i,val,tree_BTtoDLL;
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
	ob.BTtoDLL(root);
}

