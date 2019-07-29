#include<iostream>
#include<cstdlib>
using namespace std;
struct node
{
	int data;
	struct node *next;
};

class loop
{
	private:
		struct node *start,*ptr1,*ptr2;
	public:
		loop()
		{
			start=NULL;
		}
		void creation();
		void loop_check();
		void traversal();
};

void loop::creation()
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

void loop::loop_check()
{
	ptr1=start;
	ptr2=start;
	while(ptr1!=NULL&&ptr2!=NULL&&ptr2->next!=NULL)
	{
		ptr1=ptr1->next;
		ptr2=ptr2->next->next;
		if(ptr1==ptr2)
		{
			cout<<"Loop found"<<endl;
			break;
		}
	}
	if(ptr1==NULL||ptr2==NULL)
		cout<<"No loop detected"<<endl;
}

void loop::traversal()
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
	loop ob;
	ob.creation();
	ob.traversal();
	ob.loop_check();
}
