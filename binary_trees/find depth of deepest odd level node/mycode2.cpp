#include<iostream>
#include<queue>
using namespace std;

struct node
{
	int data;
	struct node *lchild,*rchild;
};

class tree
{
	public:

		void find_depth(struct node *);
};

void tree::find_depth(struct node *root)
{
	int count,max=0,v=1,key;
	if(root==NULL)
		return ;

	struct node *ptr;
	queue<struct node *> q;
	q.push(root);
	while(1)
	{
		count=q.size();
		if(count==0)
			break;
		while(count>0)
		{
			ptr=q.front();
			q.pop();
			if(v%2!=0)
			{
				if(!ptr->lchild&&!ptr->rchild)
				{
					max=v;
					key=ptr->data;
				}
			}

			if(ptr->lchild)
				q.push(ptr->lchild);
			if(ptr->rchild)
				q.push(ptr->rchild);
			count--;
		}
		v++;
	}
	cout<<"deepest odd level node is "<<key<<endl;
	cout<<"depth of this node is "<<max<<endl;
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
	int i,val,diff;
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
	ob.find_depth(root);
}
