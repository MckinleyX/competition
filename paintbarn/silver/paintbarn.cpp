#include <bits/stdc++.h>
using namespace std;
int main()
{
	//We're generating the prefix array whose sum
	//is that of the barn.
	ifstream fin("paintbarn.in");
	ofstream fout("paintbarn.out");
	int n;
	int k;
	int sums[1001][1001] = {0};
	int barn[1001][1001] = {0};
	long ans = 0;
	fin >> n >> k;
	for(int ii = 0; ii < n; ii++)
	{
		int x1,y1,x2,y2;
		fin >> x1 >> y1 >> x2 >> y2;
		sums[x1][y1]++;
		sums[x1][y2]--;
		sums[x2][y1]--;
		sums[x2][y2]++;
	}
	for(int ii = 0; ii <= 1000; ii++)
	{
		for(int jj = 0; jj <= 1000; jj++)
		{
			barn[ii][jj] += sums[ii][jj];
			if(ii > 0)
				barn[ii][jj] += barn[ii-1][jj];
			if(jj > 0)
				barn[ii][jj] += barn[ii][jj-1];
			if(ii > 0 && jj > 0)
				barn[ii][jj] -= barn[ii-1][jj-1];
			if(barn[ii][jj] == k)
				ans++;
		}
	}
	fout << ans << endl;
}
