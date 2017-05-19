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
		struct node *create_tree(int [],int [],int,int);
		int find(int [],int,int,int);
		struct node *new_node(int);
};

struct node *tree::create_tree(int in[],int pre[],int low,int high)
{
	static int i=0;
	int j;
	if(low>high)
		return NULL;

	struct node *root=new_node(pre[i++]);

	if(low==high)
		return root;

	j=find(in,low,high,root->data);

	root->lchild=create_tree(in,pre,low,j-1);
	root->rchild=create_tree(in,pre,j+1,high);
}

int tree::find(int in[],int low,int high,int key)
{
	int i;
	for(i=low;i<high;i++)
		if(in[i]==key)
			return i;

	i++;
}

struct node *tree::new_node(int key)
{
	struct node *root=new struct node;
	root->data=key;
	root->lchild=NULL;
	root->rchild=NULL;
	return root;
}

void preorder(struct node *root)
{
	if(root==NULL)
		return ;

	cout<<root->data<<" ";
	preorder(root->lchild);
	preorder(root->rchild);
}

int main(void)
{
	tree ob;
	struct node *root;
	int n,i;
	cout<<"Enter the size of tree"<<endl;
	cin>>n;
	int pre[n],in[n];

	cout<<"Enter the values for preorder"<<endl;
	for(i=0;i<n;i++)
		cin>>pre[i];

	cout<<"Enter the values for inorder"<<endl;
	for(i=0;i<n;i++)
		cin>>in[i];

	root=ob.create_tree(in,pre,0,n);
	cout<<"The required tree is"<<endl;
	preorder(root);
}
