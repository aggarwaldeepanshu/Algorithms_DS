#include<iostream>
using namespace std;

struct node
{
	int data;
	struct node *next;
};

class split
{
	private:
		struct node *last,*last1,*ptr1,*ptr2;
	public:
		split()
		{
			last=NULL;
			last1=NULL;
		}
		void creation();
		void split_nodes();
		void traversal();
};

void split::creation()
{
	int n;
	ptr1=new struct node;
	cout<<"Enter the value for first node"<<endl;
	cin>>n;
	ptr1->data=n;
	ptr1->next=NULL;
	last=ptr1;
	cout<<"Enter -1 to exit"<<endl;
	cin>>n;
	while(n!=-1)
	{
		ptr2=ptr1;
		ptr1=new struct node;
		ptr1->data=n;
		ptr1->next=last;
		ptr2->next=ptr1;
		cin>>n;
	}
	last=ptr1;
}
void split::split_nodes()
{
	ptr1=ptr2=last->next;
	while(ptr1!=last&&ptr1->next!=last)
	{
		ptr1=ptr1->next->next;
		ptr2=ptr2->next;
	}
	ptr1=ptr2->next;
	ptr2->next=last->next;
	last->next=ptr1;
	last1=ptr2;
}

void split::traversal()
{
	cout<<"Traversal"<<endl;
	ptr2=last1->next;
	cout<<ptr2->data<<" ";
	ptr2=ptr2->next;
	while(ptr2!=last1->next)
	{
		cout<<ptr2->data<<" ";
		ptr2=ptr2->next;
	}
	cout<<endl;

	ptr2=last->next;
	cout<<ptr2->data<<" ";
	ptr2=ptr2->next;
	while(ptr2!=last->next)
	{
		cout<<ptr2->data<<" ";
		ptr2=ptr2->next;
	}
	cout<<endl;
}

int main(void)
{
	split ob;
	ob.creation();
	ob.split_nodes();
	ob.traversal();
}
