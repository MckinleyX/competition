#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pos = pair<ll,ll>;
bool ycmp(pos a, pos b){return a.second < b.second;}
int main()
{
	freopen("split.in","r",stdin);
	freopen("split.out","w",stdout);
	int num;
	cin >> num;
	pos* cows = new pos[num];
	for(int ii = 0; ii < num; ii++)
	{
		cin >> cows[ii].first >> cows[ii].second;
	}
	sort(cows, cows+num);
	//Area of single fence
	ll xmin,ymin,xmax,ymax;
	xmin = xmax = cows[0].first;
	ymin = ymax = cows[0].second;
	for(int ii = 1; ii < num; ii++)
	{
		if(xmin > cows[ii].first)
			xmin = cows[ii].first;
		else if(xmax < cows[ii].first)
			xmax = cows[ii].first;

		if(ymin > cows[ii].second)
			ymin = cows[ii].second;
		else if(ymax < cows[ii].second)
			ymax = cows[ii].second;
	}
	ll area_init = (xmax-xmin)*(ymax-ymin);

	ll area_best = area_init;
	//Rectangles are horizontal
	multiset<int> left;
	multiset<int> right;
	for(int ii = 0; ii < num; ii++)
		right.insert(cows[ii].second);

	for(int ii = 0; ii < num-1; ii++)
	{
		right.erase(right.find(cows[ii].second));
		left.insert(cows[ii].second);
		ll l_xlen = (cows[ii].first - cows[0].first);
		ll l_ylen = (*left.rbegin() - *left.begin());
		ll r_xlen = (cows[num-1].first - cows[ii+1].first);
		ll r_ylen = (*right.rbegin() - *right.begin());
		ll area_curr = l_xlen*l_ylen + r_xlen*r_ylen;
		if(area_curr < area_best)
			area_best = area_curr;
	}
	left.clear();
	right.clear();
	//Rectangles are vertical
	sort(cows,cows+num,ycmp);
	for(int ii = 0; ii < num; ii++)
		right.insert(cows[ii].first);

	for(int ii = 0; ii < num-1; ii++)
	{
		right.erase(right.find(cows[ii].first));
		left.insert(cows[ii].first);
		ll l_xlen = (cows[ii].second - cows[0].second);
		ll l_ylen = (*left.rbegin() - *left.begin());
		ll r_xlen = (cows[num-1].second - cows[ii+1].second);
		ll r_ylen = (*right.rbegin() - *right.begin());
		ll area_curr = l_xlen*l_ylen + r_xlen*r_ylen;
		if(area_curr < area_best)
			area_best = area_curr;
	}
	cout << area_init - area_best << endl;

}
