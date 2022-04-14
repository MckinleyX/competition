#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<vector<int>> graph;
vector<bool> team;
vector<bool> visited;
bool fill(int pers, bool adj)
{
	bool poss = true;
	team[pers] = !adj;
	visited[pers] = true;
	for(int p : graph[pers])
	{
		if(!visited[p])
			poss &= fill(p,!adj);
		else
			poss &= team[p] != team[pers]; 
	}
	return poss;
}
int main()
{
	cin.tie(0) -> sync_with_stdio(0);
	int n,m;
	cin >> n >> m;
	graph.resize(n);
	team.resize(n);
	visited.resize(n);
	for(int ii = 0; ii < m; ii++)
	{
		int a,b;
		cin >> a >> b;
		graph[a-1].push_back(b-1);
		graph[b-1].push_back(a-1);
	}
	for(int ii = 0; ii < n; ii++)
	{
		if(!visited[ii] && !fill(ii,true))
		{
			cout << "IMPOSSIBLE";
			return 0;
		}
	}
	for(int ii = 0; ii < team.size(); ii++)
		cout << team[ii]+1 << " ";
	cout << '\n';
}
