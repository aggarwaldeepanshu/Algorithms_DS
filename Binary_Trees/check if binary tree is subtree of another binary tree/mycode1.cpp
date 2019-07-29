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

		int subtree(struct node *,struct node *);
};

int compare(struct node *root1,struct node *root2)
{
	if((root1==NULL&&root2==NULL)||(root1!=NULL&&root2==NULL))
		return 1;

	if(root1==NULL&&root2!=NULL)
		return 0;

	if(compare(root1->lchild,root2->lchild)&&compare(root1->rchild,root2->rchild))
	{
		if(root1->data==root2->data)
			return 1;
		else
			return 0;
	}
	return 0;
}

int tree::subtree(struct node *root1,struct node *root2)
{
	int a=0;
	if((root1==NULL&&root2==NULL)||(root1!=NULL&&root2==NULL))
		return 1;

	if(root1==NULL&&root2!=NULL)
		return 0;

	if(root1->data==root2->data)
	     return compare(root1,root2);

	a=a||subtree(root1->lchild,root2);
	a=a||subtree(root1->rchild,root2);

	return a;
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
	else if(val<=root->data)
		root->lchild=insert(root->lchild,val);
	else
		root->rchild=insert(root->rchild,val);

	return root;
}

int main(void)
{
	int i,val,height=0;
	struct node *root1,*root2;
	root1=NULL;
	root2=NULL;
	tree ob;
	cout<<"Enter -1 to exit"<<endl;
        cout<<"Enter the values for first tree"<<endl;
	cin>>val;
	while(val!=-1)
	{
		root1=insert(root1,val);
		cin>>val;
	}
	cout<<"Enter the values for second tree"<<endl;
	cin>>val;
	while(val!=-1)
	{
		root2=insert(root2,val);
		cin>>val;
	}
	if(ob.subtree(root1,root2))
		cout<<"Tree is subtree"<<endl;
	else
		cout<<"Tree is not subtree"<<endl;
}
