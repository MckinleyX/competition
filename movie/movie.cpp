// CSES: Movie Festival
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using movie = pair<ll,ll>;
int main()
{
	cin.tie(0) -> sync_with_stdio(0);
	int n;
	int t;
	ll ans = 0;
	cin >> n;
	vector<movie> movies(n);
	for(int ii = 0; ii < n; ii++)
		cin >> movies[ii].first >> movies[ii].second;
	
	sort(movies.begin(), movies.end(), 
			[](movie a, movie b) {return a.second < b.second;});

	t = movies[0].second;
	ans++;
	for(int ii = 1; ii < n; ii++)
	{
		if(movies[ii].first >= t)
		{
			t = movies[ii].second;
			ans++;
		}
	}
	cout << ans;
}
