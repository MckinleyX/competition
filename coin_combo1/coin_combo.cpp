//CSES: Minimizing Coins
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9+7;
int main()
{
	cin.tie(0) -> sync_with_stdio(0);
	int num, val;
	cin >> num >> val;
	vector<ll> coins(num);
	for(int ii = 0; ii < num; ii++)
		cin >> coins[ii];
	vector<ll> dp(val+1);
	dp[0] = 1;
	for(int ii = 1; ii <= val; ii++)
	{
		for(int jj = 0; jj < num; jj++)
		{
			if(ii - coins[jj] >= 0)
			{
				dp[ii] += dp[ii-coins[jj]];
				dp[ii] %= MOD;
			}
		}
	}
	cout << dp[val];
}
