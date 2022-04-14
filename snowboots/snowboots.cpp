#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct boot
{
	ll first;
	ll second;
	ll ind;
};
bool cmp(boot a, boot b){return a.first < b.first;}
int solve(ll* tiles, ll n_tiles, boot b)
{
	int prev_step = 0;
	for(int ii = 1; ii < n_tiles; ii++)
	{
		if(ii - prev_step > b.second)
			return 0;
		else if(tiles[ii] <= b.first)
			prev_step = ii;
	}
	return 1;
}
int main()
{
	freopen("snowboots.in","r",stdin);
	freopen("snowboots.out","w",stdout);
	ll n_tiles,n_boots;
	cin >> n_tiles >> n_boots;
	ll* tiles = new ll[n_tiles];
	boot* boots = new boot[n_boots];
	for(int ii = 0; ii < n_tiles; ii++)
		cin >> tiles[ii];
	for(int ii = 0; ii < n_boots; ii++)
	{
		cin >> boots[ii].first >> boots[ii].second;
		boots[ii].ind = ii;
	}
	int* ans = new int[n_boots];
	for(int ii = 0; ii < n_boots; ii++)
		ans[ii] = -1;
	sort(boots,boots+n_boots,cmp);

	for(int ii = 0; ii < n_boots; ii++)
	{
		int ans_ind = boots[ii].ind;
		if(ans[ans_ind] == -1)
		{
			ans[ans_ind] = solve(tiles,n_tiles,boots[ii]);
			if(ans[ans_ind] == 1)
			{
				for(int jj = ii+1; jj < n_boots; jj++)
				{
					if(boots[jj].second >= boots[ii].second)
						ans[boots[jj].ind] = 1;
				}
			}
		}
	}
	for(int ii = 0; ii < n_boots; ii++)
		cout << ans[ii] << '\n';
}
