#include<iostream>
using namespace std;

struct node
{
	char data;
	struct node *next;
};

class compare_list
{
	public:
		void creation(struct node **);
		void compare_strings(struct node *,struct node *);
};

void compare_list::creation(struct node **start)
{
	struct node *ptr1,*ptr2;
	char n;
	ptr1=new struct node;
	cout<<"Enter the value for first node"<<endl;
	cin>>n;
	ptr1->data=n;
	ptr1->next=NULL;
	(*start)=ptr1;
	cout<<"Press Q to exit"<<endl;
	cin>>n;
	while(n!='Q')
	{
		ptr2=ptr1;
		ptr1=new struct node;
		ptr1->data=n;
		ptr1->next=NULL;
		ptr2->next=ptr1;
		cin>>n;
	}
}

void compare_list::compare_strings(struct node *start1,struct node *start2)
{
	int v=0;
	struct node *ptr1,*ptr2;
	ptr1=start1;
	ptr2=start2;
	while(ptr1!=NULL&&ptr2!=NULL)
	{
		if(ptr1->data==ptr2->data)
		{
			ptr1=ptr1->next;
			ptr2=ptr2->next;
		}
		else if(ptr1->data>ptr2->data)
		{
			v=1;
			break;
		}
		else
		{
			v=-1;
			break;
		}
	}
	if(v==0)
	{
		if(ptr1==NULL&&ptr2==NULL)
			cout<<0<<endl;
		else if(ptr1==NULL&&ptr2!=NULL)
			cout<<-1<<endl;
		else
			cout<<1<<endl;
	}
	else
		cout<<v<<endl;
}

int main(void)
{
	struct node *start1,*start2;
	compare_list ob;
	ob.creation(&start1);
	ob.creation(&start2);
	ob.compare_strings(start1,start2);
}
