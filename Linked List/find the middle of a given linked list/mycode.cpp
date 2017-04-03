#include<iostream>
#include<cstdlib>
using namespace std;
struct node
{
	int data;
	struct node *next;
};

class middle
{
	private:
		struct node *start,*ptr1,*ptr2;
	public:
		middle()
		{
			start=NULL;
		}
		void creation();
		void middle_element();
		void get_middle(int);
		void traversal();
};

void middle::creation()
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

void middle::get_middle(int pos)
{
	int count=0;
	ptr1=start;
	while(count!=pos)
	{
		ptr1=ptr1->next;
		count++;
	}
	if(count==pos)
		cout<<ptr1->data<<endl;
}

void middle::middle_element()
{
	int count=0;
	ptr1=start;
	while(ptr1->next!=NULL)
	{
		count++;
		ptr1=ptr1->next;
	}
	count++;
	get_middle(count/2);
}

void middle::traversal()
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
	middle ob;
	ob.creation();
	ob.traversal();
	ob.middle_element();
}
