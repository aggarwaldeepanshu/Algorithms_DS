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

		struct node *FormTree(int [],int [],int,int,int);
};

int find(int post[],int low,int high,int key)
{
	for(int i=low;i<=high;i++)
	{
		if(post[i]==key)
			return i;
	}
	return -1;
}

struct node *new_node(int val)
{
	struct node *ptr=new node;
	ptr->data=val;
	ptr->lchild=NULL;
	ptr->rchild=NULL;
	return ptr;
}

struct node *tree::FormTree(int pre[],int post[],int low,int high,int size)
{
	int index;
	static int i=0;
	if(i>size||low>high)
		return NULL;

	struct node *root=new_node(pre[i]);
	if(i<size)
		i++;
	if(i==size)
		return root;

	if(low==high)
		return root;

	index=find(post,low,high,pre[i]);

	if(index>high||index==-1)
		return root;
	root->lchild=FormTree(pre,post,low,index,size);
	root->rchild=FormTree(pre,post,index+1,high,size);

	return root;

}

void inorder(struct node *root)
{
	if(root==NULL)
		return ;
	inorder(root->lchild);
	cout<<root->data<<" ";
	inorder(root->rchild);
}


int main(void)
{
	int i,size;
	struct node *root;
	root=NULL;
	tree ob;
	cout<<"Enter the size"<<endl;
	cin>>size;

	int pre[size],post[size];

	cout<<"Enter the preorder traversal"<<endl;
	for(i=0;i<size;i++)
		cin>>pre[i];

	cout<<"Enter the postorder traversal"<<endl;
	for(i=0;i<size;i++)
		cin>>post[i];


	root=ob.FormTree(pre,post,0,size-1,size);
	cout<<"The inorder traversal of tree is"<<endl;
	inorder(root);
}
