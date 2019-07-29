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
		struct node *start,*ptr1,*ptr2;
	public:
		reverse()
		{
			start=new struct node;
		}
		void creation();
		void reverse_list();
		void traversal();
};

void reverse::creation()
{
	int n;
	ptr1=new struct node;
	cout<<"Enter the value for first node"<<endl;
	cin>>n;
	ptr1->data=n;
	ptr1->next=NULL;
	start->data=-1;
	start->next=ptr1;
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

void reverse::reverse_list()
{
	int i=1,k;
	cout<<"Enter the value of k"<<endl;
	cin>>k;
	struct node *ptr,*temp,*ptr3;
	ptr=start;
	ptr3=ptr;
	ptr=ptr->next;
	while(ptr!=NULL&&ptr->next!=NULL)
	{
		ptr1=ptr;
		ptr=ptr->next;
		temp=ptr1;
		while(i<k&&ptr!=NULL)
		{
			i++;
			ptr2=ptr->next;
			ptr->next=ptr1;
			ptr1=ptr;
			ptr=ptr2;
		}

		temp->next=ptr;
		ptr3->next=ptr1;
		ptr3=temp;
		temp=ptr;

		if(i==k)
			while(i>0&&ptr!=NULL)
			{
				ptr1=ptr;
				ptr=ptr->next;
				i--;
			}
		ptr3=ptr1;
		i=1;
	}
}

void reverse::traversal()
{
	cout<<"Traversal"<<endl;
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
	reverse ob;
	ob.creation();
	ob.traversal();
	ob.reverse_list();
	ob.traversal();
}
