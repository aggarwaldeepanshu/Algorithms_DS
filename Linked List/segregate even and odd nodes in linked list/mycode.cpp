#include<iostream>
using namespace std;

struct node
{
	int data;
	struct node *next;
};

class segregate
{
	private:
		struct node *start,*ptr1,*ptr2,*start1;
	public:
		segregate()
		{
			start=new struct node;
			start1=new struct node;
		}
		void creation();
		void segregate_nodes();
		void traversal();
};

void segregate::creation()
{
	int n;
	ptr1=new struct node;
	cout<<"Enter the value for first node"<<endl;
	cin>>n;
	ptr1->data=n;
	ptr1->next=NULL;
	start->data=-1;
	start1->data=-1;
	start->next=ptr1;
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

void segregate::segregate_nodes()
{
	struct node *ptr,*ptr3;
	ptr=start;
	ptr1=start1;
	ptr3=start;
	ptr=ptr->next;
	while(ptr!=NULL)
	{
		if(ptr->data%2==0)
		{
			ptr3=ptr;
			ptr=ptr->next;
		}
		else
		{
			ptr3->next=ptr->next;
			ptr1->next=ptr;
			ptr=ptr3->next;
			ptr1=ptr1->next;
			ptr1->next=NULL;
		}
	}
	ptr3->next=start1->next;
}


void segregate::traversal()
{
	cout<<"Traversal"<<endl;
	ptr2=start;
	ptr2=ptr2->next;
	while(ptr2!=NULL)
	{
		cout<<ptr2->data<<" ";
		ptr2=ptr2->next;
	}
	cout<<endl;
}

int main(void)
{
	segregate ob;
	ob.creation();
	ob.traversal();
	ob.segregate_nodes();
	ob.traversal();
}
