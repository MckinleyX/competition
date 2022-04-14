#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5+1;
int dp[MAX][21][3];
int arr[MAX];
int main()
{
	cin.tie(0) -> sync_with_stdio(0);
	freopen("hps.in","r",stdin);
	freopen("hps.out","w",stdout);
	int num, sw;
	cin >> num >> sw;
	for(int ii = 0; ii < num; ii++)
	{
		char c;
		cin >> c;
		if(c == 'H')
			arr[ii] = 0;
		else if(c == 'P')
			arr[ii] = 1;
		else
			arr[ii] = 2;
	}
	for(int ii = 1; ii <= MAX; ii++)
	{
		for(int jj = 0; jj <= sw; jj++)
		{
			for(int kk = 0; kk < 3; kk++)
			{
				dp[ii][jj][kk] = dp[ii-1][jj][kk];
				if(jj > 0)
				{
					dp[ii][jj][kk] = 
						max(dp[ii][jj][kk],dp[ii-1][jj-1][(kk+1) % 3]);
					dp[ii][jj][kk] = 
						max(dp[ii][jj][kk],dp[ii-1][jj-1][(kk+2) % 3]);
				}
				if(kk == arr[ii-1])
					dp[ii][jj][kk]++;
			}
		}
	}
	int ans = 0;
	for(int ii = 0; ii <= sw; ii++)
		for(int jj = 0; jj < 3; jj++)
			ans = max(ans,dp[num][ii][jj]);
	cout << ans << '\n';

}
