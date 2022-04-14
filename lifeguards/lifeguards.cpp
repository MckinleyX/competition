#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using guard = pair<ll,ll>;
int main()
{
	freopen("lifeguards.in","r",stdin);
	freopen("lifeguards.out","w",stdout);
	int num;
	cin >> num;
	guard* lifeguard = new guard[num];
	for(int ii = 0; ii < num; ii++)
		cin >> lifeguard[ii].first >> lifeguard[ii].second;
	sort(lifeguard,lifeguard+num);
	
	ll best = lifeguard[0].second - lifeguard[0].first;
	for(int ii = 0; ii < num; ii++)
	{
		ll begin = lifeguard[ii].first;
		ll end = lifeguard[ii].second;
		if(ii > 0)
			begin = max(begin, lifeguard[ii-1].second);
		if(ii < num - 1 )
			end = min(end, lifeguard[ii+1].first);

		ll diff = max(end-begin, 0ll);
		if(best > diff)
			best = diff;
	}
	ll sum = 0;
	for(int ii = 0; ii < num; ii++)
	{
		sum += max(0ll, lifeguard[ii].second - lifeguard[ii].first);
		int ind = ii+1;
		while(ind < num && lifeguard[ind].first < lifeguard[ii].second)
			lifeguard[ind++].first = lifeguard[ii].second;
	}
	cout << sum-best << endl;
}
