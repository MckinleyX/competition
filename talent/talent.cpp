#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using cow = pair<int,int>;

cow operator +(cow a, cow b)
{ return make_pair(a.first+b.first,a.second+b.second); }

float score(cow c)
{
	if(c.first == 0)
		return 0;
	return (float)c.second / c.first;
}

int main()
{
	cin.tie(0) -> sync_with_stdio(0);
	freopen("talent.in","r",stdin);
	freopen("talent.out","w",stdout);
	int n,weight;
	cin >> n >> weight;
	map<int,int> best;
	best[0] = 0;
	float fin = 0;
	vector<cow> cows(n);
	for(int ii = 0; ii < n; ii++)
		cin >> cows[ii].first >> cows[ii].second;
	sort(cows.begin(),cows.end());

	for(int ii = 0; ii < n; ii++)
	{
		vector<cow> to_add;
		cow c = cows[ii];
		for(auto it : best)
		{
			if(it.first < weight || score(c) > score(it))
				to_add.push_back(it+c);
		}
		for(auto it : to_add)
		{
			best[it.first] = max(best[it.first],it.second);
			if(it.first >= weight)
				fin = max(fin, score(it));
		}
	}
	cout << (int)(fin*1000) << '\n';
}
