#include<iostream>
using namespace std;

struct node
{
	int data;
	struct node *next;
};

class rearrange
{
	private:
		struct node *start,*ptr1,*ptr2;
	public:
		rearrange()
		{
			start=NULL;
		}
		void creation();
		void rearrange_list();
		void traversal();
};

void rearrange::creation()
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

void rearrange::rearrange_list()
{
	struct node *start1,*ptr3,*ptr4;
	ptr1=start;
	ptr1=ptr1->next;
	start1=ptr1;
	ptr2=start;
	while(ptr1!=NULL&&ptr1->next!=NULL)
	{
		ptr3=ptr1->next->next;
		ptr2->next=ptr1->next;
		ptr1->next=ptr3;
		ptr1=ptr3;
		ptr2=ptr2->next;
	}

	ptr2->next=start1;
}

void rearrange::traversal()
{
	cout<<"List after rearranging"<<endl;
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
	rearrange ob;
	ob.creation();
	ob.rearrange_list();
	ob.traversal();
}
