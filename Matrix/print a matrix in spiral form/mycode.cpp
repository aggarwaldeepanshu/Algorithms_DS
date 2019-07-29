#include<iostream>
#define max 100
using namespace std;

class Matrix
{
	public:
		void PrintinSpiral(int [][max],int,int);
};

void Matrix::PrintinSpiral(int arr[][max],int row,int col)
{
	int i,j,a=0,b=0,k;

	while(a<row && b<col)
	{
		for(i=b;i<col;i++)
			cout<<arr[a][i]<<" ";

		a++;

		for(i=a;i<row;i++)
			cout<<arr[i][col-1]<<" ";

		col--;

		if(a<row)
		{
			for(i=col-1;i>=1;i--)
				cout<<arr[row-1][i]<<" ";

			row--;
		}

		if(b<col)
		{
			for(i=row-1;i>=a;i--)
				cout<<arr[i][b]<<" ";

			b++;
		}

	}
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

	ob.PrintinSpiral(arr,row,col);
}
