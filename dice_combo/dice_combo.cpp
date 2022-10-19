#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;
const ll MOD = 1000000007;
int main()
{
	cin.tie(0) -> sync_with_stdio(0);
	int num;
	cin >> num;
	ll dp[7];
	dp[0] = 1;
	for(int ii = 1; ii <= 6; ii++)
		dp[ii] = 0;
	for(int ii = 1; ii <= num; ii++)
	{
		dp[ii % 7] = 0;
		for(int roll = 1; roll <= 6; roll++)
		{
			dp[ii % 7] += dp[(ii + roll) % 7];
			dp[ii % 7] %= MOD;
		}
	}
	cout << dp[num % 7] << endl;
}
