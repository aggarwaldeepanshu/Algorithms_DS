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

		struct node *construct_tree_preorder(int [],char [],int,int);
};

struct node *new_node(int val)
{
	struct node *ptr=new node;
	ptr->data=val;
	ptr->lchild=NULL;
	ptr->rchild=NULL;
	return ptr;
}

struct node *tree::construct_tree_preorder(int pre[],char preLN[],int low,int high)
{
	static int i=0;
	if(i>high)
		return NULL;

	struct node *root=new_node(pre[i]);

	if(preLN[i]=='N')
	{
		i++;
		root->lchild=construct_tree_preorder(pre,preLN,low,high);
		root->rchild=construct_tree_preorder(pre,preLN,low,high);
		return root;
	}

	else if(preLN[i]=='L')
	{
		i++;
		return root;
	}

}

void inorder(struct node *root)
{
	if(root==NULL)
		return;

	inorder(root->lchild);
	cout<<root->data<<" ";
	inorder(root->rchild);
}

int main(void)
{
	int i,val,size;
	struct node *root;
	root=NULL;
	tree ob;
	cout<<"Enter the size"<<endl;
	cin>>size;
	int pre[size];
	char preLN[size];
	cout<<"Enter the preorder traversal"<<endl;
	for(int i=0;i<size;i++)
		cin>>pre[i];

	cout<<"Enter the values for preLN array"<<endl;
	for(int i=0;i<size;i++)
		cin>>preLN[i];

	root=ob.construct_tree_preorder(pre,preLN,0,size-1);
	cout<<"The inorder traversal of special tree is"<<endl;
	inorder(root);
}
