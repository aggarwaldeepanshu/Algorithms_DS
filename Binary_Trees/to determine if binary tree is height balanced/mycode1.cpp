#include<iostream>
#include<cstdlib>
using namespace std;

struct node
{
	int data;
	struct node *lchild,*rchild;
};

class tree
{
	public:

		int balanced(struct node *,int *);
};

int tree::balanced(struct node *root,int *height)
{
	int lheight=0,rheight=0;
	if(root==NULL)
	{
		*height=0;
		return 1;
	}

	balanced(root->lchild,&lheight);
	balanced(root->rchild,&rheight);

	*height=((lheight>rheight)?lheight:rheight)+1;

	if(abs(lheight-rheight)>1)
		return 0;
	else 
		return 1;
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
	int i,val,height=0;
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
	if(ob.balanced(root,&height))
		cout<<"Tree is balanced"<<endl;
	else
		cout<<"Tree is not balanced"<<endl;
}
