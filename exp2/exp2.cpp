//CSES: Exponentiation II
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1000000007;
vector<ll> primes;
ll exp_mod(ll a, ll b, ll mod)
{
	assert(b>=0);
	if(b == 0)
		return 1;
	if(b & 1)
		return a * exp_mod(a,b-1,mod) % mod;
	return exp_mod(a*a%mod,b/2,mod) % mod;
}
int main()
{
	cin.tie(0) -> sync_with_stdio(0);
	int n;
	cin >> n;
	for(int ii = 0; ii < n; ii++)
	{
		ll a,b,c;
		cin >> a >> b >> c;
		cout << exp_mod(a,exp_mod(b,c,MOD-1),MOD) << '\n';
	}
}
