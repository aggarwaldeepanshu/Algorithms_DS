#include<iostream>
using namespace std;

struct node
{
	int data;
	struct node *next;
};

class swap_nodes
{
	private:
		struct node *start,*ptr1,*ptr2;
	public:
		swap_nodes()
		{
			start=NULL;
		}
		void creation();
		void pairwise_swap_nodes();
		void traversal();
};

void swap_nodes::creation()
{
	int n;
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
}

void swap_nodes::pairwise_swap_nodes()
{
	struct node *temp;
	ptr1=start;
	ptr2=ptr1->next;
	ptr1->next=ptr2->next;
	ptr2->next=ptr1;
	start=ptr2;
	temp=ptr1;
	ptr1=ptr1->next;
	while(ptr1!=NULL&&ptr1->next!=NULL)
	{
		ptr2=ptr1->next;
		ptr1->next=ptr2->next;
		ptr2->next=ptr1;
		temp->next=ptr2;
		temp=temp->next->next;
		ptr1=ptr1->next;
	}
}

void swap_nodes::traversal()
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
	swap_nodes ob;
	ob.creation();
	ob.traversal();
	ob.pairwise_swap_nodes();
	ob.traversal();
}
