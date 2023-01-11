//CSES: Road Construction
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct dsu
{
	vector<ll> set;
	vector<int> sizes;
	dsu(ll size) 
	{ 
		set = vector<ll>(size,-1); 
		sizes = vector<int>(size, 1);
	}
	int get(int x)
	{
		if(set[x] < 0)
			return x;
		set[x] = get(set[x]);
		return set[x];
	}
	bool connected(int x, int y) {return get(x) == get(y);}
	int get_size(int x){ return sizes[get(x)]; }
	void unite(int x, int y)
	{
		x = get(x), y = get(y);
		if(x == y)
			return;
		if(rand() % 2)
		{
			set[x] = y;
			sizes[y] += sizes[x];
		}
		else
		{
			set[y] = x;
			sizes[x] += sizes[y];
		}
	}
};
int main()
{
	cin.tie(0) -> sync_with_stdio(0);
	int n,m;
	cin >> n >> m;
	dsu roads(n);
	int max_size = 1;
	int num_regions = n;
	for(int ii = 0; ii < m; ii++)
	{
		int a,b;
		cin >> a >> b;
		a--;b--;
		if(!roads.connected(a,b))
			num_regions--;
		roads.unite(a,b);
		if(roads.get_size(a) > max_size)
			max_size = roads.get_size(a);
		cout << num_regions << ' ' << max_size << '\n';
	}
}
