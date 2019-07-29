#include<iostream>
#include<cstdlib>
using namespace std;
struct node
{
	int data;
	struct node *next;
};

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
		void delete_node1(int);
		void delete_node2(int);
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
}
//to delete a node with given 'key'
void deletion::delete_node1(int val)
{
	ptr1=start;
	while(ptr1->next!=NULL&&ptr1->next->data!=val)
		ptr1=ptr1->next;
	if(ptr1->next==NULL)
		cout<<"Value not present"<<endl;
	ptr2=ptr1->next;
	ptr1->next=ptr1->next->next;
	delete ptr2;
}
//to delete a node with given 'position'
void deletion::delete_node2(int pos)
{
	int count=0;
	ptr1=start;
	while(count!=pos)
	{
		ptr2=ptr1;
		ptr1=ptr1->next;
		count++;
	}
	ptr2->next=ptr1->next;
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
	deletion ob;
	ob.creation();
	ob.traversal();
	ob.delete_node1(4);
	ob.traversal();
	ob.delete_node2(1);
	ob.traversal();
}
