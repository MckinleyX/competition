#include <bits/stdc++.h>
using namespace std;
int main()
{
	ifstream fin("stacking.in");
	ofstream fout("stacking.out");
	int n;
	int k;
	fin >> n >> k;
	int* pre = new int[n];
	for(int ii = 0; ii < k; ii++)
	{
		int st,en;
		fin >> st >> en;
		pre[st]++;
		pre[en+1]--;
	}
	int* bales = new int[n];
	for(int ii = 0; ii < n; ii++)
	{
		if(ii > 0)
			bales[ii] += bales[ii-1];
		bales[ii] += pre[ii];
	}
	sort(bales, bales+n);
	fout << bales[n/2];
	return 0;
}
