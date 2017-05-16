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

		int identical(struct node *,struct node *);
};

int tree::identical(struct node *root1,struct node *root2)
{
	if(root1==NULL&&root2==NULL)
		return 1;

	if(root1!=NULL&&root2!=NULL)
	{
		if(root1->data==root2->data)
		{
			return identical(root1->lchild,root2->lchild)&&identical(root1->rchild,root2->rchild);
		}
		else
			return 0;
	}
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
	int i,val,size;
	struct node *root1,*root2;
	root1=NULL;
	root2=NULL;
	tree ob;
	cout<<"Enter the values for first tree"<<endl<<"Enter -1 to exit"<<endl;
	cin>>val;
	while(val!=-1)
	{
		root1=insert(root1,val);
		cin>>val;
	}
	cout<<"Enter the values for second tree"<<endl;
	cin>>val;
	while(val!=-1)
	{
		root2=insert(root2,val);
		cin>>val;
	}
	if(ob.identical(root1,root2)==1)
		cout<<"Trees are identical"<<endl;
	else if(ob.identical(root1,root2)==0)
		cout<<"Trees are not identical"<<endl;
}
