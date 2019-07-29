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

		struct node *RemoveNode(struct node *,int,int *);
		void inorder(struct node *);
};

struct node *tree::RemoveNode(struct node *root,int k,int *sum)
{
	int l=0,r=0;
	if(root==NULL)
	{
		*sum=0;
		return NULL;
	}
	*sum=*sum+root->data;
	l=*sum;
	r=*sum;
	root->lchild=RemoveNode(root->lchild,k,&l);
	root->rchild=RemoveNode(root->rchild,k,&r);

	if(*sum<k&&!root->lchild&&!root->rchild)
	{
		delete root;
		root=NULL;
	}
	return root;
}

void tree::inorder(struct node *root)
{
	if(root==NULL)
		return ;

	inorder(root->lchild);
	cout<<root->data<<" ";
	inorder(root->rchild);
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
	int i,val,k,sum=0;
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
	cout<<"Enter K"<<endl;
	cin>>k;
	root=ob.RemoveNode(root,k,&sum);
	ob.inorder(root);
}
