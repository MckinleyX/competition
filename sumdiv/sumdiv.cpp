//CSES: Sum of Divisors
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
ll pre_sum(ll n)
{
	return (n%MOD)*((n+1)% MOD)/2 % MOD;
}
int main()
{
	cin.tie(0) -> sync_with_stdio(0);
	ll n;
	cin >> n;
	ll sum = 0;
	//all factors from 1 to sqrt(n)
	for(ll ii = 1; ii*ii <= n; ii++)
	{
		sum += n - (n % ii);
		sum %= MOD;
	}
	//all factors from n to sqrt(n)
	ll last = 1;
	for(ll ii = 2; ii*ii <= n; ii++)
	{
		sum += (ii-1)*(pre_sum(n/(ii-1)) - pre_sum(n/(ii)));
		sum %= MOD;
		last = ii;
	}
	sum += (last)*(pre_sum(n/last) - pre_sum(last));
	sum %= MOD;
	cout << sum << '\n';
}
