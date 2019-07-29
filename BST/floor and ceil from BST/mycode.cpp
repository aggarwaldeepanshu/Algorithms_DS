#include<iostream>
using namespace std;

struct node
{
	int data;
	struct node *left,*right;
};

class BST
{
	public:
		struct node *insert(struct node *,int);

		int find_ceil(struct node *,int);
};

struct node *new_node(int key)
{
	struct node *root=new struct node ;
	root->data=key;
	root->left=root->right=NULL;

	return root;
}

struct node * BST::insert(struct node *root,int key)
{
	if(root==NULL)
		return new_node(key);

	else if(root->data > key)
		root->left=insert(root->left,key);

	else
		root->right=insert(root->right,key);

	return root;
}

int BST::find_ceil(struct node *root,int key)
{
	int val;
	if(root==NULL)
		return -1;

	if(root->data == key)
		return root->data;

	else if(root->data < key)
		return find_ceil(root->right,key);

	else
	{
		int data=find_ceil(root->left,key);
		return (data >= key)?data:root->data;
	}

}

int main(void)
{
	int val,key;
	struct node *root;
	root=NULL;

	BST ob;
	cout<<"enter the values"<<endl;
	cout<<"enter -1 to exit"<<endl;

	cin>>val;
	while(val!=-1)
	{
		root=ob.insert(root,val);
		cin>>val;
	}
	cout<<"enter the key"<<endl;
	cin>>key;

	int ans=ob.find_ceil(root,key);
	if(ans==-1)
		cout<<"no ceil"<<endl;
	else
		cout<<"ans is "<<ans<<endl;
}
