#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAX_COWS = 10001;
const int MAX_TEAM = 1001;
int maxes[MAX_COWS][MAX_TEAM];//maxes[A][B] denotes the largest value
					   //from A-B (exclusive) to A (inclusive)
int max_v(int l, int e)//length and end, including end
{
	if(maxes[e][l] == -1)
		return maxes[e][l] = max(maxes[e][1],max_v(l-1,e-1));
	return maxes[e][l];
}
int main()
{
	cin.tie(0) -> sync_with_stdio(0);
	freopen("teamwork.in","r",stdin);
	freopen("teamwork.out","w",stdout);
	int n, max_size;
	cin >> n >> max_size;
	//vector<int> skill(n+1);
	vector<int> dp(n+1);
	for(int ii = 0; ii < MAX_COWS; ii++)
		for(int jj = 0; jj < MAX_TEAM; jj++)
			maxes[ii][jj] = -1;
	for(int ii = 1; ii <= n; ii++)
		cin >> maxes[ii][1];
	for(int ii = 1; ii <= n; ii++)
	{
		for(int jj = 1; ii-jj>= 0 && jj <= max_size; jj++)
		{
			int best = max_v(jj, ii);
			dp[ii] = max(dp[ii],best*jj + dp[ii-jj]);
		}
	}
	cout << dp[n] << '\n';
}
