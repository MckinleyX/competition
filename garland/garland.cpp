#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve(string gar, int len)
{
	int num;
	char fav;
	cin >> num >> fav;
	int l=0,r=0;
	int best = 0;
	int bad = 0;
	if(gar[0] != fav)
		bad++;
	while(r < len)
	{
		if(bad > num)
		{
			if(gar[l] != fav)
				bad--;
			l++;
		}
		else
		{
			if(r - l + 1 > best)
				best = r - l + 1;
			r++;
			if(gar[r] != fav)
				bad++;
		}
	}
	cout << best << '\n';
	return;
}
int main()
{
	int len;
	string gar;
	cin >> len;
	cin >> gar;
	int num_cases;
	cin >> num_cases;
	for(int ii = 0; ii < num_cases; ii++)
		solve(gar,len);
}
