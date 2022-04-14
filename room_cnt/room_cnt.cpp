#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAX_N = 1000;
const int MAX_M = 1000;
bool rooms[MAX_N][MAX_M];
void flood_fill(int r, int c, int n, int m)
{
	if(r < 0 || r >= n || c < 0 || c >= m || !rooms[r][c])
		return;
	rooms[r][c] = false;
	flood_fill(r+1,c,n,m);
	flood_fill(r-1,c,n,m);
	flood_fill(r,c+1,n,m);
	flood_fill(r,c-1,n,m);
}
int main()
{
	int n,m;
	cin >> n >> m;
	int ans = 0;
	for(int ii = 0; ii < n; ii++)
	{
		for(int jj = 0; jj < m; jj++)
		{
			char c;
			cin >> c;
			rooms[ii][jj] = (c == '.');
		}
	}
	for(int ii = 0; ii < n; ii++)
	{
		for(int jj = 0; jj < m; jj++)
		{
			if(rooms[ii][jj])
			{
				ans++;
				flood_fill(ii,jj,n,m);
			}
		}
	}
	cout << ans << endl;
}
