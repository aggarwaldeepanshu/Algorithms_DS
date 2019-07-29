#include<iostream>
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
			start=new struct node;
			start->data=-1;
			start->next=NULL;
		}
		void maximum_sum(struct node**,struct node**);
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

void merge::maximum_sum(struct node** start1,struct node** start2)
{
	int sum1,sum2;
	struct node *ptr1,*ptr2,*ptr3,*ptr4,*ptr;
	ptr1=(*start1);
	ptr2=(*start2);
	ptr=start;
	ptr3=ptr1;
	ptr4=ptr2;
	while(ptr3!=NULL&&ptr4!=NULL)
	{
		sum1=sum2=0;
		while(ptr3!=NULL&&ptr4!=NULL&&ptr3->data!=ptr4->data)
		{
			if(ptr3->data>ptr4->data)
			{
				sum2+=ptr4->data;
				ptr4=ptr4->next;
			}
			else
			{
				sum1+=ptr3->data;
				ptr3=ptr3->next;
			}
		}
		if(ptr3!=NULL&&ptr4!=NULL&&ptr3->data==ptr4->data)
		{
			if(sum1>sum2)
			{
				ptr->next=ptr1;
				ptr=ptr3;
			}
			else
			{
				ptr->next=ptr2;
				ptr=ptr4;
			}
			ptr3=ptr3->next;
			ptr4=ptr4->next;
			ptr1=ptr3;
			ptr2=ptr4;
		}
		else if(ptr3==NULL||ptr4==NULL)
		{
			if(ptr3==NULL)
				while(ptr4!=NULL)
				{
					sum2+=ptr4->data;
					ptr4=ptr4->next;
				}
			else if(ptr4==NULL)
				while(ptr3!=NULL)
				{
					sum1+=ptr3->data;
					ptr3=ptr3->next;
				}
			if(sum1>sum2)
				ptr->next=ptr1;
			else
				ptr->next=ptr2;
		}
	}
}

void merge::traversal()
{
	struct node *ptr2;
	cout<<"List after merging:"<<endl;
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
	struct node *start1,*start2;
	merge ob;
	creation(&start1);
	creation(&start2);
	ob.maximum_sum(&start1,&start2);
	ob.traversal();
}
