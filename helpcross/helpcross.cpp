#include <bits/stdc++.h>
using namespace std;
typedef pair<long long,long long> cow;
bool cmp(cow a, cow b)
{
	return a.second < b.second;
}
int main()
{
	ifstream fin("helpcross.in");
	ofstream fout("helpcross.out");
	size_t chi,num;
	fin >> chi >> num;
	long long* chickens = new long long[chi];
	for(unsigned long long ii = 0; ii < chi; ii++)
		fin >> chickens[ii];
	cow* cows = new cow[num];
	for(unsigned long long ii = 0; ii < num; ii++)
		fin >> cows[ii].first >> cows[ii].second;
	sort(chickens,chickens+chi);
	sort(cows,cows+num,cmp);
	size_t ind_co = 0;
	long long ans = 0;
	for(size_t ind_ch = 0; ind_co < num && ind_ch < chi; ind_ch++)
	{
		while(cows[ind_co].second < chickens[ind_ch])
				ind_co++;
		for(size_t ii = ind_co; ii < num; ii++)
		{
			if(cows[ii].first <= chickens[ind_ch])
			{
				ans++;
				cows[ii].first = cows[ii].second + 1;
				ii = num;
			}
		}
	}
	fout << ans << endl;
	return 0;
}
