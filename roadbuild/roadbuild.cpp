#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<bool> visited;
vector<vector<int>> graph;
void fill(int node)
{
	if(visited[node])
		return;
	visited[node] = true;
	for(int ii : graph[node])
		fill(ii);
}
int main()
{
	cin.tie(0) -> sync_with_stdio(0);
	int n,m;
	cin >> n >> m;
	visited.resize(n);
	graph.resize(n);
	for(int ii = 0; ii < m; ii++)
	{
		int a,b;
		cin >> a >> b;
		graph[a-1].push_back(b-1);
		graph[b-1].push_back(a-1);
	}
	vector<int> roads;

	for(int ii = 0; ii < n; ii++)
	{
		if(!visited[ii])
		{
			fill(ii);
			roads.push_back(ii);
		}
	}
	cout << roads.size() -1 << '\n';
	for(int ii = 0; ii < roads.size() - 1; ii++)
		cout << roads[ii]+1 << ' ' << roads[ii+1]+1 << '\n';
}
