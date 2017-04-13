#include<iostream>
using namespace std;

struct node
{
	int data;
	struct node *prev,*next;
};

class swap_node
{
	private:
		struct node *start,*ptr1,*ptr2;
	public:
		swap_node()
		{
			start=NULL;
		}
		void creation();
		void swap_kth_node();
		void traversal();
};

void swap_node::creation()
{
	int n;
	ptr1=new struct node;
	cout<<"Enter the value for first node"<<endl;
	cin>>n;
	ptr1->data=n;
	ptr1->next=NULL;
	ptr1->prev=NULL;
	start=ptr1;
	cout<<"Enter -1 to exit"<<endl;
	cin>>n;
	while(n!=-1)
	{
		ptr2=ptr1;
		ptr1=new struct node;
		ptr1->data=n;
		ptr1->next=NULL;
		ptr1->prev=ptr2;
		ptr2->next=ptr1;
		cin>>n;
	}
}

void swap_node::swap_kth_node()
{
	struct node *ptr3;
	int i=1,k;
	cout<<"Enter k"<<endl;
	cin>>k;
	ptr1=start;
	while(i!=k)
	{
		i++;
		ptr1=ptr1->next;
	}
	ptr2=ptr1;

	while(ptr2->next!=NULL)
		ptr2=ptr2->next;

	i=1;
	while(i!=k)
	{
		i++;
		ptr2=ptr2->prev;
	}

	if(ptr1==ptr2)
		return;

	else if(ptr1==NULL||ptr2==NULL)
		return;

	else
	{
		if(ptr1->prev!=NULL)
			ptr1->prev->next=ptr2;
		if(ptr2->prev!=NULL)
			ptr2->prev->next=ptr1;
		if(ptr1->next!=NULL)
			ptr1->next->prev=ptr2;
		if(ptr2->next!=NULL)
			ptr2->next->prev=ptr1;

		ptr3=ptr1->next;
		ptr1->next=ptr2->next;
		ptr2->next=ptr3;

		ptr3=ptr1->prev;
		ptr1->prev=ptr2->prev;
		ptr2->prev=ptr3;
	}
	if(ptr2->prev==NULL)
		start=ptr2;
}

void swap_node::traversal()
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
	swap_node ob;
	ob.creation();
	ob.traversal();
	ob.swap_kth_node();
	ob.traversal();
}
