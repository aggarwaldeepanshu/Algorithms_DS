#include<iostream>
using namespace std;

struct node
{
	int data;
	struct node *next;
};

class union_intersection
{
	private:
		struct node *start3,*start4;
	public:
		union_intersection()
		{
			start3=new struct node;
			start4=new struct node;
			start3->next=NULL;
			start4->next=NULL;
			start3->data=start4->data=-1;
		}
		void union_intersection_list(struct node**,struct node**);
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
		while(fast!=NULL&&fast->next!=NULL)
		{
			slow=slow->next;
			fast=fast->next->next;
		}
		(*a)=start;
		(*b)=slow->next;
		slow->next=NULL;
	}
}

struct node *merge(struct node *a,struct node *b)
{
	if(a==NULL)
		return b;
	else if(b==NULL)
		return a;
	struct node *temp;
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

void union_intersection::union_intersection_list(struct node** start1,struct node** start2)
{
	struct node *ptr1,*ptr2,*ptr,*temp1,*ptr3,*ptr4;
	merge_sort(start1);
	merge_sort(start2);
	ptr1=(*start1);
	ptr2=(*start2);
	ptr3=start3;
	ptr4=start4;
	while(ptr1!=NULL&&ptr2!=NULL)
	{
		if(ptr1->data<ptr2->data)
		{
			ptr3->next=ptr1;
			ptr1=ptr1->next;
			ptr3->next->next=NULL;
			ptr3=ptr3->next;
		}
		else if(ptr1->data>ptr2->data)
		{
			ptr3->next=ptr2;
			ptr2=ptr2->next;
			ptr3->next->next=NULL;
			ptr3=ptr3->next;
		}
		else
		{
			ptr3->next=ptr1;
			ptr4->next=ptr2;
			ptr1=ptr1->next;
			ptr2=ptr2->next;
			ptr3->next->next=NULL;
			ptr4->next->next=NULL;
			ptr3=ptr3->next;
			ptr4=ptr4->next;
		}
	}
	if(ptr1==NULL)
	{
		while(ptr2!=NULL)
		{
			ptr3->next=ptr2;
			ptr2=ptr2->next;
			ptr3->next->next=NULL;
			ptr3=ptr3->next;
		}
	}
	else if(ptr2==NULL)
	{
		while(ptr1!=NULL)
		{
			ptr3->next=ptr1;
			ptr1=ptr1->next;
			ptr3->next->next=NULL;
			ptr3=ptr3->next;
		}
	}
}

void union_intersection::traversal()
{
	struct node *ptr1,*ptr2;
	cout<<"Union:"<<endl;
	ptr1=start3;
	ptr1=ptr1->next;
	while(ptr1!=NULL)
	{
		cout<<ptr1->data<<" ";
		ptr1=ptr1->next;
	}
	cout<<endl;
	cout<<"Intersection:"<<endl;
	ptr2=start4;
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
	union_intersection ob;
	creation(&start1);
	creation(&start2);
	ob.union_intersection_list(&start1,&start2);
	ob.traversal();
}
