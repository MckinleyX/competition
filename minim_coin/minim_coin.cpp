//CSES: Minimizing Coins
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
	cin.tie(0) -> sync_with_stdio(0);
	int num, val;
	cin >> num >> val;
	vector<int> coins(num);
	for(int ii = 0; ii < num; ii++)
		cin >> coins[ii];
	vector<int> dp(val+1);
	dp[0] = 0;
	for(int ii = 1; ii <= val; ii++)
	{
		dp[ii] = 1000001;
		for(int jj = 0; jj < num; jj++)
		{
			if(ii - coins[jj] >= 0)
				dp[ii] = min(dp[ii],dp[ii-coins[jj]]+1);
		}
	}
	if(dp[val] == 1000001)
		dp[val] = -1;
	cout << dp[val];
}
