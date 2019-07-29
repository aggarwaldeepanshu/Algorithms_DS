#include<iostream>
#define max 1000
using namespace std;

struct node
{
	int data;
	struct node *lchild,*rchild;
};

class tree
{
	public:

		void PrintNode(struct node *,int);
		void PrintNodeRecur(struct node *,int,int [],bool [],int);
};

void tree::PrintNode(struct node *root,int k)
{
	int arr[max],size=0;
	bool visited[max];
	PrintNodeRecur(root,k,arr,visited,size);

}

void tree::PrintNodeRecur(struct node *root,int k,int arr[],bool visited[],int size)
{

	if(root==NULL)
		return ;

	arr[size]=root->data;
	visited[size]=false;
	size++;
	if(!root->lchild && !root->rchild)
	{
		if(size-k-1>=0&&visited[size-k-1]==false)
		{
			cout<<arr[size-k-1]<<" ";
			visited[size-k-1]=true;
		}
	}
	PrintNodeRecur(root->lchild,k,arr,visited,size);
	PrintNodeRecur(root->rchild,k,arr,visited,size);
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
	int i,val,k;
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
	cout<<"Enter k"<<endl;
	cin>>k;
	ob.PrintNode(root,k);
}
