#include<bits/stdc++.h>
using namespace std;

struct node
{
	int data;
	struct node *lchild,*rchild,*down;
};

class tree
{
	public:

		void BottomView(struct node *);
};

void tree::BottomView(struct node *root)
{
	int n=0,a,key;

	if(root==NULL)
		return ;

	struct node *ptr;
	pair <struct node *,int> p;
	map <int,int> arr;

	map <int,int>::iterator it;

	queue<pair <struct node *,int> > q;
	q.push(make_pair(root,n));
	while(!q.empty())
	{
		p=q.front();
		q.pop();
		n=p.second;
		ptr=p.first;

                arr[n]=ptr->data;

		if(ptr->lchild)
			q.push(make_pair(ptr->lchild,n-1));

		if(ptr->rchild)
			q.push(make_pair(ptr->rchild,n+1));
	}
	for(it=arr.begin();it!=arr.end();it++)
	{
		cout<<it->second<<" ";
	}
}

struct node *new_node(int val)
{
	struct node *ptr=new node;
	ptr->data=val;
	ptr->lchild=NULL;
	ptr->rchild=NULL;
	ptr->down=NULL;
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
	int i,val,k;
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
	ob.BottomView(root);
}
