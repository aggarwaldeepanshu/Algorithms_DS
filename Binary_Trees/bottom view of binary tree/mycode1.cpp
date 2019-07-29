//To print all bottommost nodes at horizontal distance if multiple bottommost nodes exist

#include<iostream>
using namespace std;

struct node
{
	int data;
	struct node *lchild,*rchild,*down;
};

class tree
{
	public:

		void BottomView(struct node *,int *,int);
};

void tree::BottomView(struct node *root,int *level,int k)
{
	if(root==NULL)
		return ;

	if(root->lchild==NULL && root->rchild==NULL)
	{

		if(*level==-1)
		{
			*level=k;
		}
		if(*level==k)
			cout<<root->data<<" ";

		return ;
	}


	BottomView(root->lchild,level,k+1);
	BottomView(root->rchild,level,k+1);

	if(*level==k)
	{
		cout<<root->data<<" ";
		if(root->lchild)
			cout<<root->lchild->data<<" ";

		if(root->rchild)
			cout<<root->rchild->data<<" ";
	}
	return ;
}

struct node *new_node(int val)
{
	struct node *ptr=new node;
	ptr->data=val;
	ptr->lchild=NULL;
	ptr->rchild=NULL;
	ptr->down=NULL;
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
	int i,val,level=-1;
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
	ob.BottomView(root,&level,0);
}
