#include<iostream>
#include<cstdlib>
using namespace std;
struct node
{
	int data;
	struct node *next;
};

class swap_nodes
{
	private:
		struct node *start,*ptr1,*ptr2,*ptr3,*ptr4;
	public:
		swap_nodes()
		{
			start=NULL;
		}
		void creation();
		void swap_element();
		void traversal();
};

void swap_nodes::creation()
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

void swap_nodes::swap_element()
{
	int a,b,v;
	struct node *temp;
	cout<<"Enter the values to swap"<<endl;
	cin>>a>>b;
	ptr1=start;

	while(ptr1->next!=NULL&&ptr1->data!=a&&ptr1->data!=b)
	{
		ptr3=ptr1;
		ptr1=ptr1->next;
	}

	if(ptr1->data==a||ptr1->data==b)
	{
		ptr2=ptr1->next;
		v=(ptr1->data==a)?b:a;
	}

	while(ptr2->next!=NULL&&ptr2->data!=v)
	{
		ptr4=ptr2;
		ptr2=ptr2->next;
	}

	ptr3->next=ptr2;
	temp=ptr2->next;
	ptr2->next=ptr1->next;
	ptr1->next=temp;
	ptr4->next=ptr1;
}

void swap_nodes::traversal()
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
	swap_nodes ob;
	ob.creation();
	ob.traversal();
	ob.swap_element();
	ob.traversal();
}
