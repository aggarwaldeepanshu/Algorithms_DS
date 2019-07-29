#include<iostream>
using namespace std;

struct node
{
	int data;
	struct node *next;
};

class delete_node
{
	private:
		struct node *start,*ptr1,*ptr2;
	public:
		delete_node()
		{
			start=NULL;
		}
		void creation();
		void delete_node_list();
		void traversal();
};

void delete_node::creation()
{
	int n;
	ptr1=new struct node;
	cout<<"Enter the value for first node"<<endl;
	cin>>n;
	ptr1->data=n;
	ptr1->next=NULL;
	start=ptr1;
	cout<<"Enter -1 to exit"<<endl;
	cin>>n;
	while(n!=-1)
	{
		ptr2=ptr1;
		ptr1=new struct node;
		ptr1->data=n;
		ptr1->next=NULL;
		ptr2->next=ptr1;
		cin>>n;
	}
}

void reverse(struct node **start)
{
	struct node *ptr1,*ptr2,*ptr3;
	ptr1=(*start);
	ptr1=ptr1->next;
	ptr2=(*start);
	ptr2->next=NULL;
	while(ptr1!=NULL)
	{
		ptr3=ptr1->next;
		ptr1->next=ptr2;
		ptr2=ptr1;
		ptr1=ptr3;
	}
	ptr2->next==NULL;
	(*start)=ptr2;
}

void delete_node::delete_node_list()
{
	struct node *temp;
	int max;
	reverse(&start);
	ptr1=start;
	max=ptr1->data;
	ptr2=ptr1;
	ptr1=ptr1->next;
	while(ptr1!=NULL)
	{
		if(ptr1->data>max)
		{
			max=ptr1->data;
			ptr2=ptr1;
			ptr1=ptr1->next;
		}
		else if(ptr1->data<max)
		{
			temp=ptr1;
			ptr2->next=ptr1->next;
			delete ptr1;
			ptr1=ptr2->next;
		}
	}
	reverse(&start);
}

void delete_node::traversal()
{
	cout<<"Traversal"<<endl;
	ptr2=start;
	while(ptr2!=NULL)
	{
		cout<<ptr2->data<<" ";
		ptr2=ptr2->next;
	}
	cout<<endl;
}

int main(void)
{
	delete_node ob;
	ob.creation();
	ob.traversal();
	ob.delete_node_list();
	ob.traversal();
}
