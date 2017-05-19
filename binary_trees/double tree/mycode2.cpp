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

		struct node *double_tree(struct node *);
		void inorder(struct node *);
};

struct node *new_node(int val)
{
	struct node *ptr=new node;
	ptr->data=val;
	ptr->lchild=NULL;
	ptr->rchild=NULL;
	return ptr;
}

struct node *tree::double_tree(struct node *root)
{
	if(root==NULL)
		return NULL;

	double_tree(root->lchild);
	struct node *ptr=new_node(root->data);
	ptr->lchild=root->lchild;
	root->lchild=ptr;
	double_tree(root->rchild);

	return root;
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

void tree::inorder(struct node *root)
{
	if(root==NULL)
		return ;
	cout<<root->data<<" ";
	inorder(root->lchild);
	inorder(root->rchild);
}

int main(void)
{
	int i,val,tree_double_tree;
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
	root=ob.double_tree(root);
	cout<<"The required double tree is"<<endl;
	ob.inorder(root);
}
