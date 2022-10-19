#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int SIZE = 201;
int prefix[SIZE][SIZE];
int actual[SIZE][SIZE];
int dp[SIZE][SIZE];
int dp_prefix[SIZE][SIZE];

int topDP[SIZE];
int bottomDP[SIZE];
int leftDP[SIZE];
int rightDP[SIZE];

int main()
{
	cin.tie(0) -> sync_with_stdio(0);
	freopen("paintbarn.in","r",stdin);
	//freopen("paintbarn.out","w",stdout);
	int n,k;	
	cin >> n >> k;
	ll ans = 0;
	for(int ii = 0; ii < n; ii++)
	{
		int x1,y1,x2,y2;
		cin >> x1 >> y1 >> x2 >> y2;
		prefix[x1][y1]++;
		prefix[x1][y2]--;
		prefix[x2][y1]--;
		prefix[x2][y2]++;
	}
	//convert prefix sums to
	//actual
	for(int ii = 0; ii <= 200; ii++)
	{
		for(int jj = 0; jj <= 200; jj++)
		{
			//TODO oops going wrong awy
			actual[ii][jj] = prefix[ii][jj];
			if(ii > 0)
				actual[ii][jj] -= actual[ii-1][jj];
			if(jj > 0)
				actual[ii][jj] -= actual[ii][jj-1];
			if(ii > 0 && jj > 0)
				actual[ii][jj] += actual[ii-1][jj-1];
		}
	}
	//convert actual to:
	//k-1 |-> 1
	//k |-> -1
	//else \> 0
	for(int ii = 0; ii <= 200; ii++)
	{
		for(int jj = 0; jj <= 200; jj++)
		{
			if(actual[ii][jj] == k)
			{
				dp[ii][jj] = -1;
				ans++;
			}
			else if(actual[ii][jj] == k-1)
				dp[ii][jj] = 1;
			else
				dp[ii][jj] = 0;
		}
	}
	
}

