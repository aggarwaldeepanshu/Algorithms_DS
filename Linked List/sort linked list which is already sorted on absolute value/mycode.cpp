#include<iostream>
using namespace std;

struct node
{
int data;
struct node *next;
};

class sort
{
private:
struct node *start,*ptr1,*ptr2;
public:
sort()
{
start=NULL;
}
void creation();
void sort_values();
void traversal();
};

void sort::creation()
{
int n;
ptr1=new struct node;
cout<<"Enter the value for first node"<<endl;
cin>>n;
ptr1->data=n;
ptr1->next=NULL;
start=ptr1;
cout<<"Enter 0 to exit"<<endl;
cin>>n;
while(n!=0)
{
ptr2=ptr1;
ptr1=new struct node;
ptr1->data=n;
ptr1->next=NULL;
ptr2->next=ptr1;
cin>>n;
}
}

void sort::sort_values()
{
struct node *start1,*ptr,*temp;
ptr=start1=start;
ptr1=ptr2=start1;
ptr=ptr->next;
ptr2->next=NULL;
while(ptr!=NULL)
{
if(ptr->data<ptr1->data)
{
temp=ptr->next;
ptr->next=start1;
start1=ptr;
ptr=temp;
}
else
{
ptr2->next=ptr;
ptr=ptr->next;
ptr2=ptr2->next;
ptr2->next=NULL;
}
}
start=start1;
}

void sort::traversal()
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
sort ob;
ob.creation();
ob.sort_values();
ob.traversal();
}
