#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pos = pair<int,int>;
#define f first
#define s second

#define REALLY_BIG_NUMBER 10e10+1

const int MAX_LENGTH = 1001;
ll grid[MAX_LENGTH][MAX_LENGTH];

int dist(pos a, pos b)
{
	return (a.f-b.f)*(a.f-b.f) + (a.s-b.s)*(a.s-b.s);
}
pos operator +(pos p, char c)
{
	if(c == 'N')
		p.s++;
	else if(c == 'E')
		p.f++;
	else if(c == 'S')
		p.s--;
	else
		p.f--;
	return p;
}
int main()
{
	cin.tie(0) -> sync_with_stdio(0);
	freopen("radio.in","r",stdin);
	freopen("radio.out","w",stdout);
	int n,m;
	cin >> n >> m;
	vector<pos> j_path(n+1);
	vector<pos> b_path(m+1);
	cin >> j_path[0].f >> j_path[0].s;
	cin >> b_path[0].f >> b_path[0].s;
	string jmov,bmov;
	cin >> jmov >> bmov;
	for(int ii = 1; ii <= n; ii++)
		j_path[ii] = j_path[ii-1] + jmov[ii-1];
	for(int ii = 1; ii <= m; ii++)
		b_path[ii] = b_path[ii-1] + bmov[ii-1];
	for(int ii = 0; ii <= n; ii++)
		for(int jj = 0; jj <= m; jj++)
			grid[ii][jj] = REALLY_BIG_NUMBER;
	grid[0][0] = -dist(j_path[0],b_path[0]);
	for(int ii = 0; ii <= n; ii++)
	{
		for(int jj = 0; jj <= m; jj++)
		{
			if(ii > 0 && jj > 0)
				grid[ii][jj] = grid[ii-1][jj-1];
			if(ii > 0)
				grid[ii][jj] = min(grid[ii][jj],grid[ii-1][jj]);
			if(jj > 0)
				grid[ii][jj] = min(grid[ii][jj],grid[ii][jj-1]);
			grid[ii][jj] += dist(j_path[ii],b_path[jj]);
		}
	}
	cout << grid[n][m] << endl;
}
