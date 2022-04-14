//CSES: Tree Diameter
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<vector<int>> graph;
vector<int> answers;
int depth(int node)
{
	if(graph[node].size() == 0)
		return 0;
	int ans = 0;
	for(int child : graph[node])
		ans += depth(child) + 1;
	answers[node] = ans;
	return ans;
}
int main()
{
	cin.tie(0) -> sync_with_stdio(0);
	int n;
	cin >> n;
	graph.resize(n);
	answers.resize(n);
	for(int ii = 1; ii <= n-1; ii++)
	{
		int a;
		cin >> a;
		a--;
		graph[a].push_back(ii);
	}
	depth(0);

	for(int num : answers)
		cout << num << ' ';
	cout << '\n';

}
