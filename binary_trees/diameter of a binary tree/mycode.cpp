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

		int diameter(struct node *,int *);
};

int max(int a,int b)
{
	return (a>b)?a:b;
}

int tree::diameter(struct node *root,int *height)
{
	int lheight=0,rheight=0,ldiameter=0,rdiameter=0,count;
	if(root==NULL)
	{
		*height=0;
		return 0;
	}

	ldiameter=diameter(root->lchild,&lheight);
	rdiameter=diameter(root->rchild,&rheight);
	if(lheight>=rheight)
		*height=lheight+1;
	else
		*height=rheight+1;

	return max(1+lheight+rheight,max(ldiameter,rdiameter));
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
	int i,val,height=0,count;
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
	count=ob.diameter(root,&height);
	cout<<"Diameter of tree is "<<count<<endl;
}
