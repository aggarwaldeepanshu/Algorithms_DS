#include<iostream>
#define max 100
using namespace std;

class Matrix
{
	public:
		void findPos(int [][max],int,int);
};

void Matrix::findPos(int arr[][max],int size,int num)
{
	int i,j;
	bool flag=false;
	i=0;
	j=size-1;
	while(i<size && j>=0)
	{
		if(arr[i][j]==num)
		{
			cout<<i<<" "<<j<<endl;
			flag=true;
			break;
		}

		else if(arr[i][j]<num)
			i++;

		else
			j--;
	}
	if(flag==false)
		cout<<"not found"<<endl;
}

int main(void)
{
	Matrix ob;
	int i,j,size,num;
	int arr[max][max];

	cout<<"enter size"<<endl;
	cin>>size;

	cout<<"enter the values"<<endl;

	for(i=0;i<size;i++)
		for(j=0;j<size;j++)
			cin>>arr[i][j];

	cout<<"enter number to find"<<endl;
	cin>>num;

	ob.findPos(arr,size,num);
}
