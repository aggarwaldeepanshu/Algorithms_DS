#include<iostream>
using namespace std;

#define large 1000

struct node
{
	int data;
	struct node *lchild,*rchild;
};

class tree
{
	public:

		struct node *construct_tree(int [],int,int);
};

struct node *new_node(int val)
{
	struct node *ptr=new node;
	ptr->data=val;
	ptr->lchild=NULL;
	ptr->rchild=NULL;
	return ptr;
}

int find_max(int arr[],int low,int high)
{
	int max=low;
	for(int i=low+1;i<=high;i++)
	{
		if(arr[max]<arr[i])
			max=i;
	}
	return max;
}

struct node *tree::construct_tree(int arr[],int low,int high)
{
	int val;
	if(low>high)
		return NULL;

	val=find_max(arr,low,high);

	struct node *root=new_node(arr[val]);

	if(low==high)
		return root;

	root->lchild=construct_tree(arr,low,val-1);
	root->rchild=construct_tree(arr,val+1,high);

	return root;
}

void preorder(struct node *root)
{
	if(root==NULL)
		return;

	cout<<root->data<<" ";
	preorder(root->lchild);
	preorder(root->rchild);
}


int main(void)
{
	int i,val,size;
	struct node *root;
	root=NULL;
	tree ob;
	cout<<"Enter the size"<<endl;
	cin>>size;
	int arr[size];
	cout<<"Enter the inorder traversal"<<endl;
	for(int i=0;i<size;i++)
		cin>>arr[i];

	root=ob.construct_tree(arr,0,size-1);
	cout<<"The preorder traversal of special tree is"<<endl;
	preorder(root);
}
