#include <bits/stdc++.h>
using namespace std;
int main()
{
	ifstream fin("cardgame.in");
	ofstream fout("cardgame.out");
	int n;
	fin >> n;
	set<int> bess;
	set<int> high;//higher to win
	set<int> low; //lower to win
	for(int ii = 0; ii < 2*n; ii++)
	{
		bess.insert(ii+1);
	}
	for(int ii = 0; ii < n/2; ii++)
	{
		int x;
		fin >> x;
		high.insert(x);
		bess.erase(x);
	}
	for(int ii = 0; ii < n/2; ii++)
	{
		int x;
		fin >> x;
		low.insert(x);
		bess.erase(x);
	}
	int ans = 0;
	auto bessh = bess.rbegin();
	for(auto it = high.rbegin(); it != high.rend(); it++)
	{
		if(*it < *bessh)
		{
			ans++;
			bessh++;
		}
	}
	auto bessl = bess.begin();
	for(auto it = low.begin(); it != low.end(); it++)
	{
		if(*it > *bessl)
		{
			ans++;
			bessl++;
		}
	}
	fout << ans << endl;
	fout.close();
	return 0;
}
