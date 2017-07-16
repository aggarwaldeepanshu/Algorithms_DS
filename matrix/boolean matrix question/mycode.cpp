#include<iostream>
#define max 100
using namespace std;

class Matrix
{
	public:
		void Boolean(int [][max],int,int);
};

void Matrix::Boolean(int arr[][max],int r,int c)
{
	int i,j,k=0;
	int row[r],col[c];
	//bool rflag=false,cflag=false;
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			if(arr[i][j]==1)
			{
				row[i]=1;
				col[j]=1;
			}
		}
	}
	for(i=0;i<r;i++)
		for(j=0;j<c;j++)
			if(row[i]==1 || col[j]==1)
				arr[i][j]=1;
}

int main(void)
{
	Matrix ob;
	int i,j,row,col;
	int arr[max][max];

	cout<<"enter row"<<endl;
	cin>>row;

	cout<<"enter column"<<endl;
	cin>>col;

	cout<<"enter the values"<<endl;

	for(i=0;i<row;i++)
		for(j=0;j<col;j++)
			cin>>arr[i][j];

	ob.Boolean(arr,row,col);
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
}
