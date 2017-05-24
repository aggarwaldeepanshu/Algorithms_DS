#include<iostream>
#define max 1000
using namespace std;

struct node
{
	int data;
	struct node *lchild,*rchild;
};

struct node *arr[max];
int top=-1;

class tree
{
	public:

		void PreorderTraversal(struct node *);
};

int empty()
{
	if(top==-1)
		return 1;
	else
		return 0;
}

void enqueue(struct node *root)
{
	if(root==NULL)
		return;

	top=top+1;
	arr[top]=root;
	return ;
}

struct node *pop()
{
	struct node *ptr;
	if(top==-1)
		return NULL;

	ptr=arr[top];
	top=top-1;
	return ptr;
}

void tree::PreorderTraversal(struct node *root)
{
	struct node *ptr;

	if(root==NULL)
		cout<<"Empty Tree"<<endl;

	enqueue(root);

	while(!empty())
	{
		ptr=pop();
		cout<<ptr->data<<" ";
		if(ptr->rchild)
			enqueue(ptr->rchild);
		if(ptr->lchild)
			enqueue(ptr->lchild);
	}
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
	else if(val<=root->data)
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
	cout<<"The preorder traversal is"<<endl;
	ob.PreorderTraversal(root);
}
