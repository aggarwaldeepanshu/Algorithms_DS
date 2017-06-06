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

		struct node *ConstructTree(int [],int [],int,int,int);
};

int find(int in[],int low,int high,int key)
{
	int i;
	for(i=low;i<high;i++)
	{
		if(in[i]==key)
			return i;

	}
	return -1;
}

int *shift(int in[],int level[],int high,int size)
{
	int i,j=0;
	int *arr=new int[high];
	for(i=0;i<size;i++)
	{
		if(find(in,0,high,level[i])!=-1)
		{
			arr[j]=level[i];
			j++;
		}
	}
	return arr;
}

struct node *new_node(int key)
{
	struct node *root=new struct node;
	root->data=key;
	root->lchild=NULL;
	root->rchild=NULL;
	return root;
}

struct node *tree::ConstructTree(int in[],int level[],int low,int high,int n)
{
	int j;
	if(low>high)
		return NULL;

	struct node *root=new_node(level[0]);

	if(low==high)
		return root;

	j=find(in,low,high,root->data);

	int *left=shift(in,level,j,n);
	int *right=shift(in+j+1,level,n-j-1,n);

	root->lchild=ConstructTree(in,left,low,j-1,n);
	root->rchild=ConstructTree(in,right,j+1,high,n);

	return root;
}

void preorder(struct node *root)
{
	if(root==NULL)
		return ;

	preorder(root->lchild);
	cout<<root->data<<" ";
	preorder(root->rchild);
}

int main(void)
{
	tree ob;
	struct node *root;
	int n,i;
	cout<<"Enter the size of tree"<<endl;
	cin>>n;
	int level[n],in[n];

	cout<<"Enter the values for level order"<<endl;
	for(i=0;i<n;i++)
		cin>>level[i];

	cout<<"Enter the values for inorder"<<endl;
	for(i=0;i<n;i++)
		cin>>in[i];

	root=ob.ConstructTree(in,level,0,n-1,n);
	cout<<"The required tree is"<<endl;
	preorder(root);
}
