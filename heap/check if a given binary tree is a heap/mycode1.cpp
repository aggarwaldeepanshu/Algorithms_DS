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

		int CountNodes(struct node *);
		int CheckifHeap(struct node *,int,int);
};

int tree::CountNodes(struct node *root)
{
	if(root==NULL)
		return 0;

	return (1+CountNodes(root->lchild)+CountNodes(root->rchild));
}

int isHeap(struct node *root)
{
	if(!root->lchild && !root->rchild)
		return 1;

	if(!root->rchild)
		return (root->data<=root->lchild->data);

	else if(root->data<=root->lchild->data && root->data<=root->rchild->data)
		return 1;
	else
		return 0;
}

int CheckifComplete(struct node *root,int count,int index)
{
	if(root==NULL)
		return 1;

	if(index>=count)
		return 0;

	return (CheckifComplete(root->lchild,count,2*index+1) && CheckifComplete(root->rchild,count,2*index+2));
}

int tree::CheckifHeap(struct node *root,int count,int index)
{
	if(CheckifComplete(root,count,index) && isHeap(root))
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

int main(void)
{
	int i,val,count;
	struct node *root;
	root=NULL;
	tree ob;

	root = new_node(10);
	root->lchild = new_node(9);
	root->rchild = new_node(8);
	root->lchild->lchild = new_node(7);
	root->lchild->rchild = new_node(6);
	root->rchild->lchild = new_node(5);
	root->rchild->rchild = new_node(4);
	root->lchild->lchild->lchild = new_node(3);
	root->lchild->lchild->rchild = new_node(2);
	root->lchild->rchild->lchild = new_node(1);
	count=ob.CountNodes(root);

	if(ob.CheckifHeap(root,count,0))
		cout<<"True"<<endl;
	else
		cout<<"False"<<endl;
}
