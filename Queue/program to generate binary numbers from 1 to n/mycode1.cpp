#include<iostream>
#include<queue>
using namespace std;

class Queue
{
	private:
		queue <string> q;

	public:

		void PrintBinary(int);
};

void Queue::PrintBinary(int n)
{
	int i;
	string s1,s2;
	q.push("1");
	while(n>0)
	{
		s1=q.front();
		q.pop();
		cout<<s1<<" ";
		s2=s1;
		q.push(s1.append("0"));
		q.push(s2.append("1"));
		n--;
	}
}

int main(void)
{
	Queue ob;
	int n;
	cout<<"enter n"<<endl;
	cin>>n;
	ob.PrintBinary(n);
}
