#include<iostream>
using namespace std;

struct node
{
	int data;
	struct node *lchild,*rchild,*next;
};

class tree
{
	public:

		void inorder_successor(struct node *);
		void print(struct node *);
};

struct node *find(struct node *root)
{
	while(root->lchild!=NULL)
		root=root->lchild;

	return root;
}

void tree::inorder_successor(struct node *root)
{
	if(root==NULL)
		return ;

	if(root->lchild)
		root->lchild->next=root;

	inorder_successor(root->lchild);

	if(root->rchild)
	{
		root->rchild->next=root->next;
		root->next=find(root->rchild);
	}
	inorder_successor(root->rchild);
}

void tree::print(struct node *root)
{
	if(root==NULL)
		return ;

	print(root->lchild);

	if(root->next!=NULL)
		cout<<root->data<<" -- "<<root->next->data<<endl;
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
	ob.inorder_successor(root);
	cout<<"Root Data  --  Root's Inorder Successor"<<endl<<endl;
	ob.print(root);
}
