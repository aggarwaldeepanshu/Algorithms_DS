#include<bits/stdc++.h>
using namespace std;

struct node
{
	string data;
	struct node *next;
};

class palindrome
{
	private:
		struct node *start,*ptr1,*ptr2;
	public:
		palindrome()
		{
			start=NULL;
		}
		void creation();
		void check_palindrome();
};

void palindrome::creation()
{
	char n;
	ptr1=new struct node;
	cout<<"Enter the value for first node"<<endl;
	cin>>n;
	ptr1->data=n;
	ptr1->next=NULL;
	start=ptr1;
	cout<<"Enter Q to exit"<<endl;
	cin>>n;
	while(n!='Q')
	{
		ptr2=ptr1;
		ptr1=new struct node;
		ptr1->data=n;
		ptr1->next=NULL;
		ptr2->next=ptr1;
		cin>>n;
	}
}

void palindrome::check_palindrome()
{
	int n=0,l,h;
	string str;
	ptr1=start;
	while(ptr1!=NULL)
	{
		str.append(ptr1->data);
		ptr1=ptr1->next;
	}
	n=str.length();
	l=0;
	h=n-1;
	while(l<h)
	{
		if(str[l]!=str[h])
		{
			cout<<str<<" is not palindrome"<<endl;
			break;
		}
		l++;
		h--;
	}
	if(l==h||l>h)
		cout<<str<<" is a palindrome"<<endl;
}

int main(void)
{
	palindrome ob;
	ob.creation();
	ob.check_palindrome();
}
