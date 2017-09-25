#include<bits/stdc++.h>
using namespace std;

class Graph
{
	private:
		int V;
		vector< pair<int,int> > arr;
		int *parent;

	public:
		Graph(int);

		void add_edge(int,int);
		bool findCycle(void);
};

Graph::Graph(int v)
{
	this->V=v;
	parent=new int [V];
}

void Graph::add_edge(int u,int v)
{
	pair<int,int> p;
	p.first=u;
	p.second=v;

	arr.push_back(p);
}

int findParent(int v,int parent[])
{
	if(parent[v]==-1)
		return v;

	return findParent(parent[v],parent);
}

void combine_set(int x,int y,int parent[])
{
	int a=findParent(x,parent);
	int b=findParent(y,parent);

	parent[a]=b;

}

bool Graph::findCycle(void)
{
	int i;

	for(i=0;i<V;i++)
		parent[i]=-1;

	for(i=0;i<arr.size();i++)
	{
		int x=findParent(arr[i].first,parent);
		int y=findParent(arr[i].second,parent);

		if(x==y)
			return true;

		combine_set(x,y,parent);
	}
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
