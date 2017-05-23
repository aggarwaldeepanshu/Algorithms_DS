#include<iostream>
using namespace std;

struct node
{
	int data;
	struct node *lchild,*rchild,*next;
};

struct node1
{
	int sum;
	struct node1 *prev,*next;
}; 

class tree
{
	public:

		void vertical_sum(struct node *);
};

void VerticalSumRecur(struct node *,struct node1 *);

void tree::vertical_sum(struct node *root)
{
	if(root==NULL)
		return ;

	struct node1 *ptr=new struct node1;
	ptr->sum=0;
	ptr->next=NULL;
	ptr->prev=NULL;
	VerticalSumRecur(root,ptr);

	while(ptr->prev!=NULL)
		ptr=ptr->prev;

	cout<<"The vertical sum are "<<endl;
	while(ptr!=NULL)
	{
		cout<<ptr->sum<<"  ";
		ptr=ptr->next;
	}
}

void VerticalSumRecur(struct node *root,struct node1 *ptr)
{
	ptr->sum+=root->data;
	if(root->lchild)
	{
		if(ptr->prev==NULL)
		{
			struct node1 *ptr1=new struct node1;
			ptr1->sum=0;
			ptr1->prev=NULL;
			ptr1->next=ptr;
			ptr->prev=ptr1;
		}
		VerticalSumRecur(root->lchild,ptr->prev);
	}
	if(root->rchild)
	{
		if(ptr->next==NULL)
		{
			struct node1 *ptr1=new struct node1;
			ptr1->sum=0;
			ptr1->next=NULL;
			ptr1->prev=ptr;
			ptr->next=ptr1;
		}
		VerticalSumRecur(root->rchild,ptr->next);
	}
}

struct node *new_node(int val)
{
	struct node *ptr=new node;
	ptr->data=val;
	ptr->lchild=NULL;
	ptr->rchild=NULL;
	ptr->next=NULL;
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
	cout<<"Enter the values"<<endl<<"Enter -1 to exit"<<endl;
	cin>>val;
	while(val!=-1)
	{
		root=insert(root,val);
		cin>>val;
	}

	ob.vertical_sum(root);
}
