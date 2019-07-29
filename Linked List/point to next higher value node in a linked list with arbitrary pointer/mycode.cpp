#include<iostream>
using namespace std;

struct node
{
	int data;
	struct node *next,*arbit;
};

class arbitrary
{
	private:
		struct node *ptr1,*ptr2;
	public:
		void creation(struct node **);
		void arbitrary_pointer(struct node **,struct node **);
		void traversal(struct node *,struct node *);
};

void arbitrary::creation(struct node **start)
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

void partition(struct node *start,struct node **a,struct node **b)
{
	struct node *fast,*slow;
	if(start==NULL||start->arbit==NULL)
	{
		(*a)=start;
		(*b)=NULL;
	}
	else
	{
		slow=start;
		fast=start->arbit;
		while(fast!=NULL)
		{
			fast=fast->arbit;
			if(fast!=NULL)
			{
				slow=slow->arbit;
				fast=fast->arbit;
			}
		}
		(*a)=start;
		(*b)=slow->arbit;
		slow->arbit=NULL;
	}

}

struct node* combine(struct node *a,struct node *b)
{
	struct node *temp;
	if(a==NULL)
		return b;
	else if(b==NULL)
		return a;
	if(a->data<=b->data)
	{
		temp=a;
		temp->arbit=combine(a->arbit,b);
	}

	else
	{
		temp=b;
		temp->arbit=combine(a,b->arbit);
	}
	return temp;
}

void merge_sort(struct node **start)
{
	struct node *a,*b;
	if((*start)==NULL||(*start)->arbit==NULL)
		return;

	partition((*start),&a,&b);
	merge_sort(&a);
	merge_sort(&b);
	(*start)=combine(a,b);
}

void arbitrary::arbitrary_pointer(struct node **start,struct node **start1)
{
	ptr1=(*start);
	while(ptr1!=NULL)
	{
		ptr1->arbit=ptr1->next;
		ptr1=ptr1->next;
	}
	(*start1)=(*start);
	merge_sort(start1);
}

void arbitrary::traversal(struct node *start,struct node *start1)
{
	cout<<"Traversal"<<endl;
	ptr2=start;
	while(ptr2!=NULL)
	{
		cout<<ptr2->data<<" ";
		ptr2=ptr2->next;
	}
	cout<<endl;
	ptr2=start1;
	while(ptr2!=NULL)
	{
		cout<<ptr2->data<<" ";
		ptr2=ptr2->arbit;
	}
	cout<<endl;
}

int main(void)
{
	struct node *start,*start1;
	arbitrary ob;
	ob.creation(&start);
	ob.arbitrary_pointer(&start,&start1);
	ob.traversal(start,start1);
}
