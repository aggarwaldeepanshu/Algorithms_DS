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

		void VerticalOrder(struct node *);
};

void PrintVerticalOrder(struct node *root,struct node *ptr)
{
	root->down=ptr->down;
	ptr->down=root;
	if(root->lchild)
	{
		if(ptr->lchild==NULL)
		{
			struct node *ptr1=new struct node;
			ptr1->data=0;
			ptr1->lchild=NULL;
			ptr1->rchild=ptr;
			ptr->lchild=ptr1;
			ptr1->down=NULL;
		}
		PrintVerticalOrder(root->lchild,ptr->lchild);
	}

	if(root->rchild)
	{
		if(ptr->rchild==NULL)
		{
			struct node *ptr1=new struct node;
			ptr1->data=0;
			ptr1->rchild=NULL;
			ptr1->lchild=ptr;
			ptr->rchild=ptr1;
			ptr1->down=NULL;
		}
		PrintVerticalOrder(root->rchild,ptr->rchild);
	}
}

void tree::VerticalOrder(struct node *root)
{
	if(root==NULL)
		return ;

	struct node *ptr=new struct node;
	ptr->data=0;
	ptr->lchild=NULL;
	ptr->rchild=NULL;
	ptr->down=NULL;

	PrintVerticalOrder(root,ptr);

	while(ptr->lchild!=NULL)
		ptr=ptr->lchild;

	struct node *ptr1;

	while(ptr!=NULL)
	{
		if(ptr->down)
		{
			ptr1=ptr->down;
			while(ptr1)
			{
				cout<<ptr1->data<<" ";
				ptr1=ptr1->down;
			}
		}
                cout<<endl;
		ptr=ptr->rchild;
	}
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
	ob.VerticalOrder(root);
}
