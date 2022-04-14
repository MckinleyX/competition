//CodeForces: Mortal Kombat Tower
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
	int n;
	cin >> n;
	vector<int> arr(n);
	for(int ii = 0; ii < n; ii++)
		cin >> arr[ii];
	vector<int> costf(n+1);//cost at start of friend turn
	vector<int> costm(n+1);//cost at start of my turn
	for(int ii = 0; ii <= n; ii++)
	{
		costf[ii] = 2e5;
		costm[ii] = 2e5;
	}
	costf[0] = 0;
	for(int ii = 1; ii <= n; ii++)
	{
		costm[ii] = costf[ii-1]+arr[ii-1];
		costf[ii] = costm[ii-1];
		if(ii >= 2)
		{
			costm[ii] = min(costm[ii],costf[ii-2]+arr[ii-2]+arr[ii-1]);
			costf[ii] = min(costf[ii],costm[ii-2]);
		}
	}
	cout << min(costf[n],costm[n]) << '\n';
	return;
}
int main()
{
	cin.tie(0) -> sync_with_stdio(0);
	int t;
	cin >> t;
	for(int ii = 0; ii < t; ii++)
		solve();
}
