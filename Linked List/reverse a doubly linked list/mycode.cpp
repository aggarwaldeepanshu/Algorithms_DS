#include<iostream>
using namespace std;

struct node
{
	int data;
	struct node *prev,*next;
};

class reverse
{
	private:
		struct node *start,*ptr1,*ptr2;
	public:
		reverse()
		{
			start=NULL;
		}
		void creation();
		void reverse_list();
		void traversal();
};

void reverse::creation()
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

void reverse::reverse_list()
{
	ptr1=start;
	while(ptr1->next!=NULL)
	{
		ptr2=ptr1->next;
		ptr1->next=ptr1->prev;
		ptr1->prev=ptr2;
		ptr1=ptr1->prev;
	}
	ptr1->next=ptr1->prev;
	ptr1->prev=NULL;
	start=ptr1;
}

void reverse::traversal()
{
	cout<<"List in reverse order:"<<endl;
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
	reverse ob;
	ob.creation();
	ob.reverse_list();
	ob.traversal();
}
