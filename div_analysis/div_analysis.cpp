//CSES: Divisor Analysis
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;
ll bin_exp(ll p, ll e)
{
	assert(e >= 0);
	if(e == 0)
		return 1;
	if(e & 1)
		return p*bin_exp(p,e-1)%MOD;
	return bin_exp(p*p%MOD,e/2);
}
int main()
{
	cin.tie(0) -> sync_with_stdio(0);
	int n;
	cin >> n;
	vector<ll> divs(n);
	vector<ll> exps(n);
	for(int ii = 0; ii < n; ii++)
		cin >> divs[ii] >> exps[ii];
	ll num_div = 1;
	ll sum_div = 1;
	ll pro_div = 1;
	for(ll e : exps)
	{
		num_div *= (e+1);
		num_div %= MOD;
	}
	for(int ii = 0; ii < n; ii++)
	{
		sum_div += (bin_exp(
	}
	cout << num_div << sum_div << pro_div;
}
