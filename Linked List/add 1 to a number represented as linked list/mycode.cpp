#include<iostream>
using namespace std;

struct node
{
	int data;
	struct node *next;
};

class add
{
	private:
		struct node *ptr1,*ptr2;
	public:
		void creation(struct node **);
		struct node *add_one(struct node *);
		void traversal(struct node *);
};

void add::creation(struct node **start)
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

int add_carry(struct node *start)
{
	int sum;
	if(start==NULL)
		return 1;

	sum=start->data+add_carry(start->next);
	start->data=sum%10;
	return sum/10;
}

struct node *add::add_one(struct node *start)
{
	int carry;
	carry=add_carry(start);
	if(carry==1)
	{
		ptr1=new struct node;
		ptr1->data=carry;
		ptr1->next=start;
		start=ptr1;
	}
	return start;
}

void add::traversal(struct node *start)
{
	cout<<"List after adding"<<endl;
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
	add ob;
	ob.creation(&start);
	start=ob.add_one(start);
	ob.traversal(start);
}
