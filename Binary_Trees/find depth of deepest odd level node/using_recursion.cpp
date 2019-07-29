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

		int find_depth(struct node *);
		int FindDepthRecur(struct node *,int);
};

int max(int a,int b)
{
	return (a>b)?a:b;
}

int tree::FindDepthRecur(struct node *root,int level)
{
	if(root==NULL)
		return 0;

	if(!root->lchild&&!root->rchild&&level%2!=0)
		return level;

	return max(FindDepthRecur(root->lchild,level+1),FindDepthRecur(root->rchild,level+1));
}

int tree::find_depth(struct node *root)
{
	int level=1;
	return FindDepthRecur(root,level);
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
	int i,val,level;
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
	level=ob.find_depth(root);
	cout<<level<<endl;
}
