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
		void inorder(struct node *);
		struct node *ParentArray(int [],int,struct node **);
};

struct node *new_node(int val)
{
	struct node *ptr=new node;
	ptr->data=val;
	ptr->lchild=NULL;
	ptr->rchild=NULL;
	return ptr;
}

void ConstructTree(int arr[],int key,struct node *visited[],struct node **root)
{
	struct node *ptr;
	if(visited[key]!=NULL)
		return ;

	visited[key]=new_node(key);

	if(arr[key]==-1)
	{
		*root=visited[key];
		return ;
	}

	if(visited[arr[key]]==NULL)
		ConstructTree(arr,arr[key],visited,root);

	ptr=visited[arr[key]];

	if(!ptr->lchild)
		ptr->lchild=visited[key];

	else
		ptr->rchild=visited[key];
}

struct node *tree::ParentArray(int arr[],int size,struct node **root)
{
	int i;
	struct node *visited[size];
	for(i=0;i<size;i++)
		visited[i]=NULL;

	for(i=0;i<size;i++)
		ConstructTree(arr,i,visited,root);

	return *root;
}

void tree::inorder(struct node *root)
{
	if(root==NULL)
		return ;

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
	cout<<"enter size of array"<<endl;
	cin>>size;
	int arr[size];
	cout<<"enter the values"<<endl;
	for(int i=0;i<size;i++)
		cin>>arr[i];

	root=ob.ParentArray(arr,size,&root);
	ob.inorder(root);
}
