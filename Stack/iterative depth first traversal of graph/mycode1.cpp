#include<iostream>
#include<list>
#include<stack>
using namespace std;

class dfs
{
	private:
		int V;
		list <int> *adj;
		bool *visited;
	public:
		dfs(int v)
		{
			V=v;
			adj=new list<int>[v];
			visited=new bool[v];
		}
		void add_edge(int a,int b);
		void DFS(int);
};

void dfs::add_edge(int a,int b)
{
	adj[a].push_back(b);
}

void dfs::DFS(int v)
{
	int i,val;
	stack<int> s;

	list<int>::iterator it;

	for(i=0;i<V;i++)
		visited[i]=false;

	s.push(v);
	visited[v]=true;
        cout<<v<<" ";

	while(!s.empty())
	{
		val=s.top();
		s.pop();
		if(visited[val]==false)
		{
			cout<<val<<" ";
			visited[val]=true;
		}

		for(it=adj[val].begin();it!=adj[val].end();it++)
		{
			if(!visited[*it])
				s.push(*it);
		}
	}
}

int main(void)
{
	dfs ob(5);
	ob.add_edge(1,0);
	ob.add_edge(0,2);
	ob.add_edge(2,1);
	ob.add_edge(0,3);
	ob.add_edge(1,4);
	cout<<"The required DFS Traversal"<<endl;
	ob.DFS(0);
}
