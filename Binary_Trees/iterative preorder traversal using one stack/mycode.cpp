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
	if(root==NULL)
		return ;

	stack<struct node *>s;
	struct node *ptr;

	ptr=root;
	do
	{

		while(ptr)
		{
			if(ptr->rchild)
				s.push(ptr->rchild);

			s.push(ptr);
			ptr=ptr->lchild;
		}

		if(!s.empty()&&ptr==NULL)
		{
			ptr=s.top();
			s.pop();

			if(ptr->rchild&&s.size()>0&&s.top()==ptr->rchild)
			{
				s.pop();
				s.push(ptr);
				ptr=ptr->rchild;
			}
			else
			{
				cout<<ptr->data<<" ";
				ptr=NULL;
			}
		}
	}while(!s.empty());
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

