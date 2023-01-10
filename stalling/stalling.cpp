//USACO: Just Stalling (Bronze, Dec 2021)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
	cin.tie(0) -> sync_with_stdio(0);
	int n;
	cin >> n;
	vector<int> cows(n);
	vector<int> stalls(n);
	for(int ii = 0; ii < n; ii++)
		cin >> cows[ii];
	for(int ii = 0; ii < n; ii++)
		cin >> stalls[ii];
	sort(cows.begin(),cows.end(),greater<int>());
	sort(stalls.begin(),stalls.end(),greater<int>());
	int h_ind = 0;//height index for stalls;
	ll ans = 1;
	for(int ii = 0; ii < n; ii++)
	{
		while(h_ind < n-1 && stalls[h_ind+1] >= cows[ii])
			h_ind++;
		ans *= (h_ind - ii + 1);
	}
	cout << ans << '\n';
}
