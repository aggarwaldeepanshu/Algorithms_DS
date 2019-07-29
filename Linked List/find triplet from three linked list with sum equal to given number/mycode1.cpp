#include<iostream>
using namespace std;

struct node
{
	int data;
	struct node *next;
};

class search_pair
{
	public:
		void find_sum(struct node **,struct node **,struct node **);
};

void creation(struct node **start)
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

void partition(struct node *start,struct node **a,struct node **b)
{
	struct node *fast,*slow;
	if(start==NULL||start->next==NULL)
	{
		(*a)=start;
		(*b)=NULL;
	}
	else
	{
		slow=start;
		fast=start->next;
		while(fast!=NULL)
		{
			fast=fast->next;
			if(fast!=NULL)
			{
				slow=slow->next;
				fast=fast->next;
			}
		}
		(*a)=start;
		(*b)=slow->next;
		slow->next=NULL;
	}

}

struct node* merge(struct node *a,struct node *b)
{
	struct node *temp;
	if(a==NULL)
		return b;
	else if(b==NULL)
		return a;
	if(a->data<=b->data)
	{
		temp=a;
		temp->next=merge(a->next,b);
	}

	else
	{
		temp=b;
		temp->next=merge(a,b->next);
	}
	return temp;
}

void merge_sort(struct node **start)
{
	struct node *a,*b;
	if((*start)==NULL||(*start)->next==NULL)
		return;

	partition((*start),&a,&b);
	merge_sort(&a);
	merge_sort(&b);
	(*start)=merge(a,b);
}

void reverse(struct node **start)
{
	struct node *ptr1,*ptr2,*ptr3;
	ptr1=(*start);
	ptr2=ptr1;
	ptr1=ptr1->next;
	ptr2->next=NULL;
	while(ptr1!=NULL)
	{
		ptr3=ptr1->next;
		ptr1->next=ptr2;
		ptr2=ptr1;
		ptr1=ptr3;
	}
	(*start)=ptr2;
}

void search_pair::find_sum(struct node **start1,struct node **start2,struct node **start3)
{
	int num,sum=0;
	cout<<"Enter the number"<<endl;
	cin>>num;
	struct node *ptr3,*ptr1,*ptr2;
	merge_sort(start2);
	merge_sort(start3);
	reverse(start3);
	ptr1=(*start1);
	while(ptr1!=NULL)
	{
		ptr2=(*start2);
		ptr3=(*start3);
		while(ptr2!=NULL&&ptr3!=NULL)
		{
			sum=ptr1->data+ptr2->data+ptr3->data;
			if(sum==num)
			{
				cout<<"The required pair is: "<<endl;
				cout<<ptr1->data<<" "<<ptr2->data<<" "<<ptr3->data<<endl;
				break;
			}
			else if(sum<num)
			{
				ptr2=ptr2->next;
			}
			else if(sum>num)
			{
				ptr3=ptr3->next;
			}
		}
		ptr1=ptr1->next;
	}
}

int main(void)
{
	struct node *start1,*start2,*start3;
	search_pair ob;
	creation(&start1);
	creation(&start2);
	creation(&start3);
	ob.find_sum(&start1,&start2,&start3);
}
