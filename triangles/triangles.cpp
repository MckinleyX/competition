#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1000000007;
struct post 
{
	ll x;
	ll y;
	ll bs;
	ll hs;
};
bool xcmp(post a, post b)
{
	if(a.x == b.x)
		return a.y < b.y;
	return a.x < b.x;
}
bool ycmp(post a, post b)
{
	if(a.y == b.y)
		return a.x < b.x;
	return a.y < b.y;
}
int main()
{
	freopen("triangles.in","r",stdin);
	freopen("triangles.out","w",stdout);
	int num;
	cin >> num;
	vector<post> posts;
	posts.resize(num);
	for(int ii = 0; ii < num; ii++)
	{
		post p;
		cin >> p.x >> p.y;
		posts[ii] = p;
	}
	sort(posts.begin(),posts.end(),xcmp);
	pair<int,int> range = {-1,0};
	//inclusive on left, exclusive on right
	for(int ii = 0; ii < num; ii++)
	{
		ll sum = 0;
		if(ii >= range.second)
		{
			range.first = ii;
			for(int jj = ii+1; jj < num &&
					posts[jj].x == posts[ii].x; jj++)
			{
				sum += abs(posts[jj].y - posts[ii].y);
				range.second = jj;
			}
			range.second++;
		}
		else
		{
			ll diff = posts[ii].y - posts[ii-1].y;
			sum = posts[ii-1].hs 
				+ diff*(ii-range.first)
				- diff*(range.second-ii);
		}
		posts[ii].hs = sum;
	}
	sort(posts.begin(),posts.end(),ycmp);
	range = {-1,0};
	for(int ii = 0; ii < num; ii++)
	{
		ll sum = 0;
		if(ii >= range.second)
		{
			range.first = ii;
			for(int jj = ii+1; jj < num &&
					posts[jj].y == posts[ii].y; jj++)
			{
				sum += abs(posts[jj].x - posts[ii].x);
				range.second = jj;
			}
			range.second++;
		}
		else
		{
			ll diff = posts[ii].x - posts[ii-1].x;
			sum = posts[ii-1].bs 
				+ diff*(ii-range.first)
				- diff*(range.second-ii);
		}
		posts[ii].bs = sum;
	}
	ll ans = 0;
	for(int ii = 0; ii < num; ii++)
	{
		ans += posts[ii].bs*posts[ii].hs;
		ans %= MOD;
	}
	cout << ans << '\n';
	return 0;
}
