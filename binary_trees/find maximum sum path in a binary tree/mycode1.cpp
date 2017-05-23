#include<iostream>
using namespace std;

#define large 1000

struct node
{
	int data;
	struct node *lchild,*rchild;
};

int path[large];
int length=0;

class tree
{
	public:

		void MaxSum(struct node *);
		void display(int);
};

void tree::display(int max)
{
	cout<<"Maximum sum is "<<max<<endl;
	cout<<"The path is"<<endl;
	for(int i=0;i<length;i++)
		cout<<path[i]<<" ";
}

void MaxPath(int arr[],int size)
{
	for(int i=0;i<size;i++)
		path[i]=arr[i];
	length=size;
}

void MaxSumRecur(struct node *root,int arr[],int size,int sum,int *max)
{
	if(root==NULL)
		return ;

	arr[size++]=root->data;
	sum+=root->data;

	if(root->lchild==NULL&&root->rchild==NULL)
	{
		if(sum>*max)
		{
			MaxPath(arr,size);
			*max=sum;
		}
	}
	else
	{
		MaxSumRecur(root->lchild,arr,size,sum,max);
		MaxSumRecur(root->rchild,arr,size,sum,max);
	}
}

void tree::MaxSum(struct node *root)
{
	int arr[large],size=0,max=-1,sum=0;
	MaxSumRecur(root,arr,size,sum,&max);
	display(max);
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

	ob.MaxSum(root);
}
