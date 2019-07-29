#include<iostream>
using namespace std;

struct node
{
int data;
struct node *next;
};

class deletion
{
private:
struct node *start,*ptr1,*ptr2;
public:
deletion()
{
start=NULL;
}
void creation();
void delete_node();
void traversal();
};

void deletion::creation()
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

void deletion::delete_node()
{
ptr1=start;
while(ptr1!=NULL&&ptr1->next!=NULL)
{
ptr2=ptr1->next;
ptr1->next=ptr1->next->next;
delete ptr2;
ptr1=ptr1->next;
}
}

void deletion::traversal()
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
deletion ob;
ob.creation();
ob.traversal();
ob.delete_node();
ob.traversal();
}
