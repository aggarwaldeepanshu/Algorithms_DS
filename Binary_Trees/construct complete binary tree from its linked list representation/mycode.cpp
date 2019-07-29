#include<iostream>
#include<queue>
using namespace std;

struct node
{
	int data;
	struct node *lchild,*rchild;
};

struct node1
{
	int data;
	struct node1 *next;
};

class tree
{
	public:

		struct node *ConstructCompleteTree(struct node *,struct node1 *);
		void push(struct node1 **,int );
		void inorder(struct node *);
};

struct node *new_node(int val)
{
	struct node *ptr=new node;
	ptr->data=val;
	ptr->lchild=NULL;
	ptr->rchild=NULL;
	return ptr;
}

struct node *tree::ConstructCompleteTree(struct node *root,struct node1 *start)
{
	struct node *temp;
	queue<struct node *> q;
	struct node1 *ptr;
	ptr=start;

	root=new_node(ptr->data);
	ptr=ptr->next;
	q.push(root);

	while(ptr!=NULL&&ptr->next!=NULL)
	{
		temp=q.front();
		q.pop();
		temp->lchild=new_node(ptr->data);
		temp->rchild=new_node(ptr->next->data);
		ptr=ptr->next->next;
		q.push(temp->lchild);
		q.push(temp->rchild);
	}
	if(ptr)
	{
		temp=q.front();
		q.pop();
		temp->lchild=new_node(ptr->data);
	}
	return root;
}


void tree::push(struct node1 **start,int key)
{
	struct node1 *ptr=new struct node1;
	ptr->data=key;
	ptr->next=*start;
	*start=ptr;
}

void tree::inorder(struct node *root)
{
	if(root==NULL)
		return ;
	inorder(root->lchild);
	cout<<root->data<<" ";
	inorder(root->rchild);
}

int main(void)
{
	int i,val;
	tree ob;
	struct node *root=NULL;
	struct node1 *start=NULL;

	cout<<"Enter the values to insert in linked list"<<endl;
	cout<<"Press -1 to exit"<<endl;
	cin>>val;
	while(val!=-1)
	{
		ob.push(&start,val);
		cin>>val;
	}
	root=ob.ConstructCompleteTree(root,start);
	cout<<"The inorder traversal is"<<endl;
	ob.inorder(root);
}
