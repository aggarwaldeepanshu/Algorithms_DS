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

		struct node *NextRightNode(struct node *,int);
};

struct node *tree::NextRightNode(struct node *root,int key)
{
	int count,v=1;
	if(root==NULL)
		return 0;

	struct node *ptr=NULL;
	queue<struct node *> q;
	q.push(root);
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

			if(ptr->data==key)
			{
				if(count==0)
				{
					ptr=NULL;
					return ptr;
				}
				else
				{
					ptr=q.front();
					return ptr;
				}
			}

			if(ptr->lchild)
				q.push(ptr->lchild);
			if(ptr->rchild)
				q.push(ptr->rchild);

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
	int i,val,key;
	struct node *root,*ptr;
	root=NULL;
	tree ob;
	cout<<"Enter the values for tree"<<endl<<"Enter -1 to exit"<<endl;
	cin>>val;
	while(val!=-1)
	{
		root=insert(root,val);
		cin>>val;
	}
	cout<<"Enter the key"<<endl;
	cin>>key;
	ptr=ob.NextRightNode(root,key);
	if(ptr==NULL)
		cout<<"NULL"<<endl;
	else
		cout<<ptr->data<<endl;
}
