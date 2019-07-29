#include<iostream>
#include<stack>
#include<climits>
using namespace std;

struct node
{
	int data;
	struct node *lchild,*rchild;
};

class tree
{
	public:

		int Preorder(int [],int,int);
};

int tree::Preorder(int arr[],int low,int high)
{
	int i=low,key,val;
	val=INT_MIN;
	stack<int> s;

	for(i=low;i<=high;i++)
	{
		if(arr[i]<val)
			return 0;

		while(!s.empty() && arr[i]>s.top())
		{
			val=s.top();
			s.pop();
		}
		s.push(arr[i]);
	}
	return 1;
}

/*struct node *new_node(int val)
  {
  struct node *ptr=new node;
  ptr->data=val;
  ptr->lchild=NULL;
  ptr->rchild=NULL;
  return ptr;
  }

  struct node *insert(struct node *root,int val)
  {
  if(root==NULL)
  return new_node(val);
  else if(val<root->data)
  root->lchild=insert(root->lchild,val);
  else
  root->rchild=insert(root->rchild,val);

  return root;
  }*/

int main(void)
{
	int i,val,size;
	struct node *root;
	root=NULL;
	tree ob;
	cout<<"enter size of array"<<endl;
	cin>>size;
	int arr[size];
	cout<<"enter the values"<<endl;
	for(int i=0;i<size;i++)
		cin>>arr[i];

	if(ob.Preorder(arr,0,size-1))
		cout<<"true"<<endl;
	else
		cout<<"false"<<endl;
}
