#include<iostream>
#include<stack>
using namespace std;

struct node
{
	int data;
	struct node *lchild,*rchild;
};

class tree
{
	public:

		void IterativePostorder(struct node *);
};

void tree::IterativePostorder(struct node *root)
{
	stack<struct node *>s1,s2;
	struct node *ptr;
	s1.push(root);
	while(!s1.empty())
	{
		ptr=s1.top();
		s1.pop();
		if(ptr->lchild)
			s1.push(ptr->lchild);

		if(ptr->rchild)
			s1.push(ptr->rchild);

		s2.push(ptr);
	}
	while(!s2.empty())
	{
		ptr=s2.top();
		s2.pop();
		cout<<ptr->data<<" ";
	}
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
	int i,val,tree_IterativePostorder;
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
	ob.IterativePostorder(root);
}

