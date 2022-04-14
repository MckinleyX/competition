#include <bits/stdc++.h>
using namespace std;
int main()
{
	ifstream fin("highcard.in");
	ofstream fout("highcard.out");
	int n;
	fin >> n;
	set<int> elsi;
	set<int> bess;
	for(int ii = 0; ii < n; ii++)
	{
		int c;
		fin >> c;
		elsi.insert(c);
	}
	for(int ii = 1; ii <= 2*n; ii++)
	{
		if(elsi.count(ii) == 0)
		{
			bess.insert(ii);
		}
	}
	int ans = 0;
	auto it_b = bess.rbegin();
	for(auto it = elsi.rbegin(); it != elsi.rend(); it++)
	{
		if(*it < *it_b)
		{
			ans++;
			it_b++;
		}
	}
	fout << ans << endl;
}
