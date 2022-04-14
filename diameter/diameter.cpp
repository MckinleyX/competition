//CSES: Tree Diameter
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<vector<int>> graph;
int depth(int node, int parent)
{
	if(graph[node].size() == 1)
		return 1;
	int ans = 0;
	for(int ii = 0; ii < graph[node].size(); ii++)
	{
		int child = graph[node][ii];
		if(child == parent)
			continue;
		ans = max(ans, depth(child,node)+1);
	}
	return ans;
}
int main()
{
	cin.tie(0) -> sync_with_stdio(0);
	int n;
	cin >> n;
	graph.resize(n);
	for(int ii = 0; ii < n-1; ii++)
	{
		int a,b;
		cin >> a >> b;
		graph[a-1].push_back(b-1);
		graph[b-1].push_back(a-1);
	}
	int ans = 0;
	for(int ii = 0; ii < n; ii++)
	{
		if(graph[ii].size() == 1)
			ans = max(ans, depth(ii,-1));
	}
	cout << ans << '\n';

}
