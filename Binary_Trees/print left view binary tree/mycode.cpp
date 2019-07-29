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

		void left_view(struct node *root)
		{
			int max=0,level=1;
			print_left_view(root,level,&max);
		}

		void print_left_view(struct node *root,int level,int *max)
		{
			if(root==NULL)
				return;
			if(level>*max)
			{
				cout<<root->data<<" ";
				*max=level;
			}
			print_left_view(root->lchild,level+1,max);
			print_left_view(root->rchild,level+1,max);
		}

};


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
	int i,val,size;
	struct node *root;
	root=NULL;
	tree ob;
	cout<<"Enter the values"<<endl<<"Enter -1 to exit"<<endl;
	cin>>val;
	while(val!=-1)
	{
		root=insert(root,val);
		cin>>val;
	}
	ob.left_view(root);
}
