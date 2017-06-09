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

		void FindSum(struct node *,int *);
};

int isleaf(struct node *root)
{
	if(root==NULL)
		return 0;

	if(root->lchild==NULL && root->rchild==NULL)
		return 1;
	else
		return 0;
}

void tree::FindSum(struct node *root,int *sum)
{
	if(root==NULL)
		return ;

	if(isleaf(root->lchild))
		*sum+=root->lchild->data;

	FindSum(root->lchild,sum);
	FindSum(root->rchild,sum);

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
	int i,val,sum=0;
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
	ob.FindSum(root,&sum);
	cout<<"sum of leaves is "<<sum<<endl;
}
