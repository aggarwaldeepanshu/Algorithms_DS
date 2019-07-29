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

		void mirror(struct node *);
		void inorder(struct node *);
};

void swap(struct node **a,struct node **b)
{
	struct node *temp;
	temp=*a;
	*a=*b;
	*b=temp;
}

void tree::inorder(struct node *root)
{
	if(root==NULL)
		return ;
	inorder(root->lchild);
	cout<<root->data<<" ";
	inorder(root->rchild);
}

void tree::mirror(struct node *root)
{
	if(root==NULL)
		return;

	mirror(root->lchild);
	swap(&root->lchild,&root->rchild);
	mirror(root->lchild);
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
	ob.inorder(root);
	cout<<endl;
	ob.mirror(root);
	cout<<"mirror tree"<<endl;
	ob.inorder(root);
}
