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

		void RoottoLeafSum(struct node *,int,int *);
};

void tree::RoottoLeafSum(struct node *root,int num,int *sum)
{
	if(root==NULL)
		return;

	num=num*10+root->data;

	if(!root->lchild && !root->rchild)
	{
		*sum+=num;
		return;
	}

	RoottoLeafSum(root->lchild,num,sum);
	RoottoLeafSum(root->rchild,num,sum);
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
	int i,val,num=0,sum=0;
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
	ob.RoottoLeafSum(root,num,&sum);
	cout<<sum<<endl;
}
