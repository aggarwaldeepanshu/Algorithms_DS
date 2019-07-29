#include<iostream>
using namespace std;

struct node
{
	int x,y;
	struct node *next;
};

class line_segments
{
	private:
		struct node *start,*ptr1,*ptr2,*ptr3;
	public:
		line_segments()
		{
			start=NULL;
		}
		void creation();
		void remove_middle();
		void traversal();
};

void line_segments::creation()
{
	int x,y,n;
	ptr1=new struct node;
	cout<<"Enter the value for first node"<<endl;
	cin>>x>>y;
	ptr1->x=x;
	ptr1->y=y;
	ptr1->next=NULL;
	start=ptr1;
	cout<<"Enter -1 to exit"<<endl;
	cin>>x>>y;
	while(x!=-1&&y!=-1)
	{
		ptr2=ptr1;
		ptr1=new struct node;
		ptr1->x=x;
		ptr1->y=y;
		ptr1->next=NULL;
		ptr2->next=ptr1;
		cin>>x>>y;
	}
}

void line_segments::remove_middle()
{
	ptr1=start;
	ptr2=ptr1->next;
	while(ptr1!=NULL&&ptr2!=NULL)
	{
		if(ptr1->y==ptr2->y||ptr1->x==ptr2->x)
		{
			if(ptr1->y==ptr2->y)
				while(ptr2->next!=NULL&&ptr2->y==ptr2->next->y)
				{
					ptr1->next=ptr2->next;
					delete ptr2;
					ptr2=ptr1->next;
				}

			if(ptr1->x==ptr2->x)
				while(ptr2->next!=NULL&&ptr2->x==ptr2->next->x)
				{
					ptr1->next=ptr2->next;
					delete ptr2;
					ptr2=ptr1->next;
				}
		}
		ptr1=ptr2;
		ptr2=ptr2->next;
	}
}

void line_segments::traversal()
{
	cout<<"Traversal"<<endl;
	ptr2=start;
	while(ptr2!=NULL)
	{
		cout<<"("<<ptr2->x<<","<<ptr2->y<<") ";
		ptr2=ptr2->next;
	}
	cout<<endl;
}

int main(void)
{
	line_segments ob;
	ob.creation();
	ob.traversal();
	ob.remove_middle();
	ob.traversal();
}
