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

		int convert_tree(struct node *);
};


int tree::convert_tree(struct node *root)
{
	int diff;
	if(root==NULL)
		return 0;

	if(root->lchild==NULL&&root->rchild==NULL)
		return root->data;

	diff=(convert_tree(root->lchild)+convert_tree(root->rchild))-root->data;
	if(diff==0)
		return root->data;
	else if(diff>0)
	{
		root->data=root->data+diff;
		return root->data;
	}
	else if(diff<0)
	{
                diff=-diff;
		if(root->lchild)
		{
			root->lchild->data+=diff;
		         convert_tree(root->lchild);
		}
		else if(root->rchild)
		{
			root->rchild->data+=diff;
			convert_tree(root->rchild);
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

/*struct node *insert(struct node *root,int val)
  {
  if(root==NULL)
  return new_node(val);
  else if(val<=root->data)
  root->lchild=insert(root->lchild,val);
  else
  root->rchild=insert(root->rchild,val);

  return root;
  }*/

void inorder(struct node *root)
{
	if(root==NULL)
		return;
	inorder(root->lchild);
	cout<<root->data<<" ";
	inorder(root->rchild); 
}

int main(void)
{
	int i,val;
	struct node *root;
	root=NULL;
	tree ob;
	/*cout<<"Enter the values for tree"<<endl<<"Enter -1 to exit"<<endl;
	  cin>>val;
	  while(val!=-1)
	  {
	  root=insert(root,val);
	  cin>>val;
	  }*/
	root=new_node(50);
	root->lchild        = new_node(7);
	root->rchild       = new_node(2);
	root->lchild->lchild  = new_node(3);
	root->lchild->rchild = new_node(5);
	root->rchild->lchild  = new_node(1);
	root->rchild->rchild = new_node(30);

	inorder(root);
	cout<<endl;
	ob.convert_tree(root);
	inorder(root);
}
