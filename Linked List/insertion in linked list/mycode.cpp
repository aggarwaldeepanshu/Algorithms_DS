#include<iostream>
#include<cstdlib>
using namespace std;
struct node
{
	int data;
	struct node *next;
};

class insertion
{
	private:
		struct node *start,*ptr1,*ptr2;
	public:
		insertion()
		{
			start=NULL;
		}
		void creation();
		void traversal();
		void insert_atbegin();
		void insert_after(int);
		void insert_before(int);
		void insert_atend();
};

void insertion::creation()
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

void insertion::insert_atbegin()
{
	int n;
	cout<<"Enter the value to insert at beginning"<<endl;
	cin>>n;
	struct node *ptr;
	ptr=new struct node;
	ptr->data=n;
	ptr->next=start;
	start=ptr;
}

void insertion::insert_atend()
{
	int n;
	cout<<"Enter the value to insert at end"<<endl;
	cin>>n;
	struct node *ptr;
	ptr=new struct node;
	ptr1=start;
	while(ptr1->next!=NULL)
		ptr1=ptr1->next;
	ptr->data=n;
	ptr->next=NULL;
	ptr1->next=ptr;
}

void insertion::insert_after(int val)
{
	int n;
	cout<<"Enter the value to insert after "<<val<<endl;
	cin>>n;
	struct node *ptr;
	ptr=new struct node;
	ptr->data=n;
	ptr1=start;
	while(ptr1->data!=val)
		ptr1=ptr1->next;
	ptr->next=ptr1->next;
	ptr1->next=ptr;
}

void insertion::insert_before(int val)
{
	int n;
	cout<<"Enter the value to insert before "<<val<<endl;
	cin>>n;
	struct node *ptr;
	ptr=new struct node;
	ptr->data=n;
	ptr1=start;
	while(ptr1->next!=NULL&&ptr1->next->data!=val)
		ptr1=ptr1->next;
	ptr->next=ptr1->next;
	ptr1->next=ptr;
}

void insertion::traversal()
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
	insertion ob;
	ob.creation();
	ob.traversal();
	ob.insert_atbegin();
	ob.traversal();
	ob.insert_atend();
	ob.insert_after(5);
	ob.insert_before(5);
	ob.traversal();
}
