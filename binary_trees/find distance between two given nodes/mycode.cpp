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

		int FindDistance(struct node *,int,int);
		struct node *FindDistanceRecur(struct node *,int,int,int *,int *,int *,int);
};

int find_node(struct node *root,int val,int level)
{
	int l,r;
	if(root==NULL)
		return -1;

	if(root->data==val)
		return level;

	l=find_node(root->lchild,val,level+1);
	r=find_node(root->rchild,val,level+1);

	if(l==-1)
		return r;
	else
		return l;
}

int tree::FindDistance(struct node *root,int n1,int n2)
{
	int l=-1,r=-1,dist=0,level=1;
	struct node *ptr;
	ptr=FindDistanceRecur(root,n1,n2,&l,&r,&dist,level);
	if(l!=-1 && r!=-1)
		return dist;

	else if(l!=-1)
	{
		dist=find_node(ptr,n2,0);
		return dist;
	}
	else
	{
		dist=find_node(ptr,n1,0);
		return dist;
	}
}

struct node *tree::FindDistanceRecur(struct node *root,int n1,int n2,int *l,int *r,int *dist,int level)
{
	struct node *left=NULL,*right=NULL;

	if(root==NULL)
		return NULL;

	if(root->data==n1||root->data==n2)
	{
		if(root->data==n1)
		{
			*l=level;
			return root;
		}
		if(root->data==n2)
		{
			*r=level;
			return root;
		}
	}
	left=FindDistanceRecur(root->lchild,n1,n2,l,r,dist,level+1);
	right=FindDistanceRecur(root->rchild,n1,n2,l,r,dist,level+1);
	if(left && right)
	{
		*dist=*l+*r-2*level;
		return root;
	}
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
	int i,val,n1,n2,dist;
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
	cout<<"Enter the two values"<<endl;
	cin>>n1>>n2;
	dist=ob.FindDistance(root,n1,n2);
	cout<<dist<<endl;
}
