#include<iostream>
#include<cstdlib>
using namespace std;
struct node
{
	char data;
	struct node *next;
};

class palindrome
{
	private:
		struct node *start,*ptr1,*ptr2,*ptr;
	public:
		palindrome()
		{
			start=NULL;
		}
		void creation();
		int find_middle();
		void check_palindrome();
		void traversal();
};

void palindrome::creation()
{
	char n;
	ptr1=new struct node;
	cout<<"Enter the value for first node"<<endl;
	cin>>n;
	ptr1->data=n;
	ptr1->next=NULL;
	start=ptr1;
	cout<<"Enter A to exit"<<endl;
	cin>>n;
	while(n!='A')
	{
		ptr2=ptr1;
		ptr1=new struct node;
		ptr1->data=n;
		ptr1->next=NULL;
		ptr2->next=ptr1;
		cin>>n;
	}
}

int palindrome::find_middle()
{
	int count=0,pos;
	ptr1=start;
	while(ptr1!=NULL)
	{
		count++;
		ptr1=ptr1->next;
	}
	if(count%2==0)
		pos=count/2;
	else
		pos=count/2+1;
	return pos;
}

void palindrome::check_palindrome()
{
	struct node *ptr3;
	int i=0,pos;

	pos=find_middle();
	ptr1=start;
	while(i!=pos)
	{
		ptr2=ptr1;
		ptr1=ptr1->next;
		i++;
	}

	ptr3=ptr2;
	while(ptr1!=NULL)
	{
		ptr=ptr1->next;
		ptr1->next=ptr2;
		ptr2=ptr1;
		ptr1=ptr;
	}

	ptr1=start;
	while(ptr2!=ptr3)
	{
		if(ptr2->data!=ptr1->data)
		{
			cout<<"Not a palindrome"<<endl;
			break;
		}
		ptr2=ptr2->next;
		ptr1=ptr1->next;
	}
	if(ptr3==ptr2)
		cout<<"Is a palindrome"<<endl;
}

void palindrome::traversal()
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
	palindrome ob;
	ob.creation();
	ob.traversal();
	ob.check_palindrome();
}
