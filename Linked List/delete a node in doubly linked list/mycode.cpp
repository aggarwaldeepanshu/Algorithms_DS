#include<iostream>
using namespace std;

struct node
{
	int data;
	struct node *prev,*next;
};

class deletion
{
	private:
		struct node *start,*ptr1,*ptr2;
	public:
		deletion()
		{
			start=NULL;
		}
		void creation();
		void traversal();
		void delete_atbegin();
		void delete_after(int);
		void delete_before(int);
		void delete_atend();
};

void deletion::creation()
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

void deletion::delete_atbegin()
{
	ptr1=ptr2=start;
	ptr2=ptr2->next;
	ptr2->prev=NULL;
	start=ptr2;
	delete ptr1;
}

void deletion::delete_atend()
{
	ptr1=start;
	while(ptr1->next!=NULL)
	{
		ptr2=ptr1;
		ptr1=ptr1->next;
	}
	ptr2->next=NULL;
	delete ptr1;
}

void deletion::delete_after(int val)
{
	ptr1=start;
	while(ptr1->data!=val)
		ptr1=ptr1->next;

	ptr2=ptr1->next;
	ptr1->next=ptr1->next->next;
	ptr1->next->prev=ptr1;
	delete ptr2;
}

void deletion::delete_before(int val)
{
	ptr1=start;
	while(ptr1->next!=NULL&&ptr1->next->data!=val)
		ptr1=ptr1->next;

	ptr1->prev->next=ptr1->next;
	ptr1->next->prev=ptr1->prev;
	delete ptr1;
}

void deletion::traversal()
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
	deletion ob;
	ob.creation();
	ob.traversal();
	ob.delete_atbegin();
	ob.traversal();
	ob.delete_atend();
	ob.traversal();
	ob.delete_after(5);
	ob.traversal();
	ob.delete_before(5);
	ob.traversal();
}
