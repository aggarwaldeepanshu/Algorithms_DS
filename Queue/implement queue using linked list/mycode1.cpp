#include<iostream>
using namespace std;

struct node
{
	int data;
	struct node *next;
};

class queue
{
	private:
		struct node *front,*rear;

	public:
		queue()
		{
			rear=NULL;
			front=NULL;
		}
		void enqueue(int);
		int dequeue(void);
		void display(void);
};

struct node *new_node(int data)
{
	struct node *ptr=new struct node;
	ptr->data=data;
	ptr->next=NULL;
	return ptr;
}

void queue::display(void)
{
	struct node *ptr=front;
	while(ptr!=NULL)
	{
		cout<<ptr->data<<" ";
		ptr=ptr->next;
	}
	cout<<endl;
}

void queue::enqueue(int num)
{
	struct node *ptr=new_node(num);
	if(rear==NULL)
	{
		front=ptr;
		rear=ptr;
	}
	rear->next=ptr;
	rear=rear->next;
	return ;
}

int queue::dequeue(void)
{
	int temp;
	if(front==NULL)
		return -1;

	else if(front==rear)
	{
		temp=front->data;
		front=NULL;
		rear=NULL;
	}

	else
	{
		temp=front->data;
		front=front->next;
	}
	return temp;
}

int main(void)
{
	int num;
	queue ob;
	cout<<"enter -1 to exit"<<endl;
	cin>>num;
	while(num!=-1)
	{
		ob.enqueue(num);
		cin>>num;
	}
	cout<<"before removing"<<endl;
	ob.display();
	cout<<"element removed is "<<ob.dequeue()<<endl;
	cout<<"after removing"<<endl;
	ob.display();
}
