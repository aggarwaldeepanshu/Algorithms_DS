#include<iostream>
using namespace std;

struct node
{
	int data;
	struct node *next;
};

class intersection
{
	private:
		struct node *start;
	public:
		intersection()
		{
			start=new struct node;
			start->data=-1;
			start->next=NULL;
		}
		void intersection_sortedlist(struct node**,struct node**);
		void traversal();
};

void creation(struct node** start)
{
	struct node *ptr1,*ptr2;
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

void intersection::intersection_sortedlist(struct node** start1,struct node** start2)
{
	struct node *ptr1,*ptr2,*ptr,*temp;
	ptr1=(*start1);
	ptr2=(*start2);
	ptr=start;
	while(ptr1!=NULL&&ptr2!=NULL)
	{
		if(ptr1->data==ptr2->data)
		{
			temp=new struct node;
			temp->data=ptr1->data;
			temp->next=NULL;
			ptr->next=temp;
			ptr=ptr->next;
			ptr1=ptr1->next;
			ptr2=ptr2->next;
		}
		else if(ptr1->data<ptr2->data)
		{
			ptr1=ptr1->next;
		}
		else
		{
			ptr2=ptr2->next;
		}
	}
}

void intersection::traversal()
{
	struct node *ptr2;
	cout<<"the required list"<<endl;
	ptr2=start->next;
	while(ptr2!=NULL)
	{
		cout<<ptr2->data<<" ";
		ptr2=ptr2->next;
	}
	cout<<endl;
}

int main(void)
{
	struct node *start1,*start2;
	intersection ob;
	creation(&start1);
	creation(&start2);
	ob.intersection_sortedlist(&start1,&start2);
	ob.traversal();
}
