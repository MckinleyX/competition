#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> Point;
bool ycomp(Point p, Point q) { return p.second < q.second;}
int main()
{
	int n;
	cin >> n;
	Point* cows = new Point[n];
	for(int ii = 0; ii < n; ii++)
	{
		Point p;
		cin >> p.first >> p.second;
		cows[ii] = p;
	}
	//COORDINATE COMPRESSION
	sort(cows,cows+n,ycomp);
	for(int ii = 0; ii < n; ii++) { cows[ii].second = ii+1; }
	sort(cows,cows+n);
	for(int ii = 0; ii < n; ii++) { cows[ii].first = ii+1; }
	vector<vector<int>> sums;
	sums.resize(n+1);
	sums[0].resize(n+1);
	for(int ii = 0; ii < n; ii++)
	{
		sums[ii+1].resize(n+1);
		sums[cows[ii].first][cows[ii].second]++;
	}
	for(int ii = 1; ii <= n; ii++)
	{
		for(int jj = 1; jj <= n; jj++)
		{
			sums[ii][jj] += sums[ii-1][jj];
			sums[ii][jj] += sums[ii][jj-1];
			sums[ii][jj] -= sums[ii-1][jj-1];
		}
	}
	long long ans = 0;
	for(int ii = 0; ii < n; ii++)
	{
		for(int jj = ii; jj < n; jj++)
		{
			//Pick the max&min xs then look up and down from there
			int top = max(cows[jj].second,cows[ii].second);
			int bot = min(cows[jj].second,cows[ii].second);
			long above = sums[jj+1][n] - sums[ii][n]
				- sums[jj+1][top] + sums[ii][top];
			long below = sums[jj+1][bot-1] - sums[ii][bot-1];
			ans += (above+1)*(below+1);
		}
	}
	cout << ans+1 << endl;
	
	return 0;
}
