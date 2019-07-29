#include<iostream>
using namespace std;

struct node
{
	int data;
	struct node *next;
};

class insert
{
	private:
		struct node *last,*ptr1,*ptr2;
	public:
		insert()
		{
			last=NULL;
		}
		void creation();
		void insert_node();
		void traversal();
};

void insert::creation()
{
	int n;
	ptr1=new struct node;
	cout<<"Enter the value for first node"<<endl;
	cin>>n;
	ptr1->data=n;
	ptr1->next=ptr1;
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
void insert::insert_node()
{
	int k;
	cout<<"Enter the value of node to insert"<<endl;
	cin>>k;
	ptr1=new struct node;
	ptr1->data=k;
	if(last==NULL)
	{
		ptr1->next=ptr1;
		last=ptr1;
		return;
	}

	ptr2=last->next;
	if(ptr2->data>=k)
	{
		ptr1->next=ptr2;
		last->next=ptr1;
	}
	else
	{
		while(ptr2->next->data<k&&ptr2->next!=last->next)
			ptr2=ptr2->next;
		if(ptr2!=last)
		{
			ptr1->next=ptr2->next;
			ptr2->next=ptr1;
		}
		else
		{
			ptr1->next=last->next;
			last->next=ptr1;
			last=ptr1;
		}
	}
}

void insert::traversal()
{
	cout<<"list after insertion"<<endl;
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
	insert ob;
	ob.creation();
	ob.insert_node();
	ob.traversal();
}
