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

		int DeepestLeaf(struct node *,int,int *,int *);
};

int isleaf(struct node *root)
{
	return (root&&root->lchild==NULL&&root->rchild==NULL)?1:0;
}

int tree::DeepestLeaf(struct node *root,int level,int *max,int *key)
{
	int l=0,r=0;
	if(root==NULL)
		return 0;

	if(isleaf(root->lchild))
	{
		if(*max<level+1)
		{
			*key=root->lchild->data;
			*max=level+1;
		}
		return *max;
	}

	l=DeepestLeaf(root->lchild,level+1,max,key);
	r=DeepestLeaf(root->rchild,level+1,max,key);

	return (l>=r)?l:r;
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
	int i,val,level=0,max=-1,key;
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
	val=ob.DeepestLeaf(root,level,&max,&key);
	cout<<"max level is "<<val<<endl;
	cout<<"Deepest leaf node is "<<key<<endl;
}
