#include<iostream>
#define max 100
using namespace std;

struct node
{
	int data;
	struct node *lchild,*rchild;
};

class tree
{
	public:

		void Reverse(struct node *);
		void inorder(struct node *);
};

void ReverseLevel(struct node *root,int arr[],int *size,int level)
{
	if(root==NULL)
		return ;

	ReverseLevel(root->lchild,arr,size,level+1);

	if(level%2!=0)
	{
		arr[(*size)++]=root->data;
	}

	ReverseLevel(root->rchild,arr,size,level+1);

	return ;
}

void ReverseArray(int arr[],int size)
{
	int i,j,temp;
	i=0;
	j=size-1;
	while(i<j)
	{
		temp=arr[i];
		arr[i]=arr[j];
		arr[j]=temp;
		i++;
		j--;
	}
}

void ReverseAlternateLevels(struct node *root,int arr[],int size,int level)
{
	static int i=0;
	if(root==NULL)
		return ;

	ReverseAlternateLevels(root->lchild,arr,size,level+1);

	if(level%2!=0)
	{
		root->data=arr[i++];
	}

	ReverseAlternateLevels(root->rchild,arr,size,level+1);

	return ;
}

void tree::Reverse(struct node *root)
{
	int size=0,level=0;
	int arr[max];
	ReverseLevel(root,arr,&size,level);
	ReverseArray(arr,size);
	level=0;
	ReverseAlternateLevels(root,arr,size,level);
}

void tree::inorder(struct node *root)
{
	if(root==NULL)
		return ;

	inorder(root->lchild);
	cout<<root->data<<" ";
	inorder(root->rchild);
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
	int i,val;
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
	ob.Reverse(root);
	cout<<"the tree after reversing levels is"<<endl;
	ob.inorder(root);
}
