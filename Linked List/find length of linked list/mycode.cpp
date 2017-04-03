#include<iostream>
#include<cstdlib>
using namespace std;
struct node
{
	int data;
	struct node *next;
};

class count_nodes
{
	private:
		struct node *start,*ptr1,*ptr2;
	public:
		count_nodes()
		{
			start=NULL;
		}
		void creation();
		void getcount();
		void traversal();
};

void count_nodes::creation()
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

void count_nodes::getcount()
{
	int count=0;
	ptr1=start;
	while(ptr1->next!=NULL)
	{
		count++;
		ptr1=ptr1->next;
	}
	cout<<"Number of nodes: "<<count+1<<endl;
}

void count_nodes::traversal()
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
	count_nodes ob;
	ob.creation();
	ob.traversal();
	ob.getcount();
}
