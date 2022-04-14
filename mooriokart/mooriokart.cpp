#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 10e9+7;
using road = pair<ll,ll>;//destination, cost
using edge = pair<ll,ll>;//from, to
int main()
{
	cin.tie(0) -> sync_with_stdio(0);
	freopen("mooriokart.in","r",stdin);
	freopen("mooriokart.out","w",stdout);
	int n,m,x,y;
	cin >> n >> m >> x >> y;
	vector<vector<road>> graph(n);
	vector<bool> visited(n);
	for(int ii = 0; ii < m; ii++)
	{
		int a,b,c;
		cin >> a >> b >> c;
		a--;
		b--;
		graph[a].push_back(make_pair(b,c));
		graph[b].push_back(make_pair(a,c));
	}
	ll num_tracks = 1;
	for(int ii = 0; ii < n; ii++)
	{
		if(visited[ii])
			continue;
		vector<int> farm;//list of distances
		queue<edge> q;
		for(
		while(!q.empty())
	}
}
