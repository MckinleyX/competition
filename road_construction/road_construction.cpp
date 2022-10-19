#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct dsu
{
	vector<ll> set;
	dsu(ll size) { set = vector<ll>(size,-1); }
	int get(int x)
	{
		if(set[x] < 0)
			return x;
		set[x] = get(set[x]);
		return set[x];
	}
	int size(int x){ return -set[get(x)];}
	bool connected(int x, int y) {return get(x) == get(y);}
	bool unite(int x, int y)
	{
		x = get(x), y = get(y);
		if(x == y)
			return false;
		if(set[x] < set[y]) 
			swap(x,y);
		set[x] += set[y];
		set[y] = x;
		return true;
	}
};
int main()
{
	cin.tie(0) -> sync_with_stdio(0);
	int n,m;
	cin >> n >> m;
	for(int ii = 0; ii < m; ii++)
	{
	}
}
