#include<iostream>
using namespace std;

struct node
{
	int data;
	struct node *next;
};

class loop
{
	public:
		void creation(struct node **);
		void detect_and_remove_loop(struct node **);
		void traversal(struct node **);
};

void loop::creation(struct node **start)
{
	struct node *ptr1,*ptr2;
	ptr1=new struct node;
	ptr1->data=50;
	ptr1->next=NULL;
	(*start)=ptr1;
	ptr2=new struct node;
	ptr2->data=20;
	ptr2->next=NULL;
	(*start)->next=ptr2;
	ptr2=new struct node;
	ptr2->data=15;
	ptr2->next=NULL;
	(*start)->next->next=ptr2;
	ptr2=new struct node;
	ptr2->data=4;
	ptr2->next=NULL;
	(*start)->next->next->next=ptr2;
	ptr2=new struct node;
	ptr2->data=10;
	ptr2->next=NULL;
	(*start)->next->next->next->next=ptr2;

	(*start)->next->next->next->next->next=(*start)->next->next;
}

void loop::detect_and_remove_loop(struct node **start)
{
	struct node *ptr1,*ptr2;
	ptr1=(*start);
	ptr2=NULL;
	while(ptr1!=NULL)
	{
		if(ptr1->data<0)
		{
			cout<<"Loop found"<<endl;
			ptr2->next=NULL;
			break;
		}

		ptr1->data=-ptr1->data;
		ptr2=ptr1;
		ptr1=ptr1->next;
	}
	if(ptr1==NULL)
		cout<<"No loop detected"<<endl;
}

void loop::traversal(struct node **start)
{
	struct node *ptr2;
	cout<<"Traversal"<<endl;
	ptr2=(*start);
	while(ptr2!=NULL)
	{
		cout<<-ptr2->data<<" ";
		ptr2=ptr2->next;
	}
	cout<<endl;
}

int main(void)
{
	struct node *start;
	loop ob;
	ob.creation(&start);
	ob.detect_and_remove_loop(&start);
	ob.traversal(&start);
}
