#include<iostream>
#include<queue>
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

void tree::connect_nodes(struct node *root)
{
	int count;
	queue<struct node *> q;
	struct node *ptr1=NULL,*ptr2=NULL;
	if(root==NULL)
	{
		cout<<"Tree is empty"<<endl;
		return;
	}
	q.push(root);
	while(1)
	{
		count=q.size();
		if(count==0)
			break;

		while(count>0)
		{
			ptr1=q.front();
			q.pop();
			count--;
			if(count>0)
			{
				ptr2=q.front();
				ptr1->right=ptr2;
			}
			if(ptr1->lchild)
				q.push(ptr1->lchild);
			if(ptr1->rchild)
				q.push(ptr1->rchild);
		}
		ptr1->right=NULL;
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
