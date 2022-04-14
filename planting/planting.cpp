#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
	freopen("planting.in","r",stdin);
	freopen("planting.out","w",stdout);
	int n;
	cin >> n;
	vector<int> sol(n);
	for(int ii = 0; ii < n-1; ii++)
	{
		int a,b;
		cin >> a >> b;
		sol[a-1]++;
		sol[b-1]++;
	}
	int ans = 0;
	for(int ii = 0; ii < n; ii++)
	{
		ans = max(ans,sol[ii]);
	}
	cout << ans+1 << '\n';
	
}
