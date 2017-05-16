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

		void level_order(struct node *);
};

void tree::level_order(struct node *root)
{
	int count;
	queue<struct node *> q;
	struct node *ptr;
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
			ptr=q.front();
			cout<<ptr->data<<" ";
			q.pop();
			if(ptr->lchild)
				q.push(ptr->lchild);
			if(ptr->rchild)
				q.push(ptr->rchild);
			count--;
		}
		cout<<endl;
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
	ob.level_order(root);
}
