#include<iostream>
using namespace std;

struct node
{
int data;
struct node *next;
};

class circulate
{
private:
struct node *start,*ptr1,*ptr2;
public:
circulate()
{
start=NULL;
}
void creation();
void circulate_nodes();
void traversal();
};

void circulate::creation()
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

void circulate::circulate_nodes()
{
ptr1=start;
ptr2=NULL;
while(ptr1->next!=NULL)
{
ptr2=ptr1;
ptr1=ptr1->next;
}
ptr1->next=start;
start=ptr1;
ptr2->next=NULL;
}

void circulate::traversal()
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
circulate ob;
ob.creation();
ob.traversal();
ob.circulate_nodes();
ob.traversal();
}
