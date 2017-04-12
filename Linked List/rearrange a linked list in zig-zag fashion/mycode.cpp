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

void swap_data(struct node *ptr1,struct node *ptr2)
{
	int temp;
	temp=ptr1->data;
	ptr1->data=ptr2->data;
	ptr2->data=temp;
}

void rearrange::rearrange_list()
{
	int n=0,temp;
	ptr1=start;
	ptr2=ptr1->next;
	while(ptr2!=NULL)
	{
		if(n%2==0)
		{
			if(ptr1->data>ptr2->data)
				swap_data(ptr1,ptr2);
		}
		else
		{
			if(ptr1->data<ptr2->data)
				swap_data(ptr1,ptr2);
		}

		n++;
		ptr1=ptr2;
		ptr2=ptr2->next;
	}
}

void rearrange::traversal()
{
	cout<<"List in Zig-Zag manner"<<endl;
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
