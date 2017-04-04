#include<iostream>
#include<cstdlib>
using namespace std;
struct node
{
	int data;
	struct node *next;
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

void reverse::reverse_list()
{
	struct node *ptr3;
	ptr1=start;
	ptr1=ptr1->next;
	ptr2=start;
	ptr2->next=NULL;
	//ptr3=ptr1->next;
	//ptr1->next=ptr2;
	//ptr2=ptr1;
	//ptr1=ptr3;
	while(ptr1!=NULL)
	{
		ptr3=ptr1->next;
		ptr1->next=ptr2;
		ptr2=ptr1;
		ptr1=ptr3;
	}
	ptr2->next==NULL;
	start=ptr2;
}

void reverse::traversal()
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
	reverse ob;
	ob.creation();
	ob.traversal();
	ob.reverse_list();
	ob.traversal();
}
