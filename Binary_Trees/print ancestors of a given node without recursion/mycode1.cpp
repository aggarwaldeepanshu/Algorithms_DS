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

		void print_ancestor(struct node *,int);
};

void tree::print_ancestor(struct node *root,int key)
{
	bool flag=true;
	struct node *ptr;
	if(root==NULL)
		return ;

	stack<struct node *> s;

	do
	{
		while(root)
		{
			if(root->data==key)
			{
				while(!s.empty())
				{
					ptr=s.top();
					cout<<ptr->data<<" ";
					s.pop();
				}
				flag=false;
				break;
			}
			s.push(root);
			root=root->lchild;
		}
		if(!s.empty()&&root==NULL)
		{
			root=s.top();
			/*root=s.front();
			  if(root->rchild)
			  root=root->rchild;
			  else
			  {
			  s.pop();
			  root=s.front();
			  }*/
			while(root->rchild==NULL||root->rchild==ptr)
			{
				ptr=root;
				s.pop();
				root=s.top();
			}
			root=root->rchild;
		}

	}while(flag);
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
	ob.print_ancestor(root,key);
}
