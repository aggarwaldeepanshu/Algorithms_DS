#include<iostream>
#include<cstdlib>
using namespace std;
struct node
{
	int data;
	struct node *next;
};

class deletion
{
	private:
		int k;
		struct node *start,*ptr1,*ptr2;
	public:
		deletion()
		{
			start=NULL;
		}
		void creation();
		void count();
		void ll_deletion();
		void traversal();
};

void deletion::creation()
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

void deletion::ll_deletion()
{
	ptr1=start;
	while(ptr1->next!=NULL)
	{
		ptr2=ptr1;
		ptr1=ptr1->next;
		delete ptr2;
	}
	delete ptr1;
        start=NULL;
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
	ob.ll_deletion();
	ob.traversal();
}
