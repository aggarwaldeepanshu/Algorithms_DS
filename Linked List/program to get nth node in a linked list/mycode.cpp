#include<iostream>
#include<cstdlib>
using namespace std;
struct node
{
	int data;
	struct node *next;
};

class nth_node
{
	private:
		struct node *start,*ptr1,*ptr2;
	public:
		nth_node()
		{
			start=NULL;
		}
		void creation();
		void get_nth_node(int);
		void traversal();
};

void nth_node::creation()
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

void nth_node::get_nth_node(int pos)
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

void nth_node::traversal()
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
	nth_node ob;
	ob.creation();
	ob.traversal();
	ob.get_nth_node(3);
}
