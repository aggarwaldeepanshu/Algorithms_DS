#include<iostream>
using namespace std;

struct node
{
int data;
struct node *next;
};

class split
{
private:
struct node *start,*ptr1,*ptr2,*ptr,*start1;
public:
split()
{
start=NULL;
}
void creation();
void split_node();
void traversal();
};

void split::creation()
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

void split::split_node()
{
ptr=start;
ptr=ptr->next;
start1=ptr;
ptr1=start;
while(ptr!=NULL&&ptr->next!=NULL)
{
ptr2=ptr->next;
ptr->next=ptr2->next;
ptr1->next=ptr2;
ptr=ptr->next;
ptr1=ptr1->next;
}
ptr1->next=NULL;
}

void split::traversal()
{
cout<<"The list after splitting the original list"<<endl;
ptr2=start;
ptr1=start1;
while(ptr1!=NULL)
{
cout<<ptr1->data<<" ";
ptr1=ptr1->next;
}
cout<<endl;

while(ptr2!=NULL)
{
cout<<ptr2->data<<" ";
ptr2=ptr2->next;
}
cout<<endl;
}

int main(void)
{
split ob;
ob.creation();
//ob.traversal();
ob.split_node();
ob.traversal();
}
