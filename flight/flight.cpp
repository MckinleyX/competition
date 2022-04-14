//CSES: Flight Routse Check
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<vector<int>> graph;
vector<vector<int>> ungraph;
vector<bool> visited;
vector<bool> unvisited;
void fill(vector<bool>& visited, vector<vector<int>>& graph,int node)
{
	if(visited[node])
		return;
	visited[node] = true;
	for(int n : graph[node])
	{
		if(n == 0)

		fill(n);
	}
}
int main()
{
	cin.tie(0) -> sync_with_stdio(0);
	int n,m;
	cin >> n >> m;
	graph.resize(n);
	visited.resize(n);
	for(int ii = 0; ii < m; ii++)
	{
		int a,b;
		cin >> a >> b;
		graph[a-1].push_back(b-1);
		ungraph[b-1].push_back(a-1);
	}
	fill(visited,graph,0);
	fill(unvisited,ungraph,0);
	bool ans = true;
	for(int ii = 0; ii < n; ii++)
		if(!visited[ii])
			cout << "NO\n" << 0 << ' ' << ii;

}
