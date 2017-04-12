#include<iostream>
using namespace std;

struct node
{
	int data;
	struct node *next,*arbit;
};

class greatest_value
{
	private:
		struct node *ptr1,*ptr2;
	public:
		void creation(struct node **);
		void pointer_to_greatest_node(struct node *);
		void traversal(struct node *);
};

void greatest_value::creation(struct node **start)
{
	int n;
	ptr1=new struct node;
	cout<<"Enter the value for first node"<<endl;
	cin>>n;
	ptr1->data=n;
	ptr1->next=NULL;
	ptr1->arbit=NULL;
	(*start)=ptr1;
	cout<<"Enter -1 to exit"<<endl;
	cin>>n;
	while(n!=-1)
	{
		ptr2=ptr1;
		ptr1=new struct node;
		ptr1->data=n;
		ptr1->next=NULL;
		ptr1->arbit=NULL;
		ptr2->next=ptr1;
		cin>>n;
	}
}

void greatest_value::pointer_to_greatest_node(struct node *start)
{
	static struct node *max;
	if(start==NULL)
		return ;

	if(start->next==NULL)
	{
		max=start;
		return;
	}

	pointer_to_greatest_node(start->next);
	start->arbit=max;
	if(start->data>max->data)
		max=start;

	return;
}

void greatest_value::traversal(struct node *start)
{
	ptr2=start;
	cout<<"data   data at next node    max at right"<<endl;
	while(ptr2!=NULL)
	{
		cout<<ptr2->data<<"  ";
		if(ptr2->next!=NULL)
			cout<<ptr2->next->data<<"   ";
		else
			cout<<"NULL   ";
		if(ptr2->arbit!=NULL)
			cout<<ptr2->arbit->data<<endl;
		else
			cout<<"NULL"<<endl;
		ptr2=ptr2->next;
	}
	cout<<endl;
}

int main(void)
{
	struct node *start;
	greatest_value ob;
	ob.creation(&start);
	ob.pointer_to_greatest_node(start);
	ob.traversal(start);
}
