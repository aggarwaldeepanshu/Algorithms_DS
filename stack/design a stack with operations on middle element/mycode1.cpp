#include<iostream>
using namespace std;

struct node
{
	int data;
	struct node *prev,*next;
};

class Stack
{
	private:
		int count;
		struct node *middle;
	public:
		Stack()
		{
			count=0;
			middle=NULL;
		}
		struct node *push(struct node *,int);
		int pop(struct node *);
		int findMiddle(void);
		int deleteMiddle(void);
};

struct node *new_node(int data)
{
	struct node *ptr=new struct node;
	ptr->data=data;
	ptr->prev=NULL;
	ptr->next=NULL;
	return ptr;
}

int Stack::deleteMiddle(void)
{
	int temp;
	struct node *ptr;

	if(middle->prev)
		ptr=middle->prev;

	else if(middle->next)
		ptr=middle->next;

	else
		ptr=NULL;

	temp=middle->data;

	middle->prev->next=middle->next;
	middle->next->prev=middle->prev;

	delete middle;

	count--;

	if(count&1)
		middle=ptr;

	else
		middle=ptr->next;

	return temp;
}

int Stack::findMiddle(void)
{
	if(middle==NULL)
		return -1;

	return middle->data;
}

int Stack::pop(struct node *start)
{
	int temp;
	temp=start->data;
	struct node *ptr=start;
	start=start->next;
	start->prev=NULL;
	delete ptr;
	return temp;
}

struct node *Stack::push(struct node *start,int num)
{
	struct node *ptr=new_node(num);

	if(start==NULL)
	{
		start=ptr;
		count=1;
		middle=ptr;
		return start;
	}
	count++;
	ptr->next=start;
	ptr->next->prev=ptr;
	start=ptr;

	if(count%2!=0)
		middle=middle->prev;
	return start;
}

int main(void)
{
	Stack ob;
	int num;
	struct node *start=NULL;
	cout<<"enter -1 to exit"<<endl;
	cin>>num;
	while(num!=-1)
	{
		start=ob.push(start,num);
		cin>>num;
	}
	cout<<"middle element is "<<ob.findMiddle()<<endl;
	cout<<"deleted element is "<<ob.pop(start)<<endl;
	cout<<"middle element after deleting element is "<<ob.findMiddle()<<endl;
}
