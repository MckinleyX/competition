//CSES: Movie Festival II
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> movie;
bool cmp(movie a, movie b)
{
	if(a.second == b.second)
		return a.first > b.second;
	return a.second > b.second;
}
int main()
{
	ll n,k;
	ll ans = 0;
	cin >> n >> k;
	multiset<ll,greater<ll>> ppl;
	priority_queue<movie,vector<movie>,decltype(&cmp)> movies(cmp);
	for(int ii = 0; ii < k; ii++)
	{
		ppl.insert(0);
	}
	for(int ii = 0; ii < n; ii++)
	{
		movie m;
		cin >> m.first >> m.second;
		movies.push(m);
	}
	while(!movies.empty())
	{
		if(ppl.lower_bound(movies.top().first) != ppl.end())
		{
			ppl.erase(ppl.lower_bound(movies.top().first));
			ppl.insert(movies.top().second);
			ans++;
		}
		movies.pop();
	}
	cout << ans << endl;
}
