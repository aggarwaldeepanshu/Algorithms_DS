#include<iostream>
#include<algorithm>
using namespace std;

class pairs
{
	private:
		int size1,size2;
		int *x,*y;

	public:

		pairs(int n=4,int m=4)
                {
			size1=n;
			size2=m;
			x=new int[size1];
			y=new int[size2];
		}

		void get()
		{
			cout<<"Enter the first array size"<<endl;
			cin>>size1;
			cout<<"Enter the second array size"<<endl;
			cin>>size2;
			x=new int[size1];
			y=new int[size2];
			cout<<"Enter the values of first array"<<endl;
			for(int i=0;i<size1;i++)
				cin>>x[i];

			cout<<"Enter the values of second array"<<endl;
			for(int i=0;i<size2;i++)
				cin>>y[i];
		}

		void pairs_count();
};

int totalpairs(int y[],int temp[],int v,int size)
{
int i,val;
if(v==0)
return 0;
else if(v==1)
return temp[0];
int *idx=upper_bound(y,y+size,v);
val=(y+size)-idx;
val+=(temp[0]+temp[1]);
if(v==2)
val-=(temp[3]+temp[4]);
if(v==3)
val+=temp[2];
return val;
}

void pairs::pairs_count()
{
int i,val,temp[5]={0};
for(i=0;i<size2;i++)
{
if(y[i]<5)
temp[y[i]]++;
}
sort(y,y+size2);
for(i=0;i<size1;i++)
{
val+=totalpairs(y,temp,x[i],size2);
}
cout<<"Total pairs: "<<val<<endl;
}

int main(void)
{
	pairs ob;
	ob.get();
	ob.pairs_count();
}
