#include<iostream>
using namespace std;

struct node
{
	int data;
	struct node *next;
};

class merge
{
	public:
		void merge_list(struct node**,struct node**);
		void traversal(struct node *,struct node *);
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
	struct node *ptr1,*ptr2,*ptr3,*ptr4;
	ptr1=(*start1);
	ptr2=(*start2);
	while(ptr1!=NULL&&ptr2!=NULL)
	{
		ptr3=ptr1->next;
		ptr1->next=ptr2;
		ptr2=ptr2->next;
		ptr1->next->next=ptr3;
		ptr1=ptr1->next->next;
	}
	if(ptr1==NULL)
		(*start2)=ptr2;
	else if(ptr2==NULL)
		(*start2)=NULL;
}

void merge::traversal(struct node *start1,struct node *start2)
{
	struct node *ptr1,*ptr2;
	cout<<"List after merging:"<<endl;
	ptr1=start1;
	ptr2=start2;
	while(ptr1!=NULL)
	{
		cout<<ptr1->data<<" ";
		ptr1=ptr1->next;
	}
	cout<<endl;
	while(ptr2!=NULL)
	{
		cout<<ptr2->data<<" ";
		ptr2=ptr2->next;
	}
}

int main(void)
{
	struct node *start1,*start2;
	merge ob;
	creation(&start1);
	creation(&start2);
	ob.merge_list(&start1,&start2);
	ob.traversal(start1,start2);
}
