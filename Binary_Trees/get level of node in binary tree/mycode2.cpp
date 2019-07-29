#include<iostream>
using namespace std;

struct node
{
	int data;
	struct node *lchild,*rchild;
};

class tree
{
	public:

		int node_level(struct node *,int,int);
};

int tree::node_level(struct node *root,int key,int level)
{
	int pos;
	if(root==NULL)
		return 0;

	if(root->data==key)
		return level;

	pos=node_level(root->lchild,key,level+1);

	if(pos!=0)
		return pos;

	pos=node_level(root->rchild,key,level+1);
            return pos;

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
	cout<<"Enter key"<<endl;
	cin>>key;
	val=ob.node_level(root,key,1);
	cout<<"The level of the given key is "<<val<<endl;
}
