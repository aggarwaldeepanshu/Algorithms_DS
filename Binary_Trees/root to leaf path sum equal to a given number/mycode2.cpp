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

		int check_sum(struct node *,int,int);
};

int tree::check_sum(struct node *root,int count,int sum)
{
	int a=0;
	if(root==NULL)
		return (count==sum);

	count+=root->data;
	if(count==sum&&root->lchild==NULL&&root->rchild==NULL)
		return 1;

	a=a||check_sum(root->lchild,count,sum);
	a=a||check_sum(root->rchild,count,sum);

	return a;
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
	int i,val,sum;
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
	cout<<"Enter the sum"<<endl;
	cin>>sum;
	if(ob.check_sum(root,0,sum))
		cout<<"The path with given sum exist"<<endl;
	else
		cout<<"The path does not exist"<<endl;
}
