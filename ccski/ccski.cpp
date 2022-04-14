#include <bits/stdc++.h>
using namespace std;
#define MAX_SIZE 500
using wayp = pair<int,int>;
int grid[MAX_SIZE][MAX_SIZE];
const int R_CHANGE[]{0, 1, 0, -1};
const int C_CHANGE[]{1, 0, -1, 0};
bool fill(int m,int n,int diff, vector<wayp> wayps)
{
	bool visit[MAX_SIZE][MAX_SIZE];
	for(int ii = 0; ii < m; ii++)
		for(int jj = 0; jj < n; jj++)
			visit[ii][jj] = false;
	queue<wayp> q;
	q.push(wayps[0]);
	while(q.size() > 0)
	{
		wayp next = q.front();
		q.pop();
		visit[next.first][next.second] = true;
		for(int ii = 0; ii < 4; ii++)
		{
			wayp check;
			check.first = next.first + R_CHANGE[ii];
			check.second = next.second + C_CHANGE[ii];
			if(check.first >= 0 && check.first < m
					&& check.second >= 0 && check.second < n)
			{
				int distance = abs(grid[check.first][check.second]
						- grid[next.first][next.second]);
				if(!visit[check.first][check.second]
						&& distance <= diff)
					q.push(check);
			}
		}
	}
	bool ans = true;
	for(wayp w : wayps)
		ans &= visit[w.first][w.second];
	return ans;
}
int main()
{
	freopen("ccski.in","r",stdin);
	freopen("ccski.out","w",stdout);
	int m,n;
	cin >> m >> n;
	int min = 1000000000;
	int max = 0;
	for(int ii = 0; ii < m; ii++)
	{
		for(int jj = 0; jj < n; jj++)
		{
			cin >> grid[ii][jj];
			if(max < grid[ii][jj])
				max = grid[ii][jj];
			if(min > grid[ii][jj])
				min = grid[ii][jj];
		}
	}
	vector<wayp> wayps;
	for(int ii = 0; ii < m; ii++)
	{
		for(int jj = 0; jj < n; jj++)
		{
			int w;
			cin >> w;
			if(w)
				wayps.push_back({ii,jj});
		}
	}
	int lo = 0;
	int hi = max - min;
	while(lo < hi)
	{
		int mid = lo + (hi-lo+1)/2;
		if(fill(m,n,mid,wayps))
			hi = mid-1;
		else
			lo = mid;
	}
	cout << lo+1 << endl;

}
