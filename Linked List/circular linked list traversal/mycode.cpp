#include<iostream>
using namespace std;

struct node
{
	int data;
	struct node *next;
};

class traversal
{
	private:
		struct node *last,*ptr1,*ptr2;
	public:
		traversal()
		{
			last=NULL;
		}
		void creation();
		void print();
};

void traversal::creation()
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

void traversal::print()
{
	cout<<"Traversal"<<endl;
	ptr2=ptr1=last->next;
	cout<<ptr1->data<<" ";
	ptr1=ptr1->next;
	while(ptr1!=ptr2)
	{
		cout<<ptr1->data<<" ";
		ptr1=ptr1->next;
	}
	cout<<endl;
}

int main(void)
{
	traversal ob;
	ob.creation();
	ob.print();
}
