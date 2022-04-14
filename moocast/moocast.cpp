#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using cow = pair<int,int>;
ll dist(cow a, cow b)
{
	return (a.first-b.first)*(a.first-b.first) +
		(a.second-b.second)*(a.second-b.second);
}
bool ok(ll dist)
{
}

int main()
{
	cin.tie(0) -> sync_with_stdio(0);
	freopen("moocast.in","r",stdin);
	freopen("moocast.out","w",stdout);
	int n;
	cin >> n;
	vector<vector<ll>> graph(n);
	vector<cow> cows(n);
	for(int ii = 0; ii < n; ii++)
	{
		cin >> cows[ii].first >> cows[ii].second;
		for(int jj = 0; jj < ii; jj++)
		{
			graph[ii][jj] = 
		}
	}
	for(int ii 
	ll lo = 1;
	ll hi = 1e10;
	while(lo < hi)
	{
		ll mid = lo + (hi-lo+1)/2;
	}
}
