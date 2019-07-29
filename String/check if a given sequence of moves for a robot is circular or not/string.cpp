#include<bits/stdc++.h>
#define max1 256
#define N 0
#define E 1
#define S 2
#define W 3
using namespace std;

class String
{
	public:
		int RobotMoves(char []);
};

int String::RobotMoves(char str[])
{
	int i,n,a=0,b=0;
	n=strlen(str);
	int dir=N;
	for(i=0;i<n;i++)
	{
		if(str[i]=='L')
			dir=(4+dir-1)%4;

		else if(str[i]=='R')
			dir=(dir+1)%4;

		else
		{
			if(dir==N)
				b++;

			else if(dir==S)
				b--;

			else if(dir==E)
				a++;

			else if(dir==W)
				a--;
		}
	}

	if(a==0 && b==0)
		return 1;
	else
		return 0;

}

int main(void)
{
	String ob;
	char text[max1];
	cout<<"enter string"<<endl;
	cin.get(text,max1);

	if(ob.RobotMoves(text))
		cout<<"true"<<endl;
	else
		cout<<"false"<<endl;
}
