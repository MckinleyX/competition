#include <bits/stdc++.h>
#define f first
#define s second
#define MAX_VAL 1e10
using namespace std;
using ll = unsigned long long;
using pos = pair<int,int>;

int distance(pos a, pos b)
{
	return (a.f-b.f)*(a.f-b.f) + (a.s-b.s)*(a.s-b.s);
}

const int MAX_COWS = 1001;
ll g_grid[MAX_COWS][MAX_COWS];//grid of paths, ending on h
ll h_grid[MAX_COWS][MAX_COWS];//grid of paths, ending on g
int main()
{
	cin.tie(0) -> sync_with_stdio(0);
	freopen("checklist.in","r",stdin);
	freopen("checklist.out","w",stdout);
	int h,g;
	cin >> h >> g;
	vector<pos> hs(h+1);
	vector<pos> gs(g+1);
	for(int ii = 1; ii <= h; ii++)
		cin >> hs[ii].f >> hs[ii].s;
	for(int ii = 1; ii <= g; ii++)
		cin >> gs[ii].f >> gs[ii].s;
	for(int ii = 0; ii <= h; ii++)
		for(int jj = 0; jj <= g; jj++)
		{
			g_grid[ii][jj] = MAX_VAL;
			h_grid[ii][jj] = MAX_VAL;
		}
	h_grid[1][0] = 0;
	//first index represents hs, second gs
	//g_grid[ii][jj] represents the cost to reach the iith and jjth
	//cows
	for(int ii = 1; ii < h; ii++)//skip first and last
	{
		for(int jj = 0; jj <= g; jj++)
		{
			if(jj > 0)
			{
				g_grid[ii][jj] = min(
					h_grid[ii][jj-1] + distance(gs[jj],hs[ii]),
					g_grid[ii][jj-1] + distance(gs[jj],gs[jj-1]));
			}
			if(ii > 1)
			{
				h_grid[ii][jj] = min(
					g_grid[ii-1][jj] + distance(hs[ii],gs[jj]),
					h_grid[ii-1][jj] + distance(hs[ii],hs[ii-1]));
			}
		}
	}
	
	cout << min(h_grid[h-1][g] 
				+ distance(*next(hs.rbegin()),*hs.rbegin()),
			g_grid[h-1][g] + distance(*gs.rbegin(),*hs.rbegin()));
}
