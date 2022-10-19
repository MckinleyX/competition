#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;
const ll MAXN = 2e6;
ll fac[MAXN+1],inv[MAXN+1];
//computes x^y mod MOD
ll exp(ll x, ll y)
{
	if(y == 1)
		return x;
	if(y & 1)
		return (x * exp(x,y-1)) % MOD;
	return exp((x*x) % MOD, y/2);
}
//precompute factorials
void factorial()
{
	fac[0] = 1;
	for(int ii = 1; ii <= MAXN; ii++)
	{
		fac[ii] = fac[ii-1] * ii % MOD;
	}
}
//precompute inverse factorials
void inverses()
{
	inv[0] = 1;
	for(int ii = 1; ii <= MAXN; ii++)
	{
		inv[ii] = exp(fac[ii], MOD-2);
		//cout << inv[ii] << '\n';
	}
}
ll choose(ll n, ll r)
{
	return ((fac[n] * inv[r] % MOD) * inv[n-r]) % MOD;
}
int main()
{
	cin.tie(0) -> sync_with_stdio(0);
	int n,m;
	factorial();
	inverses();
	cin >> n >> m;
	cout << choose(n+m-1,m) << '\n';
}
