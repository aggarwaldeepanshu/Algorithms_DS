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
		struct node *start,*ptr1,*ptr2;
	public:
		sort()
		{
			start=NULL;
		}
		void creation();
		void sort_list();
		void traversal();
};

void sort::creation()
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

void sort::sort_list()
{
	int c0=0,c1=0,c2=0;
	ptr1=start;
	while(ptr1!=NULL)
	{
		if(ptr1->data==0)
			c0++;
		else if(ptr1->data==1)
			c1++;
		else
			c2++;
		ptr1=ptr1->next;
	}
	ptr1=start;
	while(ptr1!=NULL)
	{
		while(c0>0)
		{
			ptr1->data=0;
			ptr1=ptr1->next;
			c0--;
		}
		while(c1>0)
		{
			ptr1->data=1;
			ptr1=ptr1->next;
			c1--;
		}
		while(c2>0)
		{
			ptr1->data=2;
			ptr1=ptr1->next;
			c2--;
		}
	}

}

void sort::traversal()
{
	cout<<"List after sorting"<<endl;
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
	sort ob;
	ob.creation();
	ob.sort_list();
	ob.traversal();
}
