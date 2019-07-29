#include<iostream>
using namespace std;

struct node
{
int data;
struct node *next;
};

class delete_node
{
private:
int k;
struct node *start,*ptr1,*ptr2;
public:
delete_node()
{
start=NULL;
}
void creation();
void delete_last_occurence();
void traversal();
};

void delete_node::creation()
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
cout<<"Enter the value of key"<<endl;
cin>>k;
}

void delete_node::delete_last_occurence()
{
ptr1=start;
ptr2=NULL;
while(ptr1!=NULL)
{
if(ptr1->data==k)
ptr2=ptr1;
ptr1=ptr1->next;
}
if(ptr2==NULL)
cout<<"Key not present"<<endl;
else
{
ptr2->data=ptr2->next->data;
ptr1=ptr2->next;
ptr2->next=ptr1->next;
delete ptr1;
}
}

void delete_node::traversal()
{
cout<<"After removing last occurence"<<endl;
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
delete_node ob;
ob.creation();
ob.delete_last_occurence();
ob.traversal();
}
