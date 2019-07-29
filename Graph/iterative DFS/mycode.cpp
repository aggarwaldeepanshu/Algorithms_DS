#include<bits/stdc++.h>
using namespace std;

#define max 100

class Graph
{
	private:
		int V;
		list<int> *adj;
		bool *visited;

	public:
		Graph(int);

		void add_edge(int,int);
		void DFS(void);
};

Graph::Graph(int v)
{
	this->V=v;
	adj=new list<int> [V];
	visited=new bool [V];
}

void Graph::add_edge(int u,int v)
{
	adj[u].push_back(v);
	return ;
}

void DFSUtil(int s,bool visited[],list<int> *adj)
{
	int v;

	stack<int> stk;
	stk.push(s);

	list<int>::iterator it;

	while(!stk.empty())
	{
		v=stk.top();
		stk.pop();
		visited[v]=true;
		cout<<v<<" ";

		for(it=adj[v].begin();it!=adj[v].end();it++)
		{
			if(visited[*it]==false)
				stk.push(*it);
		}

	}

}

void Graph::DFS(void)
{
	int i;

	for(i=0;i<V;i++)
		visited[i]=false;

	for(i=0;i<V;i++)
		if(!visited[i])
			DFSUtil(i,visited,adj);

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

	ob.DFS();
}
