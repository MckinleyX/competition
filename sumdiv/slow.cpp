//CSES: Sum of Divisors
//Slow, accurate version
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
int main()
{
	cin.tie(0) -> sync_with_stdio(0);
	ll n;
	cin >> n;
	ll sum = 0;
	for(ll ii = 1; ii <= n; ii++)
	{
		sum += n/ii*ii;
		sum %= MOD;
	}
	cout << sum << '\n';
}
