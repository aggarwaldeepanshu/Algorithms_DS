#include<iostream>
#include<cstdlib>
using namespace std;
struct node
{
	int data;
	struct node *next;
};

struct node *start1;

class deletion
{
	private:
		struct node *start,*ptr1,*ptr2;
	public:
		deletion()
		{
			start=NULL;
		}
		void creation();
		void delete_node(struct node*);
		void traversal();
};

void deletion::creation()
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
	start1=start;
}

void deletion::delete_node(struct node *ptr)
{
	ptr1=ptr->next;
	ptr->data=ptr1->data;
	ptr->next=ptr1->next;
	delete ptr1;
}


void deletion::traversal()
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
	int pos,i;
	struct node *ptr;
	ptr=start1;
	i=0;
	deletion ob;
	ob.creation();
	ob.traversal();
	ob.delete_node(start1);
	ob.traversal();
}
