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

		int compare(struct node *,struct node *);
};


int tree::compare(struct node *root1,struct node *root2)
{

	if(root1==NULL&&root2==NULL)
		return 1;
	else if(root1==NULL||root2==NULL)
		return 0;
	if(root1->data!=root2->data)
		return 0;

	if((compare(root1->lchild,root2->lchild)&&compare(root1->rchild,root2->rchild))||(compare(root1->lchild,root2->rchild)&&compare(root1->rchild,root2->lchild)))
	return 1;
	else
	return 0;
}

void inorder(struct node *root)
{
	if(root==NULL)
		return ;
	inorder(root->lchild);
	cout<<root->data<<" ";
	inorder(root->rchild);
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
	int i,val;
	struct node *root1=NULL,*root2=NULL;

	tree ob;
	/*cout<<"Enter -1 to exit"<<endl;
	  cout<<"Enter the values for first tree"<<endl;
	  cin>>val;
	  while(val!=-1)
	  {
	  root1=insert(root1,val);
	  cin>>val;
	  }

	  cout<<"Enter the values for second tree"<<endl;
	  cin>>val;
	  while(val!=-1)
	  {
	  root2=insert(root2,val);
	  cin>>val;
	  }*/
	root1=new_node(1);
	root1->lchild        = new_node(2);
	root1->rchild       = new_node(3);
	root1->lchild->lchild  = new_node(4);
	root1->lchild->rchild = new_node(5);
	root1->rchild->lchild  = new_node(6);
	root1->lchild->rchild->lchild = new_node(7);
	root1->lchild->rchild->rchild = new_node(8);

	root2=new_node(1);
	root2->lchild         = new_node(3);
	root2->rchild        = new_node(2);
	root2->rchild->lchild   = new_node(4);
	root2->rchild->rchild   = new_node(5);
	root2->lchild->rchild   = new_node(6);
	root2->rchild->rchild->lchild = new_node(8);
	root2->rchild->rchild->rchild = new_node(7);

	if(ob.compare(root1,root2))
		cout<<"true"<<endl;
	else 
		cout<<"false"<<endl;
	inorder(root1);
	cout<<endl;
	inorder(root2);
}

