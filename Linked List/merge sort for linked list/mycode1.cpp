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
		void merge_sort(struct node **);
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
		temp->next=combine(a->next,b);
	}

	else
	{
		temp=b;
		temp->next=combine(a,b->next);
	}
	return temp;
}

void sort::merge_sort(struct node **start)
{
	struct node *a,*b;
	if((*start)==NULL||(*start)->next==NULL)
		return;

	partition((*start),&a,&b);
	merge_sort(&a);
	merge_sort(&b);
	(*start)=combine(a,b);
}

void sort::traversal(struct node *start)
{
	cout<<"Traversal"<<endl;
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
	sort ob;
	ob.creation(&start);
	ob.traversal(start);
	ob.merge_sort(&start);
	ob.traversal(start);
}
