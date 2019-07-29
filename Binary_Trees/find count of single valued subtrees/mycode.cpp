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

		int SingleValued(struct node *,int *);
};

int tree::SingleValued(struct node *root,int *count)
{
	int l,r;
	if(root==NULL)
		return 1;

	l=SingleValued(root->lchild,count);
	r=SingleValued(root->rchild,count);

	if(l==0 || r==0)
		return 0;

	if(root->lchild && root->data!=root->lchild->data)
		return 0;

	if(root->rchild && root->data!=root->rchild->data)
		return 0;

	(*count)++;
	return 1;
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
	int i,val,count=0,flag=1,key=-1;
	struct node *root;
	root=NULL;
	tree ob;
	/*cout<<"Enter the values for tree"<<endl<<"Enter -1 to exit"<<endl;
	  cin>>val;
	  while(val!=-1)
	  {
	  root=insert(root,val);
	  cin>>val;
	  }*/
	root=new_node(5);
	root->lchild        = new_node(4);
	root->rchild       = new_node(5);
	root->lchild->lchild  = new_node(4);
	root->lchild->rchild = new_node(4);
	root->rchild->rchild = new_node(5);
	ob.SingleValued(root,&count);
	cout<<"number of subtrees are "<<count<<endl;
}
