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

		int height(struct node *);
};

int tree::height(struct node *root)
{
	int count=0,height=0;
	struct node *ptr;
	queue<struct node *> q;
	q.push(root);
	while(1)
	{
		count=q.size();
		if(count==0)
			break;

		height+=1;
		while(count>0)
		{
			ptr=q.front();
			q.pop();
			if(ptr->lchild)
				q.push(ptr->lchild);
			if(ptr->rchild)
				q.push(ptr->rchild);
			count--;
		}
	}
	return height;
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
	int i,val,tree_height;
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
	tree_height=ob.height(root);
	cout<<"Height of tree is "<<tree_height<<endl;
}
