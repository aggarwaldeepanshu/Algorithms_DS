#include<bits/stdc++.h>
using namespace std;

#define max 100

class Graph
{
	private:
		int V;
		list<int> *adj;
		int **tc;

	public:
		Graph(int);

		void add_edge(int,int);
		void findClosure();
		void DFSUtil(int,int);
		void printClosure();
};

Graph::Graph(int v)
{
	this->V=v;
	adj=new list<int> [V];

	tc=new int *[V];

	for(int i=0;i<V;i++)
		tc[i]=new int [V];

	for(int i=0;i<V;i++)
		for(int j=0;j<V;j++)
			tc[i][j]=0;
}

void Graph::add_edge(int u,int v)
{
	adj[u].push_back(v);
	return ;
}

void Graph::DFSUtil(int i,int v)
{
	tc[i][v]=1;
	list<int>::iterator it;

	for(it=adj[v].begin();it!=adj[v].end();it++)
	{
		if(tc[i][*it]==0)
			DFSUtil(i,*it);

	}

}

void Graph::findClosure()
{
	int i;
	for(i=0;i<V;i++)
	{
		DFSUtil(i,i);
	}

}

void Graph::printClosure()
{
	for(int i=0;i<V;i++)
	{
		for(int j=0;j<V;j++)
		{
			cout<<tc[i][j]<<" ";
		}
		cout<<endl;
	}

}

int main(void)
{
	int u,v,n;
	cout<<"enter the number of vertices"<<endl;
	cin>>n;
	Graph ob(n);
	cout<<"enter -1 -1 to exit"<<endl;
	cout<<"enter the values to create edge"<<endl;

	cin>>u>>v;
	while(u!=-1 && v!=-1)
	{
		ob.add_edge(u,v);
		cin>>u>>v;
	}
	ob.findClosure();
	ob.printClosure();
}
