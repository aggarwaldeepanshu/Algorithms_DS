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

		int CheckLeafLevel(struct node *);
};

int tree::CheckLeafLevel(struct node *root)
{
	int count,k,max=0,flag=1,level=1;
	if(root==NULL)
		return 1;

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

			if(!ptr->lchild&&!ptr->rchild)
			{
				if(flag==1)
				{
					flag=0;
					k=level;
				}
				else if(flag==0&&level!=k)
					return 0;
			}
			if(ptr->lchild)
				q.push(ptr->lchild);
			if(ptr->rchild)
				q.push(ptr->rchild);
			count--;
		}
		level++;
	}
	return 1;
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
	if(ob.CheckLeafLevel(root))
               cout<<"all leaves at same level"<<endl;
        else
               cout<<"leaves not at same level"<<endl;
}
