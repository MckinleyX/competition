//CSES: Message Route
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
	cin.tie(0) -> sync_with_stdio(0);
	int n,m;
	cin >> n >> m;
	vector<vector<int>> graph(n);
	vector<int> prev(n);
	for(int ii = 0; ii < n; ii++)
		prev[ii] = -1;
	for(int ii = 0; ii < m; ii++)
	{
		int a,b;
		cin >> a >> b;
		a--;
		b--;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	queue<int> q;
	q.push(0);
	while(!q.empty())
	{
		if(q.front() == n-1)
			break;
		for(int ii : graph[q.front()])
		{
			if(prev[ii] == -1 && ii != 0)
			{
				prev[ii] = q.front();
				q.push(ii);
			}
		}
		q.pop();
	}
	if(q.front() == n-1)
	{
		stack<int> ans;
		int curr = n-1;
		while(curr != -1)
		{
			ans.push(curr);
			curr = prev[curr];
		}
		cout << ans.size() << '\n';
		while(!ans.empty())
		{
			cout << ans.top() + 1 << ' ';
			ans.pop();
		}
		cout << '\n';
	}
	else
		cout << "IMPOSSIBLE" << '\n';

}
