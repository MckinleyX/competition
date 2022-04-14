//Codeforces: E. Mahmoud and Ehab and the function
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
	cin.tie(0) -> sync_with_stdio(0);
	int n, m, q;
	cin >> n >> m >> q;
	ll as = 0;
	for(int ii = 0; ii < n; ii++)
	{
		ll a;
		cin >> a;
		as -= a * (2*(ii&1) - 1);
	}
	vector<ll> b(m);
	vector<ll> bs(m - n + 1);
	for(int ii = 0; ii < m; ii++)
		cin >> b[ii];

	/*
	for(int ii = 0; ii <= m-n; ii++)
		for(int jj = 0; jj < n; jj++)
			bs[ii] += b[ii+jj]*(2*(jj&1)-1);
			*/
	for(int ii = 0; ii < n; ii++)
		bs[0] += b[ii]*(2*(ii&1)-1);

	for(int ii = 1; ii <= m-n; ii++)
		bs[ii] = -(bs[ii-1] + b[ii-1]) + b[ii+n-1]*(2*((n-1)&1)-1);


	sort(bs.begin(),bs.end());

	auto it = lower_bound(bs.begin(),bs.end(),-as);
	ll ans = abs(as + bs[0]);
	if(it != bs.end())
		ans = abs(*it + as);
	if(it != bs.begin())
		ans = min(ans, abs(as+*prev(it)));
	cout << ans << '\n';
	for(int ii = 0; ii < q; ii++)
	{
		ll l,r,x;
		cin >> l >> r >> x;
		as += x*((l-r+1) & 1)*(2*(l&1)-1);
		it = lower_bound(bs.begin(),bs.end(),-as);
		ll ans = abs(as + bs[0]);
		if(it != bs.end())
			ans = abs(as+*it);
		if(it != bs.begin())
			ans = min(ans, abs(as+*prev(it)));
		cout << ans << '\n';
	}
}
