#include<iostream>
using namespace std;

struct node
{
	int data;
	struct node *next,*child;
};

class flatten
{
	public:
		void flatten_list(struct node **);
		void traversal(struct node *);
};

struct node *create_list(int arr[],int size)
{
	int i;
	struct node *start=NULL;
	struct node *temp;
	for(i=0;i<size;i++)
	{
		if(start==NULL)
			start=temp=new struct node;
		else
		{
			temp->next=new struct node;
			temp=temp->next;
		}
		temp->data=arr[i];
		temp->next=temp->child=NULL;
	}
	return start;
}

struct node *creation()
{
	int arr1[]={10,5,12,7,11};
	int arr2[]={4,20,13};
	int arr3[]={17,6};
	int arr4[]={9,8};
	int arr5[]={19,15};
	int arr6[]={2};
	int arr7[]={16};
	int arr8[]={3};
	struct node *start1=create_list(arr1,5);
	struct node *start2=create_list(arr2,3);
	struct node *start3=create_list(arr3,2);
	struct node *start4=create_list(arr4,2);
	struct node *start5=create_list(arr5,2);
	struct node *start6=create_list(arr6,1);
	struct node *start7=create_list(arr7,1);
	struct node *start8=create_list(arr8,1);
	start1->child=start2;
	start1->next->next->next->child=start3;
	start3->child=start4;
	start4->child=start5;
	start2->next->child=start6;
	start2->next->next->child=start7;
	start7->child=start8;
	return start1;
}


void flatten::flatten_list(struct node **start)
{
	struct node *ptr1,*ptr2,*ptr3,*ptr;
	ptr1=(*start);
	ptr=(*start);

	while(ptr1->next!=NULL)
		ptr1=ptr1->next;

	while(ptr!=NULL)
	{
		if(ptr->child!=NULL)
		{
			ptr1->next=ptr->child;
			ptr->child=NULL;
			while(ptr1->next!=NULL)
				ptr1=ptr1->next;
		}
		ptr=ptr->next;
	}
}

void flatten::traversal(struct node *start)
{
	struct node *ptr2;
	cout<<"List after flattening"<<endl;
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
	struct node *start;
	flatten ob;
	start=creation();
	ob.flatten_list(&start);
	ob.traversal(start);
}
