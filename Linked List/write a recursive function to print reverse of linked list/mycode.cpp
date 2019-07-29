#include<iostream>
using namespace std;

struct node
{
	int data;
	struct node *next;
};

class reverse
{
	private:
		struct node *start,*ptr2;
	public:
		reverse()
		{
			start=NULL;
		}
		void creation(struct node**);
		void print_reverse(struct node*);
		void traversal();
};

void reverse::creation(struct node** ptr4)
{
	int n;
	struct node *ptr1;
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
	(*ptr4)=start;
}

void reverse::print_reverse(struct node* ptr)
{
	if(ptr==NULL)
		return;
	print_reverse(ptr->next);
	cout<<ptr->data<<" ";
}

void reverse::traversal()
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
	struct node *ptr4;
	reverse ob;
	ob.creation(&ptr4);
	ob.traversal();
	ob.print_reverse(ptr4);
}
