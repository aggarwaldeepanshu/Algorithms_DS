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

		void MaxSum(struct node *);
		int display(struct node *,struct node *);
};

int tree::display(struct node *root,struct node *leaf)
{
	if(root==NULL)
		return 0;

	if((root->data==leaf->data)||display(root->lchild,leaf)||display(root->rchild,leaf))
	{
		cout<<root->data<<" ";
		return 1;
	}
	else
		return 0;
}

void MaxSumRecur(struct node *root,int sum,int *max,struct node **leaf)
{
	if(root==NULL)
		return ;

	sum+=root->data;

	if(root->lchild==NULL&&root->rchild==NULL)
	{
		if(sum>*max)
		{
			*leaf=root;
			*max=sum;
		}
	}
	else
	{
		MaxSumRecur(root->lchild,sum,max,leaf);
		MaxSumRecur(root->rchild,sum,max,leaf);
	}
}

void tree::MaxSum(struct node *root)
{
	struct node *leaf;
	int max=-1,sum=0;
	MaxSumRecur(root,sum,&max,&leaf);
	display(root,leaf);
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
	int i,val;
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

	ob.MaxSum(root);
}
