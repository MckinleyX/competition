#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using peak = pair<int,int>;
int main()
{
	freopen("mountains.in","r",stdin);
	freopen("mountains.out","w",stdout);
	int num;
	cin >> num;
	peak* peaks = new peak[num];
	for(int ii = 0; ii < num; ii++)
	{
		int x,y;
		cin >> x >> y;
		peaks[ii].first = y+x;
		peaks[ii].second = y-x;
	}
	sort(peaks,peaks+num,greater<>());
	int greatest = peaks[0].second;
	ll ans = num;
	for(int ii = 1; ii < num; ii++)
	{
		if(peaks[ii].second > greatest)
			greatest = peaks[ii].second;
		else
			ans--;
	}
	cout << ans << endl;
}
