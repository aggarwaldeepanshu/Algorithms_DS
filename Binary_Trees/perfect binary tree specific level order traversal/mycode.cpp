#include<iostream>
#include<queue>
using namespace std;

struct node
{
	int data;
	struct node *lchild,*rchild;
};

class tree
{
	public:

		void SpecificTraversal(struct node *);
};

void tree::SpecificTraversal(struct node *root)
{
	int count;

	if(root==NULL)
		return ;

	struct node *ptr,*ptr1;

	queue<struct node *> q;

	cout<<root->data<<" ";

	if(root->lchild)
		q.push(root->lchild);

	if(root->rchild)
		q.push(root->rchild);

	while(1)
	{
		count=q.size();

		if(count==0)
			break;

		while(count>0)
		{
			ptr=q.front();
			q.pop();
			count--;

			ptr1=q.front();
			q.pop();
			count--;

			cout<<ptr->data<<" "<<ptr1->data<<" ";

			if(ptr->lchild)
				q.push(ptr->lchild);

			if(ptr1->rchild)
				q.push(ptr1->rchild);

			if(ptr->rchild)
				q.push(ptr->rchild);

			if(ptr1->lchild)
				q.push(ptr1->lchild);
		}
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
	ob.SpecificTraversal(root);
}
