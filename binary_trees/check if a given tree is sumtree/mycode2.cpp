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

		int sumtree(struct node *,int *);
};

int tree::sumtree(struct node *root,int *sum)
{
	int lsum=0,rsum=0,l=0,r=0;
	if(root==NULL)
	{
		*sum=0;
		return 0;
	}
	l=sumtree(root->lchild,&lsum);
	r=sumtree(root->rchild,&rsum);

	if(root->lchild==NULL&&root->rchild==NULL)
		*sum=root->data;

	else
		*sum=lsum+rsum+root->data;

	if((root->lchild||root->rchild)&&(root->data==lsum+rsum))
		return 1;

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
	int i,val,sum=0;
	struct node *root;
	root=NULL;
	tree ob;
	root=new_node(26);
	root->lchild         = new_node(10);
	root->rchild        = new_node(3);
	root->lchild->lchild   = new_node(4);
	root->lchild->rchild  = new_node(6);
	root->rchild->rchild = new_node(3);

	if(ob.sumtree(root,&sum))
		cout<<"tree is sumtree"<<endl;
	else
		cout<<"it is not sumtree"<<endl;
}
