#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define f first
#define s second
struct dsu
{
	vector<int> set;
	vector<int> sizes;
	dsu(int size) 
	{ 
		set = vector<int>(size,-1); 
		sizes = vector<int>(size, 1);
	}
	int get(int x)
	{
		if(set.at(x) < 0)
			return x;
		set.at(x) = get(set.at(x));
		return set.at(x);
	}
	bool connected(int x, int y) {return get(x) == get(y);}
	int get_size(int x){ return sizes.at(get(x)); }
	void unite(int x, int y)
	{
		x = get(x), y = get(y);
		if(x == y)
			return;
		if(rand() % 2)
		{
			set.at(x) = y;
			sizes.at(y) += sizes.at(x);
		}
		else
		{
			set.at(y) = x;
			sizes.at(x) += sizes.at(y);
		}
	}
};
int main()
{
	cin.tie(0) -> sync_with_stdio(0);
	int n,m;
	cin >> n >> m;
	dsu cities(n);
	vector<pair<ll, pair<int,int>>> roads;
	for(int ii = 0; ii < m; ii++)
	{
		int a,b;
		ll cost;
		cin >> a >> b >> cost;
		a--;
		b--;
		if(a > b)
			swap(a,b);
		roads.push_back({cost,{a,b}});
	}
	ll total_cost = 0;
	sort(roads.begin(),roads.end());
	for(int ii = 0; ii < roads.size() && cities.get_size(0) < n; ii++)
	{
		if(!cities.connected(roads[ii].s.f,roads[ii].s.s))
		{
			total_cost += roads[ii].f;
			cities.unite(roads[ii].s.f,roads[ii].s.s);
		}
	}
	if(cities.get_size(0) == n)
		cout << total_cost;
	else
		cout << "IMPOSSIBLE";
	return 0;
}
