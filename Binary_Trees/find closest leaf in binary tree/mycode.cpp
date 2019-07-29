#include<iostream>
#include<climits>
using namespace std;

struct node
{
	int data;
	struct node *lchild,*rchild;
};

class tree
{
	public:

		int ClosestLeaf(struct node *,int,int *);
};

void FindMin(struct node *root,int *dist,int level)
{
	if(root==NULL)
		return ;

	if(root->lchild==NULL && root->rchild==NULL)
	{
		if(*dist>level)
			*dist=level;

		return ;
	}

	FindMin(root->lchild,dist,level+1);
	FindMin(root->rchild,dist,level+1);

	return ;
}

int tree::ClosestLeaf(struct node *root,int key,int *dist)
{
	int l,r;
	if(root==NULL)
		return -1;

	if(root->data==key)
	{
		FindMin(root,dist,0);
		return 1;
	}
	static int v=0;
	l=ClosestLeaf(root->lchild,key,dist);
	if(l!=-1)
	{
		v++;
		if(root->rchild)
			FindMin(root->rchild,dist,v++);

		return 1;
	}

	r=ClosestLeaf(root->rchild,key,dist);
	if(r!=-1)
	{
		v++;
		if(root->lchild)
			FindMin(root->lchild,dist,v++);

		return 1;
	}

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
	int i,val,key,dist=INT_MAX;
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
	cout<<"enter the key"<<endl;
	cin>>key;
	ob.ClosestLeaf(root,key,&dist);
	cout<<"closet leaf is at distance "<<dist<<endl;
}
