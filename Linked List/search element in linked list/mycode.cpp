#include<iostream>
#include<cstdlib>
using namespace std;
struct node
{
	int data;
	struct node *next;
};

class search
{
	private:
		struct node *start,*ptr1,*ptr2;
	public:
		search()
		{
			start=NULL;
		}
		void creation();
		void find_element(int);
		void traversal();
};

void search::creation()
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

void search::find_element(int val)
{
	ptr1=start;

	while(ptr1->next!=NULL&&ptr1->data!=val)
		ptr1=ptr1->next;

	if(ptr1->next==NULL&&ptr1->data!=val)
		cout<<"Not present"<<endl;
	else
		cout<<"Present"<<endl;
}

void search::traversal()
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
	search ob;
	ob.creation();
	ob.traversal();
	ob.find_element(5);
	ob.find_element(100);
	ob.find_element(7);
}
