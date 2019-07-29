#include<iostream>
using namespace std;

struct node
{
int data;
struct node *next;
};

class swap_nodes
{
public:
void creation(struct node **);
struct node *pairwise_swap_nodes(struct node *);
void traversal(struct node *);
};

void creation(struct node **start)
{
struct node *ptr1,*ptr2;
int n;
ptr1=new struct node;
cout<<"Enter the value for first node"<<endl;
cin>>n;
ptr1->data=n;
ptr1->next=NULL;
(*start)=ptr1;
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

struct node *swap_nodes::pairwise_swap_nodes(struct node *start)
{
struct node *head,*ptr;
if(start==NULL||start->next==NULL)
return start;

ptr=start->next->next;
head=start->next;
start->next->next=start;
start->next=pairwise_swap_nodes(ptr);
return head;
}

void swap_nodes::traversal(struct node *start)
{
struct node *ptr2;
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
struct node *start;
swap_nodes ob;
creation(&start);
start=ob.pairwise_swap_nodes(start);
ob.traversal(start);
}
