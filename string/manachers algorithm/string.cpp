#include<bits/stdc++.h>
#define max1 500
using namespace std;

class String
{
	public:
		void ManachersAlgorithm(char []);
};

void String::ManachersAlgorithm(char str[])
{
	int i=1,n,r=2,diff=-1,c=1,max_length=0,max_center=0,j,expand=-1,start=-1,end=-1;
	n=strlen(str);
	n=2*n+1;
	int pos[n];
	pos[0]=0;
	pos[1]=1;

	for(i=2;i<n;i++)
	{
		j=2*c-i;
		diff=r-i;
		expand=0;
		if(diff>0)
		{
			if(pos[j]<diff)
				pos[i]=pos[j];

			else if(pos[j]==diff && i==n-1)
				pos[i]=pos[j];

			else if(pos[j]==diff && i<n-1)
			{
				expand=1;
				pos[i]=pos[j];
			}

			else if(pos[j]>diff)
			{
				expand=1;
				pos[i]=pos[j];
			}

		}
		else
		{
			pos[i]=0;
			expand=1;
		}

		if(expand==1)
		{
			while(((i+pos[i]<n) && (i-pos[i])>0) && (((i+pos[i]+1)%2==0) || (str[(i+pos[i]+1)/2]==str[(i-pos[i]-1)/2]) ))

				pos[i]++;
		}

		if(pos[i]>max_length)
		{
			max_length=pos[i];
			max_center=i;
		}

		if(i+pos[i]>r)
		{
			r=i+pos[i];
			c=i;
		}

	}

	start=(max_center-max_length)/2;
	end=start+max_length-1;
	for(i=start;i<=end;i++)
		cout<<str[i];

	cout<<endl;
	cout<<"max length is "<<max_length<<endl;

}

int main(void)
{
	String ob;

	char text[max1],pat[max1];
	cin.get(text,max1);

	ob.ManachersAlgorithm(text);

}
