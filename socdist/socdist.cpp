#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using interval = pair<ll,ll>;
bool check(interval* ints, int n_int, int n_cow, ll max_dist)
{
	ll prev_cow = 0 - max_dist;
	for(int ii = 0; ii < n_int; ii++)
	{
		ll first = max(ints[ii].first,prev_cow + max_dist);
		if(first <= ints[ii].second)
		{
			int num_placed = (ints[ii].second - first)/max_dist + 1;
			n_cow -= num_placed;
			prev_cow = first + (num_placed - 1)*max_dist;
		}
	}
	return n_cow <= 0;
}
int main()
{
	freopen("socdist.in","r",stdin);
	freopen("socdist.out","w",stdout);
	int n_cow, n_int;
	cin >> n_cow >> n_int;
	interval* ints = new interval[n_int];
	for(int ii = 0; ii < n_int; ii++)
		cin >> ints[ii].first >> ints[ii].second;
	sort(ints,ints+n_int);
	ll lo = 1;
	ll hi = (ints[n_int-1].second-ints[0].first+1)/(n_cow-1);
	while(lo < hi)
	{
		ll mid = lo + (hi - lo + 1)/2;
		if(check(ints, n_int, n_cow, mid))
			lo = mid;
		else
			hi = mid-1;
	}
	cout << hi << endl;
}
