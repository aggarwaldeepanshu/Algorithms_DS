#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

struct node
{
	int data;
	struct node *next;
};

class random_number
{
	private:
		struct node *start,*ptr1,*ptr2;
	public:
		random_number()
		{
			start=NULL;
		}
		void creation();
		void random_node();
};

void random_number::creation()
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

void random_number::random_node()
{
	int n,result;
	srand(time(NULL));
	ptr1=start;
	result=start->data;
	for(n=2;ptr1!=NULL;n++)
	{
		if(rand()%n==0)
			result=ptr1->data;
		ptr1=ptr1->next;
	}
	cout<<"Random number generated is "<<result<<endl;
}

int main(void)
{
	random_number ob;
	ob.creation();
	ob.random_node();
}
