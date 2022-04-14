//Problem name: Stick Lengths
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
	int n;
	cin >> n;
	long long* sticks = new long long[n];
	for(int ii = 0; ii < n; ii++)
	{
		cin >> sticks[ii];
	}
	sort(sticks,sticks+n);
	ll median = sticks[n/2];
	ll ans = 0;
	for(int ii = 0; ii < n; ii++)
		ans += abs(median - sticks[ii]);
	cout << ans << endl;
}
