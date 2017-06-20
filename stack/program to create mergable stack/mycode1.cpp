#include<iostream>
using namespace std;

struct node
{
	int data;
	struct node *next;
};

class Stack
{
	private:
		struct node *last;

	public:
		Stack()
		{
			last=NULL;
		}
		struct node *push(struct node *,int);
		int pop(struct node *);
		void display(struct node *);
		void MergeList(struct node *,struct node *);
};

void Stack::MergeList(struct node *last,struct node *start2)
{
	last->next=start2;
}

struct node *new_node(int data)
{
	struct node *ptr=new struct node;
	ptr->data=data;
	ptr->next=NULL;
	return ptr;
}

void Stack::display(struct node *start)
{
	struct node *ptr=start;
	while(ptr!=NULL)
	{
		cout<<ptr->data<<" ";
		ptr=ptr->next;
	}
	cout<<endl;
}

int Stack::pop(struct node *start)
{
	int temp;
	temp=start->data;
	struct node *ptr=start;
	start=start->next;
	delete ptr;
	return temp;
}

struct node *Stack::push(struct node *start,int num)
{
	struct node *ptr=new_node(num);

	if(start==NULL)
	{
		start=ptr;
		return start;
	}
	ptr->next=start;
	start=ptr;

	return start;
}

int main(void)
{
	Stack ob;
	int num;
	struct node *start1,*start2,*last;
	start1=NULL;
	start2=NULL;
	cout<<"enter -1 to exit"<<endl;
	cout<<"create list 1"<<endl;
	cin>>num;
	while(num!=-1)
	{
		start1=ob.push(start1,num);
		cin>>num;
	}

	last=start1;
	while(last->next!=NULL)
		last=last->next;

	cout<<"create list 2"<<endl;
	cin>>num;
	while(num!=-1)
	{
		start2=ob.push(start2,num);
		cin>>num;
	}
	cout<<"first list is"<<endl;
	ob.display(start1);

	cout<<"second list is"<<endl;
	ob.display(start2);

	ob.MergeList(last,start2);
	cout<<"list after merging"<<endl;
	ob.display(start1);
}
