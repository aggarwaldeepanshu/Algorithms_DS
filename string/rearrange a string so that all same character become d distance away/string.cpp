#include<bits/stdc++.h>
#define max 256
using namespace std;

struct element
{
	int count;
	char data;
};

class String
{
	public:
		void Rearrange(char [],int);
};

void swap(struct element *a,struct element *b)
{
	struct element temp;
	temp=*a;
	*a=*b;
	*b=temp;

	return ;
}

void Heapify(struct element arr[],int i,int size)
{
	int largest=i,l,r;
	l=2*i+1;
	r=2*i+2;
	if(l<size && arr[l].count>arr[largest].count)
		largest=l;

	if(r<size && arr[r].count>arr[largest].count)
		largest=r;

	if(largest!=i)
	{
		swap(&arr[largest],&arr[i]);
		Heapify(arr,largest,size);
	}

}

void BuildHeap(struct element arr[],int size)
{
	int i;
	for(i=(size-1)/2;i>=0;i--)
		Heapify(arr,i,size);
}

void display(char str[])
{
	int i;
	for(i=0;i<strlen(str);i++)
		cout<<str[i];

	cout<<endl;

	return ;
}

void String::Rearrange(char str[],int d)
{
	int i,j=0,k,n,val,size=0,len=max-1;
	n=strlen(str);
	bool flag=true;
	struct element var;
	struct element arr[max];

	for(i=0;i<max;i++)
	{
		arr[i].count=0;
		arr[i].data=0;
	}

	for(i=0;i<n;i++)
	{
		if(arr[str[i]].data==0)
		{
			size++;
			arr[str[i]].data=str[i];
		}

		(arr[str[i]].count)++;
	}

	for(i=0;i<n;i++)
		str[i]='\0';

	BuildHeap(arr,max-1);

	for(i=0;i<size;i++)
	{
		if(flag==false)
			break;
		var=arr[0];
		if(len>1)
		{
			arr[0]=arr[len];
			len--;
			Heapify(arr,0,len);
		}

		j=i;
		while(str[j]!='\0')
			j++;

		for(k=j;var.count>0;k+=d)
		{
			if(k>n)
			{
				flag=false;
				break;
			}

			str[k]=var.data;
			(var.count)--;
		}

	}
	if(flag==false)
	{
		cout<<"no arrangement possible"<<endl;
		return ;
	}
	for(i=0;i<strlen(str);i++)
		cout<<str[i];

	return ;
}

int main(void)
{
	String ob;
	int n,m,i,d;
	char str[max];

	cout<<"enter the string"<<endl;
	cin.get(str,max);

	cout<<"enter d"<<endl;
	cin>>d;

	ob.Rearrange(str,d);
}
