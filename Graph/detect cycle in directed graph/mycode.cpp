#include<bits/stdc++.h>
using namespace std;

#define max 100

class Graph
{
	private:
		int V;
		list<int> *adj;
		bool *visited;
		bool *recstk;

	public:
		Graph(int);

		void add_edge(int,int);
		bool findCycle(void);
};

Graph::Graph(int v)
{
	this->V=v;
	adj=new list<int> [V];
	visited=new bool [V];
	recstk=new bool [V];
}

void Graph::add_edge(int u,int v)
{
	adj[u].push_back(v);
	return ;
}

bool findCycleUtil(int s,bool visited[],list<int> *adj,bool recstk[])
{
	if(!visited[s])
	{
		visited[s]=true;
		recstk[s]=true;

		list<int>::iterator it;

		for(it=adj[s].begin();it!=adj[s].end();it++)
		{
			if(!visited[*it] && findCycleUtil(*it,visited,adj,recstk) )
				return true;

			else if(recstk[*it])
				return true;
		}

	}
	recstk[s]=false;
	return false;

}

bool Graph::findCycle(void)
{
	int i;

	for(i=0;i<V;i++)
	{
		visited[i]=false;
		recstk[i]=false;
	}

	for(i=0;i<V;i++)
		if(findCycleUtil(i,visited,adj,recstk))
			return true;

	return false;
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

	if(ob.findCycle())
		cout<<"cycle is present"<<endl;

	else
		cout<<"cycle is not present"<<endl;
}
