#include<iostream>
using namespace std;

struct node
{
	int data;
	struct node *next;
};

class sort
{
	private:
		struct node *ptr1,*ptr2;
	public:
		void creation(struct node **);
		void insertion_sort(struct node **);
		void traversal(struct node *);
};

void sort::creation(struct node **start)
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

void sortfunction(struct node **start,struct node *ptr)
{
	struct node *ptr1,*ptr2;
	if((*start)==NULL||(*start)->data>ptr->data)
	{
		ptr->next=(*start);
		(*start)=ptr;
	}
	else
	{
		ptr1=(*start);
		while(ptr1->next!=NULL&&ptr1->next->data<ptr->data)
			ptr1=ptr1->next;

		ptr->next=ptr1->next;
		ptr1->next=ptr;
	}
}

void sort::insertion_sort(struct node **start)
{
	struct node *start1=NULL;
	ptr1=(*start);
	while(ptr1!=NULL)
	{
		ptr2=ptr1->next;
		sortfunction(&start1,ptr1);
		ptr1=ptr2;
	}
	(*start)=start1;
}

void sort::traversal(struct node *start)
{
	cout<<"List after sorting"<<endl;
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
	sort ob;
	struct node *start;
	ob.creation(&start);
	ob.insertion_sort(&start);
	ob.traversal(start);
}
