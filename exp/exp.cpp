//CSES: Exponentiation
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
const ll MOD = 1000000007;
int main()
{
	cin.tie(0) -> sync_with_stdio(0);
	int n;
	cin >> n;
	for(int ii = 0; ii < n; ii++)
	{
		ll a,b;
		cin >> a >> b;
		vector<ll> v;
		v.push_back(a);
		while(1 << v.size() <= b)
		{
			ll last = *v.rbegin();
			ll prod = (last*last) % MOD;
			v.push_back(prod);
			if(prod < 0)
				cerr << "overflow detected" << '\n';
		}
		ll ans = 1;
		for(int ii = 0; ii < v.size(); ii++)
		{
			if((b & (1<<ii)) > 0)
				ans *= v[ii];
			ans %= MOD;
		}
		cout << ans << '\n';
	}
}
