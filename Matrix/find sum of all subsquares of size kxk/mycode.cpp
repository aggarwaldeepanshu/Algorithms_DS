
#include<bits/stdc++.h>
using namespace std;

class Matrix
{
	private:
		int n,k;
		int **arr,**ans,**temp;

	public:
		Matrix(int,int);
		void get_input();
		void find_sum();
		void display();
};

Matrix::Matrix(int a,int b)
{
	n=a;
	k=b;
	arr=new int* [n];
	for(int i=0;i<n;i++)
	{
		arr[i]=new int [n];
	}
	ans=new int* [k];

	for(int i=0;i<k;i++)
		ans[i]=new int [k];

	temp=new int* [k];

	for(int i=0;i<k;i++)
		temp[i]=new int [n];
}

void Matrix::get_input()
{
	cout<<"Enter the values for matrix"<<endl;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin>>arr[i][j];
}

void Matrix::find_sum()
{
	int i,j,sum;
	for(j=0;j<n;j++)
	{
		sum=0;
		for(i=0;i<k;i++)
			sum+=arr[i][j];

		temp[0][j]=sum;

		for(i=1;i<n-k+1;i++)
		{
			sum+=arr[i+k-1][j]-arr[i-1][j];
			temp[i][j]=sum;
		}

	}
	for(i=0;i<k;i++)
	{
		sum=0;
		for(j=0;j<k;j++)
			sum+=temp[i][j];

		ans[i][0]=sum;

		for(j=1;j<n-k+1;j++)
		{
			sum+=temp[i][j+k-1]-temp[i][j-1];
			ans[i][j]=sum;
		}
	}

}

void Matrix::display()
{
	cout<<"required matrix is"<<endl;
	for(int i=0;i<k;i++)
	{
		for(int j=0;j<k;j++)
			cout<<ans[i][j]<<" ";

		cout<<endl;
	}
}

int main(void)
{
	cout<<"Enter the size and k value"<<endl;
	int a,b;
	cin>>a>>b;
	Matrix ob(a,b);
	ob.get_input();
	ob.find_sum();
	ob.display();
}
