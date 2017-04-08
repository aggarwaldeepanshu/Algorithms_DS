#include<iostream>
using namespace std;

struct node
{
	int data;
	struct node *next;
};

class deletion
{
	private:
		struct node *ptr1,*ptr2;
	public:
		void creation(struct node **);
		void delete_node(struct node **,struct node *);
		void traversal(struct node *);
};

void deletion::creation(struct node **start)
{
	int n;
	ptr1=new struct node;
	cout<<"Enter the value for first node"<<endl;
	cin>>n;
	ptr1->data=n;
	ptr1->next=NULL;
	(*start)=ptr1;
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

void deletion::delete_node(struct node **start,struct node *ptr)
{
	ptr1=(*start);
	if(ptr1==ptr)
	{
		if(ptr1->next==NULL)
		{
			cout<<"Empty list"<<endl;
			return;
		}
		ptr2=ptr1;
		(*start)=ptr1->next;
		delete ptr2;
	}
	else
	{
		while(ptr1->next!=NULL&&ptr1->next!=ptr)
			ptr1=ptr1->next;
		if(ptr1->next==NULL)
		{
			cout<<"Value not present"<<endl;
			return;
		}
		ptr2=ptr1->next;
		ptr1->next=ptr1->next->next;
		delete ptr2;
		return;
	}
}

void deletion::traversal(struct node *start)
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
	struct node *start;
	deletion ob;
	ob.creation(&start);
	ob.traversal(start);
	ob.delete_node(&start,start->next->next->next);
	ob.traversal(start);
}
