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

		void inorder(struct node *);
};

void tree::inorder(struct node *root)
{
	struct node *curr;
	stack<struct node *> s;
	s.push(root);
	curr=root;
	while(!s.empty())
	{
		while(curr!=NULL)
		{
			s.push(curr);
			curr=curr->lchild;
		}
		if(!s.empty()&&curr==NULL)
		{
			curr=s.top();
				s.pop();
			cout<<curr->data<<" ";
			curr=curr->rchild;
		}
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
	ob.inorder(root);
}
