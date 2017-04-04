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
		void insert_in_sorted_list();
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

void insertion::insert_in_sorted_list()
{
	int n;
	cout<<"Enter the value to insert"<<endl;
	cin>>n;
	ptr1=start;

	struct node *ptr=new struct node;
	ptr->data=n;

	if(start==NULL)
	{
		start=ptr;
		ptr->next=NULL;
	}

	else if(n<=ptr1->data)
	{
		ptr->next=start;
		start=ptr;
	}
	else
	{
		while(ptr1!=NULL&&ptr1->data<n)
		{
			ptr2=ptr1;
			ptr1=ptr1->next;
		}

		if(ptr1->data>=n)
		{
			ptr->next=ptr2->next;
			ptr2->next=ptr;
		}
		else if(ptr1==NULL)
		{
			ptr2->next=ptr;
			ptr->next=NULL;
		}
	}
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
	ob.insert_in_sorted_list();
	ob.traversal();
}
