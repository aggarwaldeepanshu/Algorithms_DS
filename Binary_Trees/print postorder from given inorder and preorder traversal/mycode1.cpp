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
		void create_tree(int [],int [],int,int);
		int find(int [],int,int,int);
		struct node *new_node(int);
};

void tree::create_tree(int in[],int pre[],int low,int high)
{
	static int i=0;
	int j,key;
	if(low>high)
		return ;

	key=pre[i++];

	if(low==high)
	{
		cout<<in[high]<<" ";
		return ;
	}
	j=find(in,low,high,key);

	create_tree(in,pre,low,j-1);
	create_tree(in,pre,j+1,high);

	cout<<in[j]<<" ";
	return;
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

	ob.create_tree(in,pre,0,n-1);
}
