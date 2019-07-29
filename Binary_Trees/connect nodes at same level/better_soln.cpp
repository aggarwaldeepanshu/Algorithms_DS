//solution with constant extra space

#include<iostream>
using namespace std;

struct node
{
	int data;
	struct node *lchild,*rchild,*right;
};

class tree
{
	public:

		void connect_nodes(struct node *);
		void print(struct node *);
};

struct node *get_right(struct node *root)
{
	struct node *ptr=root->right;
	while(ptr)
	{
		if(ptr->lchild)
			return ptr->lchild;
		else if(ptr->rchild)
			return ptr->rchild;
		ptr=ptr->right;
	}
	return NULL;
}

void tree::connect_nodes(struct node *root)
{
	if(root==NULL)
		return ;

	root->right=NULL;
	struct node *ptr;

	while(root)
	{
		ptr=root;
		while(ptr)
		{
			if(ptr->lchild)
			{
				if(ptr->rchild)
					ptr->lchild->right=ptr->rchild;
				else
					ptr->lchild->right=get_right(ptr);
			}
			if(ptr->rchild)
				ptr->rchild->right=get_right(ptr);

			ptr=ptr->right;
		}
		if(root->lchild)
			root=root->lchild;
		else if(root->rchild)
			root=root->rchild;
		else
			root=get_right(root);
	}
}

void tree::print(struct node *root)
{
	if(root==NULL)
		return ;

	print(root->lchild);

	if(root->right!=NULL)
		cout<<root->data<<" -- "<<root->right->data<<endl;
	else
		cout<<root->data<<" -- "<<-1<<endl;

	print(root->rchild);
}

struct node *new_node(int val)
{
	struct node *ptr=new node;
	ptr->data=val;
	ptr->lchild=NULL;
	ptr->rchild=NULL;
	ptr->right=NULL;
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
	ob.connect_nodes(root);
	cout<<"Root Data  --  Root's Next Right Data"<<endl<<endl;
	ob.print(root);
}
