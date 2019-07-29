#include<iostream>
#include<queue>
#define max 100
using namespace std;

class Queue
{
	private:
		queue<pair<int,int> > q;

	public:
		int FindTime(int [][max],int,int);
};

int delimiter(pair<int,int> p)
{
	if(p.first==-1 && p.second==-1)
		return 1;
	else
		return 0;
}

int check_valid(int x,int y,int r,int c)
{
	if((x>=0 && y>=0) && (x<r && y<c))
		return 1;
	else
		return 0;
}

int Verify(int arr[][max],int r,int c)
{
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			if(arr[i][j]==1)
				return 1;
		}
	}
	return 0;
}

int Queue::FindTime(int arr[][max],int r,int c)
{
	int i,j,time=0;
	bool flag;
	pair<int,int> p;
	for(i=0;i<r;i++)
		for(j=0;j<c;j++)
		{
			if(arr[i][j]==2)
			{
				p.first=i;
				p.second=j;
				q.push(p);
			}
		}
	p.first=-1;
	p.second=-1;
	q.push(p);

	while(!q.empty())
	{
		flag=false;
		while(!delimiter(q.front()))
		{
			p=q.front();

			if(check_valid(p.first+1,p.second,r,c) && arr[p.first+1][p.second]==1)
			{
				if(flag==false)
				{
					time++;
					flag=true;
				}
				p.first++;
				arr[p.first][p.second]=2;
				q.push(p);
				p.first--;
			}

			if(check_valid(p.first-1,p.second,r,c) && arr[p.first-1][p.second]==1)
			{
				if(flag==false)
				{
					time++;
					flag=true;
				}
				p.first--;
				arr[p.first][p.second]=2;
				q.push(p);
				p.first++;
			}

			if(check_valid(p.first,p.second+1,r,c) && arr[p.first][p.second+1]==1)
			{
				if(flag==false)
				{
					time++;
					flag=true;
				}
				p.second++;
				arr[p.first][p.second]=2;
				q.push(p);
				p.second--;
			}

			if(check_valid(p.first,p.second-1,r,c) && arr[p.first][p.second-1]==1)
			{
				if(flag==false)
				{
					time++;
					flag=true;
				}
				p.second--;
				arr[p.first][p.second]=2;
				q.push(p);

			}
			q.pop();
		}

		q.pop();

		if(!q.empty())
		{
			p.first=-1;
			p.second=-1;
			q.push(p);
		}

	}
	if(Verify(arr,r,c))
		return -1;
	else
		return time;
}

int main(void)
{
	Queue ob;
	int i,j,r,c,val;
	cout<<"enter rows and columns"<<endl;
	cin>>r>>c;
	int arr[max][max];
	cout<<"enter the values"<<endl;
	for(i=0;i<r;i++)
		for(j=0;j<c;j++)
			cin>>arr[i][j];

	val=ob.FindTime(arr,r,c);
	if(val==-1)
		cout<<"impossible to rot every orange"<<endl;
	else
		cout<<"time required is "<<val<<endl;
}
