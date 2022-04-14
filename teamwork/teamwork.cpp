#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int max_v(vector<int> v, int s, int e)
{
	int maximum = v[s];
	for(int ii = s+1; ii <= e; ii++)
		maximum = max(v[ii],maximum);
	return maximum;
}
int main()
{
	cin.tie(0) -> sync_with_stdio(0);
	freopen("teamwork.in","r",stdin);
	freopen("teamwork.out","w",stdout);
	int n, max_size;
	cin >> n >> max_size;
	vector<int> skill(n);
	vector<int> dp(n);
	for(int ii = 0; ii < n; ii++)
	{
		cin >> skill[ii];
		for(int jj = 1; jj <= min(ii,max_size); jj++)
		{
			int curr = dp[ii-jj]
		}
	}
}
