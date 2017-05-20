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

		void ancestor(struct node *,int);
};

void print_ancestor(struct node *root,int arr[],int key,int size)
{
	if(root==NULL)
		return ;

	if(root->data==key)
	{
		for(int j=0;j<size;j++)
			cout<<arr[j]<<" ";
		return ;
	}

	arr[size++]=root->data;

	print_ancestor(root->lchild,arr,key,size);
	print_ancestor(root->rchild,arr,key,size);

}

void tree::ancestor(struct node *root,int key)
{
	int arr[max];
        int size=0;
	print_ancestor(root,arr,key,size);
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
	cout<<"Enter the key"<<endl;
	cin>>key;
	ob.ancestor(root,key);
}
