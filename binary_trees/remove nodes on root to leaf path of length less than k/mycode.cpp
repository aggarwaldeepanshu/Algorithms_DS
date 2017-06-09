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

		struct node *RemoveNodes(struct node *,int,int);
		void inorder(struct node *);
};

struct node *tree::RemoveNodes(struct node *root,int length,int k)
{
	if(root==NULL)
		return NULL;

	root->lchild=RemoveNodes(root->lchild,length+1,k);
	root->rchild=RemoveNodes(root->rchild,length+1,k);

	//cout<<root->data<<" "<<length<<endl;
	if(!root->lchild && !root->rchild)
	{
		if(length<k)
		{
			delete root;
			return NULL;
		}
		//return root;
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
	int i,val,k;
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
	cout<<"enter k"<<endl;
	cin>>k;
	ob.RemoveNodes(root,1,k);
	ob.inorder(root);
}
