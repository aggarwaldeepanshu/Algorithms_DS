#include<iostream>
#include<cstdlib>
using namespace std;
struct node
{
	int data;
	struct node *next;
};

class merge
{
	private:
		struct node *start;
	public:
		merge()
		{
			start=NULL;
		}
		void merge_list(struct node**,struct node**);
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

void merge::merge_list(struct node** start1,struct node** start2)
{
	struct node *ptr1,*ptr2,*ptr;
	ptr1=(*start1);
	ptr2=(*start2);
	if(ptr1->data>ptr2->data)
	{
		start=ptr2;
		ptr2=ptr2->next;
	}
	else
	{
		start=ptr1;
		ptr1=ptr1->next;
	}

	ptr=start;
	while(ptr1!=NULL&&ptr2!=NULL)
	{
		if(ptr1->data>ptr2->data)
		{
			ptr->next=ptr2;
			ptr2=ptr2->next;
			ptr=ptr->next;
		}
		else
		{
			ptr->next=ptr1;
			ptr1=ptr1->next;
			ptr=ptr->next;
		}
	}
	if(ptr1==NULL)
	{
		while(ptr2!=NULL)
		{
			ptr->next=ptr2;
			ptr2=ptr2->next;
			ptr=ptr->next;
		}
	}
	else if(ptr2==NULL)
	{
		while(ptr1!=NULL)
		{
			ptr->next=ptr1;
			ptr1=ptr1->next;
			ptr=ptr->next;
		}
	}
	ptr=NULL;
}

void merge::traversal()
{
	struct node *ptr2;
	cout<<"List after merging:"<<endl;
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
	struct node *start1,*start2;
	merge ob;
	creation(&start1);
	creation(&start2);
	ob.merge_list(&start1,&start2);
	ob.traversal();
}
