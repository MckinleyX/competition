//CSES: Edit Distance
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll grid[5001][5001];
int main()
{
	cin.tie(0) -> sync_with_stdio(0);
	string a,b;
	cin >> a >> b;
	for(int ii = 0; ii <= a.size(); ii++)
		for(int jj = 0; jj <= b.size(); jj++)
			grid[ii][jj] = 5001;
	grid[0][0] = 0;
	for(int ii = 0; ii <= a.size(); ii++)
	{
		for(int jj = 0; jj <= b.size(); jj++)
		{
			if(ii > 0)
				grid[ii][jj] = min(grid[ii][jj],grid[ii-1][jj]+1);
			if(jj > 0)
				grid[ii][jj] = min(grid[ii][jj],grid[ii][jj-1]+1);
			if(ii > 0 && jj > 0)
			{
				if(a[ii-1] == b[jj-1])
					grid[ii][jj]=min(grid[ii][jj],grid[ii-1][jj-1]);
				else
					grid[ii][jj]=min(grid[ii][jj],grid[ii-1][jj-1]+1);
			}
		}
	}
	cout << grid[a.size()][b.size()] << endl;
}
