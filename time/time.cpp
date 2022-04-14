//USACO: time is mooney
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
#define f first
#define s second
int main()
{
	cin.tie(0) -> sync_with_stdio(0);
	freopen("time.in","r",stdin);
	freopen("time.out","w",stdout);
	int n,m,c;
	cin >> n >> m >> c;
	vector<vector<int>> graph(n);
	vi mooney(n);
	for(int ii = 0; ii < n; ii++)
		cin >> mooney[ii];
	for(int ii = 0; ii < m; ii++)
	{
		int a,b;
		cin >> a >> b;
		a--;
		b--;
		graph[a].push_back(b);
	}
	map<int,int> trip;//maximum profit 
	//from a single trip of length n
	map<int,int>* curr = new map<int,int>();
	(*curr)[0] = 0;
	for(int ii = 1; curr->size() > 0; ii++)
	{
		map<int,int>* next = new map<int,int>();
		for(auto p : *curr)
		{
			for(auto n : graph[p.f])
			{
				if(n == 0)
					trip[ii] = max(trip[ii],p.s);
				else if(p.s + mooney[n] - c*ii*ii > 0)
					(*next)[n] = max((*next)[n],p.s+mooney[n]);
			}
		}
		delete curr;
		curr = next;
	}
	delete curr;
	ll best = 0;
	vector<ll> profit(500);
	for(int ii = 0; c*(2*ii+1) <= 1000; ii++)
	{
		for(auto p : trip)
		{
			if(p.f + ii < profit.size())
				profit[ii+p.f] = max(profit[ii+p.f],
						profit[ii]+p.s);
		}
	}
	for(int ii = 0; ii < profit.size(); ii++)
	{
		profit[ii] -= c*ii*ii;
		if(best < profit[ii])
			best = profit[ii];
	}
	cout << best << '\n';

}
