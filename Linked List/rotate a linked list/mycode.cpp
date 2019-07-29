#include<iostream>
using namespace std;

struct node
{
	int data;
	struct node *next;
};

class rotate
{
	private:
		struct node *start,*ptr1,*ptr2;
	public:
		rotate()
		{
			start=NULL;
		}
		void creation();
		void rotate_list();
		void traversal();
};

void rotate::creation()
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

void rotate::rotate_list()
{
	int i=1,k;
	cout<<"Enter the value of k"<<endl;
	cin>>k;
	ptr1=start;
	while(i!=k)
	{
		i++;
		ptr1=ptr1->next;
	}
	ptr2=ptr1;

	while(ptr2->next!=NULL)
		ptr2=ptr2->next;

	ptr2->next=start;
	start=ptr1->next;
	ptr1->next=NULL;
}

void rotate::traversal()
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
	rotate ob;
	ob.creation();
	ob.rotate_list();
	ob.traversal();
}
