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
		struct node *start,*ptr1,*ptr2;
	public:
		sort()
		{
			start=NULL;
		}
		void creation();
		void sort_list();
		void traversal();
};

void sort::creation()
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

void merge(struct node **start,struct node *start1)
{
	struct node *ptr1,*ptr2,*ptr3,*start2;
	ptr3=new struct node;
	ptr3->next=NULL;
	ptr1=(*start);
	ptr2=start1;
	start2=ptr3;
	while(ptr1!=NULL&&ptr2!=NULL)
	{
		if(ptr1->data>ptr2->data)
		{
			ptr3->next=ptr2;
			ptr2=ptr2->next;
		}
		else if(ptr2->data>ptr1->data)
		{
			ptr3->next=ptr1;
			ptr1=ptr1->next;
		}
		else
		{
			ptr3->next=ptr1;
			ptr1=ptr1->next;
			ptr2=ptr2->next;
		}
		ptr3=ptr3->next;
	}
	if(ptr1==NULL)
	{
		while(ptr2!=NULL)
		{
			ptr3->next=ptr2;
			ptr2=ptr2->next;
			ptr3=ptr3->next;
		}
	}
	else if(ptr2==NULL)
	{
		while(ptr1!=NULL)
		{
			ptr3->next=ptr1;
			ptr1=ptr1->next;
			ptr3=ptr3->next;
		}
	}
	(*start)=start2;
}

void sort::sort_list()
{
	struct node *start1,*ptr3,*ptr4;
	ptr1=start;
	ptr1=ptr1->next;
	ptr2=start;
	ptr4=NULL;
       //to split and reverse one of the list 
	while(ptr1!=NULL&&ptr1->next!=NULL)
	{
		ptr3=ptr1->next->next;
		ptr2->next=ptr1->next;
		ptr1->next=ptr4;
		ptr4=ptr1;
		ptr1=ptr3;
		ptr2=ptr2->next;
	}
	ptr2->next=NULL;
	if(ptr1==NULL)
		start1=ptr4;
	else if(ptr1->next==NULL)
		start1=ptr1;
	merge(&start,start1);
}

void sort::traversal()
{
	cout<<"List after sorting"<<endl;
	ptr2=start;
	ptr2=ptr2->next;
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
	ob.creation();
	ob.traversal();
	ob.sort_list();
	ob.traversal();
}
