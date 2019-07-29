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

		int CompleteTree(struct node *);
};

int tree::CompleteTree(struct node *root)
{
	int count,v=0;
	queue<struct node *> q;
	struct node *ptr,*ptr1;
	if(root==NULL)
		return 1;

	q.push(root);
	while(!q.empty())
	{
		ptr=q.front();
		q.pop();
		if(!ptr->lchild&&ptr->rchild)
			return 0;

		if(v==1&&ptr->lchild)
			return 0;

		if(!ptr->lchild||!ptr->rchild)
			v=1;

		if(ptr->lchild)
			q.push(ptr->lchild);
		if(ptr->rchild)
			q.push(ptr->rchild);
	}
	return 1;
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
	if(ob.CompleteTree(root))
		cout<<"Complete Binary Tree"<<endl;
	else
		cout<<"Incomplete Binary Tree"<<endl;
}
