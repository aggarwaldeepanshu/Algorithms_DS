#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};

int main(void)
{
	int i,n;
	struct node *start=NULL;
	struct node *ptr1,*ptr2;
	ptr1=(struct node*)malloc(sizeof(struct node));
	printf("Enter the value for first node\n");
	scanf("%d",&n);
	ptr1->data=n;
	ptr1->next=NULL;
	start=ptr1;
	printf("Enter -1 to exit\n");
	scanf("%d",&n);
	while(n!=-1)
	{
		ptr2=ptr1;
		ptr1=(struct node*)malloc(sizeof(struct node));
		ptr1->data=n;
		ptr1->next=NULL;
		ptr2->next=ptr1;
		scanf("%d",&n);
	}

	printf("\nTraversal\n");
	ptr2=start;
	while(ptr2!=NULL)
	{
		printf("%d\t",ptr2->data);
		ptr2=ptr2->next;
	}
}
