#include<iostream>
using namespace std;

struct node
{
	int data;
	struct node *next;
};

class identical
{
	private:
		struct node *start;
	public:
		identical()
		{
			start=NULL;
		}
		void identical_list(struct node**,struct node**);
		//void traversal();
};

void creation(struct node** start)
{
	struct node *ptr1,*ptr2;
	int n;
	ptr1=new struct node;
	cout<<"Enter the value for first node"<<endl;
	cin>>n;
	ptr1->data=n;
	ptr1->next=NULL;
	(*start)=ptr1;
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

void identical::identical_list(struct node** start1,struct node** start2)
{
	bool check=true;
	struct node *ptr1,*ptr2,*ptr;
	ptr1=(*start1);
	ptr2=(*start2);
	while(ptr1!=NULL&&ptr2!=NULL)
	{
		if(ptr1->data!=ptr2->data)
		{
			check=false;
			break;
		}
		ptr1=ptr1->next;
		ptr2=ptr2->next;
	}

	if(ptr1==NULL && ptr2!=NULL||ptr2==NULL && ptr1!=NULL)
		check=false;

	if(check)
		cout<<"Lists are identical"<<endl;
	else
		cout<<"Lists are not identical"<<endl;
}

int main(void)
{
	struct node *start1,*start2;
	identical ob;
	creation(&start1);
	creation(&start2);
	ob.identical_list(&start1,&start2);
}
