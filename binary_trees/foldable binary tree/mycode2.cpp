#include<iostream>
#include<queue>
using namespace std;

struct node
{
	int data;
	struct node *lchild,*rchild;
};

class tree
{
	public:

		int foldable_trees(struct node *);
		int check_foldable(struct node *,struct node *);
};

int tree::foldable_trees(struct node *root)
{
	if(root==NULL)
		return 1;

	return check_foldable(root->lchild,root->rchild);
}

int tree::check_foldable(struct node *root1,struct node *root2)
{
	if(root1==NULL&&root2==NULL)
		return 1;

	if(root1==NULL||root2==NULL)
		return 0;

	if(check_foldable(root1->lchild,root2->rchild)&&check_foldable(root1->rchild,root2->lchild))
		return 1;
	else
		return 0;
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
	if(ob.foldable_trees(root))
		cout<<"trees are foldable"<<endl;
	else
		cout<<"trees are not foldable"<<endl;
}
