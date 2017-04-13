#include<iostream>
using namespace std;

struct node
{
	int data;
	struct node *left,*right;
};

class doublylinkedlist
{
	private:
		struct node *start,*ptr1,*ptr2;
	public:
		doublylinkedlist()
		{
			start=NULL;
		}
		void BT_CDLL(struct node *);
		void traversal();
};

struct node *insert(struct node *root,int key)
{
	struct node *ptr,*ptr1,*temp;
	ptr=root;
	ptr1=NULL;
	temp=new struct node;
	while(ptr!=NULL)
	{
		ptr1=ptr;
		if(ptr->data>key)
			ptr=ptr->left;
		else if(ptr->data<key)
			ptr=ptr->right;
		else
		{
			cout<<"Value already exist"<<endl;
			return root;
		}
	}
	temp->data=key;
	temp->left=NULL;
	temp->right=NULL;
	if(ptr1==NULL)
		root=temp;
	else if(ptr1->data>key)
		ptr1->left=temp;
	else
		ptr1->right=temp;
	return root;
}

void doublylinkedlist::BT_CDLL(struct node *root)
{
	if(root==NULL)
		return;
	BT_CDLL(root->left);

	if(start==NULL)
	{
		ptr1=new struct node;
		ptr1->data=root->data;
		ptr1->left=NULL;
		ptr1->right=ptr1;
		start=ptr1;
		ptr2=ptr1;
	}
	else
	{
		ptr1=new struct node;
		ptr1->data=root->data;
		ptr1->right=start;
		ptr1->left=ptr2;
		ptr2->right=ptr1;
		ptr2=ptr1;
	}
	BT_CDLL(root->right);
}

void doublylinkedlist::traversal()
{
	cout<<"The required circular doubly linked list is:"<<endl;
	ptr2=start;
	cout<<ptr2->data<<" ";
	ptr2=ptr2->right;
	while(ptr2!=start)
	{
		cout<<ptr2->data<<" ";
		ptr2=ptr2->right;
	}
	cout<<endl;
}

int main(void)
{
	struct node *root;
	doublylinkedlist ob;
	root=insert(root,5);
	root=insert(root,3);
	root=insert(root,6);
	root=insert(root,1);
	root=insert(root,4);
	root=insert(root,8);
	root=insert(root,0);
	root=insert(root,2);
	root=insert(root,7);
	root=insert(root,9);
	ob.BT_CDLL(root);
	ob.traversal();
}
