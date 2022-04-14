#include <bits/stdc++.h>
using namespace std;
int main()
{
	ifstream fin("cownomics.in");
	ofstream fout("cownomics.out");
	int n,m;
	fin >> n >> m;
	vector<string> spots;
	vector<string> plain;
	for(int ii = 0; ii < n; ii++)
	{
		string s;
		fin >> s;
		spots.push_back(s);
	}
	for(int ii = 0; ii < n; ii++)
	{
		string s;
		fin >> s;
		plain.push_back(s);
	}
	int ans = 0;
	for(int ii = 0; ii < m; ii++)
	{
		for(int jj = ii+1; jj < m; jj++)
		{
			for(int kk = jj+1; kk < m; kk++)
			{
				unordered_set<string> m;
				for(int ll = 0; ll < n; ll++)
				{
					m.insert({spots[ll][ii],spots[ll][jj],spots[ll][kk]} ); 
				}
				bool no_coll = false;
				for(int ll = 0; ll < n; ll++)
				{
					if(m.count({plain[ll][ii],plain[ll][jj],plain[ll][kk]}))
					{
						ll = n;
						no_coll = true;
					}
				}
				if(!no_coll)
					ans++;
			}
		}
	}
	fout << ans << endl;
	return 0;
}
