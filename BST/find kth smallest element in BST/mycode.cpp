#include<iostream>
using namespace std;

struct node
{
	int data;
	int count;
	struct node *left,*right;
};

class BST
{
	public:
		struct node *insert(struct node *,int);

		int find_smallest_element(struct node *,int);
};

struct node *new_node(int key)
{
	struct node *root=new struct node ;
	root->data=key;
	root->count=0;
	root->left=root->right=NULL;

	return root;
}

struct node * BST::insert(struct node *root,int key)
{
	struct node *temp=new_node(key);

	struct node *ptr=root;
	struct node *parent=NULL;

	while(ptr)
	{
		parent=ptr;

		if(ptr->data > key)
		{
			ptr->count++;
			ptr=ptr->left;
		}

		else
			ptr=ptr->right;
	}

	if(!root)
		root=temp;

	else if(parent->data > key)
		parent->left=temp;

	else
		parent->right=temp;

	return root;
}

int BST::find_smallest_element(struct node *root,int k)
{
	int val;
	if(root==NULL)
		return -1;

	if(root->count+1==k)
		return root->data;

	else if(k > root->count)
		val=find_smallest_element(root->right , k - (root->count + 1) );

	else
		val=find_smallest_element(root->left,k);

	return val;

}

int main(void)
{
	int val,k;
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
	cout<<"enter k"<<endl;
	cin>>k;
	int ans=ob.find_smallest_element(root,k);
	cout<<"kth element is "<<ans<<endl;
}
