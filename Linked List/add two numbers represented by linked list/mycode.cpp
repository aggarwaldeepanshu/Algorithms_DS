#include<iostream>
using namespace std;

struct node
{
	int data;
	struct node *next;
};

class add
{
	private:
		struct node *start;
	public:
		add()
		{
			start=NULL;
		}
		void add_list(struct node**,struct node**);
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

void add::add_list(struct node** start1,struct node** start2)
{
	int carry=0,sum;
	struct node *ptr1,*ptr2,*ptr,*temp;
	ptr=new struct node;
	start=ptr;
	ptr->next=NULL;
	ptr1=(*start1);
	ptr2=(*start2);
	while(ptr1!=NULL&&ptr2!=NULL)
	{
		temp=new struct node;
		sum=ptr1->data+ptr2->data+carry;
		carry=sum/10;
		temp->data=sum%10;
		temp->next=NULL;
		ptr->next=temp;
		ptr=ptr->next;
		ptr1=ptr1->next;
		ptr2=ptr2->next;
	}
	if(ptr1==NULL)
	{
		while(ptr2!=NULL)
		{
			temp=new struct node;
			sum=ptr2->data+carry;
			carry=sum/10;
			temp->data=sum%10;
			temp->next=NULL;
			ptr->next=temp;
			ptr=ptr->next;
			ptr2=ptr2->next;
		}
	}
	else if(ptr2==NULL)
	{
		while(ptr1!=NULL)
		{
			temp=new struct node;
			sum=ptr1->data+carry;
			carry=sum/10;
			temp->data=sum%10;
			temp->next=NULL;
			ptr->next=temp;
			ptr=ptr->next;
			ptr1=ptr1->next;
		}
	}
}

void add::traversal()
{
	struct node *ptr2;
	cout<<"List after adding:"<<endl;
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
	add ob;
	creation(&start1);
	creation(&start2);
	ob.add_list(&start1,&start2);
	ob.traversal();
}
