//Out of sorts
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using num = pair<int,int>;
int main()
{
	freopen("sort.in","r",stdin);
	freopen("sort.out","w",stdout);
	int n;
	cin >> n;
	num* arr = new num[n];
	for(int ii = 0; ii < n; ii++)
	{
		cin >> arr[ii].first;
		arr[ii].second = ii;
	}
	sort(arr,arr+n);
	ll ans = 0;
	for(int ii = 0; ii < n; ii++)
	{
		if(arr[ii].second - ii > ans)
			ans = arr[ii].second - ii;
	}
	cout << ans+1 << endl;
}
