#include<bits/stdc++.h>
#define max 256
using namespace std;

struct node
{
	char data;
	struct node *left,*right;
};

class String
{
	private:
		struct node *start,*tail;
	public:
		String()
		{
			start=NULL;
			tail=NULL;
		}
		void insert(char);
		void delete_node(struct node *);
		void findCharacter(char []);
};

void String::insert(char ch)
{
	struct node *ptr=new struct node;
	ptr->data=ch;
	ptr->right=NULL;

	if(start==NULL)
	{
		start=ptr;
		ptr->left=NULL;
		tail=ptr;
		return ;
	}

	ptr->left=tail;
	tail->right=ptr;
	tail=ptr;

	return ;
}

void String::delete_node(struct node *ptr)
{
	if(ptr->left)
		ptr->left->right=ptr->right;

	if(ptr->right)
		ptr->right->left=ptr->left;

	if(ptr==tail)
		tail=ptr->left;

	if(ptr==start)
		start=ptr->right;

	delete ptr;

	return ;
}

void String::findCharacter(char str[])
{
	int i,j,n;
	char ch;
	int visited[max];
	struct node *pointer[max];

	for(i=0;i<max;i++)
	{
		pointer[i]=NULL;
		visited[i]=0;
	}

	n=strlen(str);

	for(i=0;i<n;i++)
	{
		ch=str[i];

		if(!visited[ch])
		{
			if(!pointer[ch])
			{
				insert(ch);
				pointer[ch]=tail;
			}

			else
			{
				delete_node(pointer[ch]);
				pointer[ch]=NULL;
				visited[ch]=1;
			}

		}
		if(start)
		{
			ch=start->data;
			cout<<ch<<endl;
		}

	}

}

int main(void)
{
	String ob;
	int n,m,i;
	char str[max];

	cout<<"enter the string"<<endl;
	cin.get(str,max);
	cout<<"non repeating characters are"<<endl;
	ob.findCharacter(str);
}
