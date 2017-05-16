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

		int leaf_nodes(struct node *);
};

int tree::leaf_nodes(struct node *root)
{
	if(root==NULL)
		return 0;
	if(root->lchild==NULL&&root->rchild==NULL)
		return 1;
	else
		return leaf_nodes(root->lchild)+leaf_nodes(root->rchild);
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
	count=ob.leaf_nodes(root);
	cout<<"Number of leaf nodes are "<<count<<endl;
}
