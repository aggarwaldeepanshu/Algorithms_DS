#include<iostream>
using namespace std;

struct node
{
	int data;
	struct node *right,*down;
};

class flatten
{
	private:
		struct node *start,*ptr1,*ptr2,*ptr3;
	public:
		flatten()
		{
			start=NULL;
		}
		void creation();
		void flatten_list();
		void traversal();
};

void flatten::creation()
{
	int n,m;
	ptr1=new struct node;
	cout<<"Enter the value for first node"<<endl;
	cin>>n;
	ptr1->data=n;
	ptr1->right=NULL;
	start=ptr1;
	cout<<"Enter -1 to exit"<<endl<<"Enter -2 to exit the linked list with current node as head"<<endl;
	cin>>n;
	ptr2=ptr1;
	while(n!=-1)
	{
		cin>>m;
		ptr3=ptr2;
		while(m!=-2)
		{
			ptr1=new struct node;
			ptr1->data=m;
			ptr1->down=NULL;
			ptr1->right=NULL;
			ptr3->down=ptr1;
			ptr3=ptr3->down;
			cin>>m;
		}
		ptr1=new struct node;
		ptr1->data=n;
		ptr1->down=NULL;
		ptr1->right=NULL;
		ptr2->right=ptr1;
		ptr2=ptr2->right;
		cin>>n;
	}
}

void merge(struct node **start)
{
	struct node *ptr,*ptr1,*ptr2,*temp,*ptr3;
	ptr=(*start);
	ptr2=ptr;
	ptr3=ptr;
	ptr1=ptr->right;
	while(ptr!=NULL&&ptr1!=NULL)
	{
		if(ptr->data<ptr1->data)
		{
			ptr2=ptr;
			ptr=ptr->down;
		}
		else if(ptr->data>ptr1->data)
		{
			if(ptr3->right==ptr1)
				ptr3->right=ptr1->right;

			ptr2->down=ptr1;
			ptr1=ptr1->down;
			ptr2->down->down=ptr;
			ptr2=ptr2->down;
		}
		else
		{
			if(ptr3->right==ptr1)
				ptr3->right=ptr1->right;

			temp=ptr1;
			ptr1=ptr1->down;
			ptr2=ptr;
			ptr=ptr->down;
			delete temp;
		}
	}
	if(ptr==NULL)
	{
		while(ptr1!=NULL)
		{
			if(ptr3->right==ptr1)
				ptr3->right=ptr1->right;

			ptr2->down=ptr1;
			ptr2->down->down=NULL;
			ptr2=ptr2->down;
			ptr1=ptr1->down;
		}
	}
}

void flatten::flatten_list()
{
	ptr1=start;
	while(ptr1!=NULL&&ptr1->right!=NULL)
	{
		merge(&start);
		ptr1=start;
	}
}

void flatten::traversal()
{
	cout<<"List after flattening"<<endl;
	ptr2=start;
	while(ptr2!=NULL)
	{
		cout<<ptr2->data<<" ";
		ptr2=ptr2->down;
	}
	cout<<endl;
}

int main(void)
{
	flatten ob;
	ob.creation();
	ob.flatten_list();
	ob.traversal();
}
