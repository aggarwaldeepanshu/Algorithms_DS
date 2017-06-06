#include<iostream>
#include<climits>
using namespace std;

struct node
{
	int data;
	struct node *lchild,*rchild;
};

class tree
{
	public:

		int CheckHeight(struct node *);
		int CheckHeightRecur(struct node *,int *,int *,int *);
};

int tree::CheckHeight(struct node *root)
{
	int min=INT_MAX,max=INT_MIN;
	int flag=1;
	CheckHeightRecur(root,&min,&max,&flag);

	return flag;
}

int tree::CheckHeightRecur(struct node *root,int *min,int *max,int *flag)
{

	int l=0,r=0,a=0;
	if(root==NULL)
		return 1;

	l=CheckHeightRecur(root->lchild,min,max,flag);
	r=CheckHeightRecur(root->rchild,min,max,flag);

	if(l>=r)
	{
		*max=l;
		*min=r;
	}
	else
	{
		*max=r;
		*min=l;
	}
	if(*min==0 && *max>2)
		*flag=0;

	if(*min!=0 && *max>2*(*min))
		*flag=0;

	if(l>=r)
		return 1+l;
	else 
		return 1+r;

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
	if(ob.CheckHeight(root))
		cout<<"Balanced"<<endl;
	else
		cout<<"Unbalanced"<<endl;
}
