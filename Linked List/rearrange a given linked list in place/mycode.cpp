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
		struct node *start,*ptr1,*ptr2,*ptr3;
	public:
		rearrange()
		{
			start=NULL;
		}
		void creation();
		void nodes_in_place();
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

void reverse(struct node **ptr)
{
	struct node *ptr1,*ptr2,*temp,*ptr3;
	if((*ptr)->next==NULL)
		return;

	ptr2=(*ptr);
	ptr1=ptr2->next;
	temp=ptr2;
	while(ptr1!=NULL)
	{
		ptr3=ptr1->next;
		ptr1->next=ptr2;
		ptr2=ptr1;
		ptr1=ptr3;
	}
	(*ptr)=ptr2;
	temp->next=NULL;
}

void rearrange::nodes_in_place()
{
	ptr1=ptr2=start;
	while(ptr1!=NULL&&ptr1->next!=NULL)
	{
		ptr1=ptr1->next->next;
		ptr2=ptr2->next;
	}
	reverse(&ptr2);
	ptr1=start;
	while(ptr1->next!=NULL&&ptr2->next!=NULL)
	{
		ptr3=ptr1->next;
		ptr1->next=ptr2;
		ptr2=ptr2->next;
		ptr1->next->next=ptr3;
		ptr1=ptr3;
	}
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
	ob.nodes_in_place();
	ob.traversal();
}
