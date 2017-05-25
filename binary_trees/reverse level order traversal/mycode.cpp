#include<iostream>
#include<stack>
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

		void ReverseLevelOrder(struct node *);
};

void tree::ReverseLevelOrder(struct node *root)
{
	if(root==NULL)
		return ;

	int count;
	struct node *ptr;
	queue<struct node *>q;
	stack<struct node *>s;
	q.push(root);

	while(!q.empty())
	{
		while(1)
		{
			count=q.size();
			if(count==0)
				break;
			while(count>0)
			{
				ptr=q.front();
				q.pop();
				s.push(ptr);
				if(ptr->rchild)
					q.push(ptr->rchild);
				if(ptr->lchild)
					q.push(ptr->lchild);
				count--;
			}
		}
	}
	cout<<"Reverse Level Order Traversal"<<endl;
	while(!s.empty())
	{
		ptr=s.top();
		cout<<ptr->data<<" ";
		s.pop();
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
	int i,val,tree_ReverseLevelOrder;
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
	ob.ReverseLevelOrder(root);
}

