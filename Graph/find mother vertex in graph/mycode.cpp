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
		void DFSUtil(int);
		int findVertex();
		void checkVertex(int);
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

void Graph::DFSUtil(int v)
{
	visited[v]=true;
	list<int>::iterator it;

	for(it=adj[v].begin();it!=adj[v].end();it++)
	{
		if(visited[*it]==false)
			DFSUtil(*it);
	}
}

int Graph::findVertex()
{
	int i,ans;

	for(i=0;i<V;i++)
		visited[i]=false;

	for(i=0;i<V;i++)
	{
		if(visited[i]==false)
		{
			DFSUtil(i);
			ans=i;
		}

	}

	for(i=0;i<V;i++)
		visited[i]=false;

	DFSUtil(ans);

	for(i=0;i<V;i++)
	{
		if(visited[i]==false)
			return -1;
	}

	return ans;
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
	int vtx=ob.findVertex();
	if(vtx==-1)
		cout<<"no mother vertex present"<<endl;

	else
		cout<<"the required vertex is "<<vtx<<endl;
}
