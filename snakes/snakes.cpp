#include <bits/stdc++.h>
using namespace std;
const int MAX = 10;
map<int,int> dp[MAX][MAX];
int best[MAX][MAX];
int arr[MAX];
int main()
{
	cin.tie(0) -> sync_with_stdio(0);
	int num, sw;
	cin >> num >> sw;
	int max_snake = 0;
	for(int ii = 0; ii < num; ii++)
	{
		cin >> arr[ii];
		max_snake = max(max_snake, arr[ii]);
	}

	for(int ii = 1; ii <= num; ii++)
		for(int jj = 0; jj <= sw; jj++)
			best[ii][jj] = num*max_snake;

	for(int ii = 1; ii <= num; ii++)
	{
		for(int jj = 0; jj <= sw; jj++)
		{
			for(int kk = arr[ii-1]; kk <= max_snake; kk++)
			{
				if(dp[ii-1][jj].count(kk) == 0)
					dp[ii][jj][kk] = num*max_snake;
				else
					dp[ii][jj][kk] = dp[ii-1][jj][kk];
				if(jj > 0)
				{
					dp[ii][jj][kk] = min(dp[ii][jj][kk],
							best[ii-1][jj-1]);
				}
				dp[ii][jj][kk] += kk - arr[ii-1];
				best[ii][jj] = min(best[ii][jj],dp[ii][jj][kk]);
			}
		}
	}
	int ans = max_snake*num;
	for(int ii = 0; ii <= sw; ii++)
		ans = min(ans,best[num][ii]);
	cout << ans << '\n';
}
