#include<bits/stdc++.h>
using namespace std;

typedef unordered_set<int> unordered;

struct node
{
	int data;
	struct node *next;
};

class duplicates
{
	private:
		struct node *start,*ptr2,*ptr1;
		unordered arr;
	public:
		duplicates()
		{
			start=NULL;
		}
		void creation();
		void remove_duplicate();
		void traversal();
};

void duplicates::creation()
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

void duplicates::remove_duplicate()
{
	ptr1=start;
	ptr2=NULL;
	while(ptr1!=NULL&&ptr1->next!=NULL)
	{
		if(arr.find(ptr1->data)!=arr.end())
		{
			ptr2->next=ptr1->next;
			delete ptr1;
		}
		else
		{
			arr.insert(ptr1->data);
			ptr2=ptr1;
		}
		ptr1=ptr2->next;
	}
}

void duplicates::traversal()
{
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
	duplicates ob;
	ob.creation();
	ob.traversal();
	ob.remove_duplicate();
	ob.traversal();
}
