#include<iostream>
using namespace std;
struct node
{
	int data;
	struct node *next;
};

class intersect
{
	private:
		struct node *start;
	public:
		intersect()
		{
			start=NULL;
		}
		void intersect_point(struct node**,struct node**);
};

void creation(struct node** start1,struct node** start2)
{
	struct node* ptr1;
	(*start1)=new struct node;  
	(*start1)->data =10;
	(*start2)=new struct node; 
	(*start2)->data=3;
	ptr1=new struct node;
	ptr1->data=6;
	(*start2)->next=ptr1;
	ptr1=new struct node;
	ptr1->data=9;
	(*start2)->next->next=ptr1; 
	ptr1=new struct node;
	ptr1->data=15;
	(*start1)->next=ptr1;
	(*start2)->next->next->next=ptr1;   
	ptr1=new struct node;
	ptr1->data=30;
	(*start1)->next->next=ptr1;
	(*start1)->next->next->next=NULL;
}

void reverse(struct node*** start)
{

	struct node *ptr1,*ptr2,*ptr3;
	ptr1=(**start);
	ptr1=ptr1->next;
	ptr2=(**start);
	ptr2->next=NULL;
	while(ptr1!=NULL)
	{
		ptr3=ptr1->next;
		ptr1->next=ptr2;
		ptr2=ptr1;
		ptr1=ptr3;
	}
	(**start)=ptr2;
}

void intersect::intersect_point(struct node** start1,struct node** start2)
{
	int c1=0,c2=0,c3=0,i,v;
	struct node *ptr1,*ptr2,*ptr3,*ptr;
	ptr1=(*start1);
	ptr=(*start2);
	while(ptr1!=NULL)
	{
		c1++;
		ptr1=ptr1->next;
	}
	while(ptr!=NULL)
	{
		c2++;
		ptr=ptr->next;
	}
	ptr=(*start2);

	reverse(&start1);
	while(ptr!=NULL)
	{
		c3++;
		ptr=ptr->next;
	}
	ptr=(*start2);
	v=(c2-c1+c3)/2;
	i=0;
	while(i!=v)
	{
		ptr=ptr->next;
		i++;
	}
	if(ptr==NULL)
		cout<<"No intersection"<<endl;
	else
		cout<<"Intersection point is "<<ptr->data<<endl;
}

int main(void)
{
	struct node *start1,*start2;
	intersect ob;
	creation(&start1,&start2);
	//creation(&start2);
	ob.intersect_point(&start1,&start2);
}
