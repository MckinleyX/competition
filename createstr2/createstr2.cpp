#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;
const ll MOD = 1e9 + 7;
const ll MAXN = 1e6;
ll fac[MAXN+1],inv[MAXN+1];
//computes x^y mod p
ll exp(ll x, ll y, ll mod)
{
	if(y == 1)
		return x;
	if(y & 1)
		return (x * exp(x,y-1,mod)) % mod;
	return exp((x*x) % mod, y/2, mod);
}
//precompute factorials
void factorial(ll mod)
{
	fac[0] = 1;
	for(int ii = 1; ii <= MAXN; ii++)
	{
		fac[ii] = fac[ii-1] * ii % mod;
	}
}
//precompute inverse factorials
void inverses(ll mod)
{
	inv[0] = 1;
	for(int ii = 1; ii <= MAXN; ii++)
	{
		inv[ii] = exp(fac[ii], mod-2, mod);
		//cout << inv[ii] << '\n';
	}
}
int main()
{
	cin.tie(0) -> sync_with_stdio(0);
	string s;
	cin >> s;
	factorial(MOD);
	inverses(MOD);
	map<char,int> m;
	for(int ii = 0; ii < s.size(); ii++)
		m[s[ii]]++;
	ll ans = fac[s.size()];
	for(auto ii : m)
	{
		ans *= inv[ii.second];
		ans %= MOD;
	}
	cout << ans << endl;
}
