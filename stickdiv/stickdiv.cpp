//CSES Stick Lengths
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll div(vector<ll> sticks)
{
	vector<ll> left,right;
	ll l_sum = 0;
	ll r_sum = 0;
	if(sticks.size() == 1)
		return 0;
	for(auto it = sticks.begin(); it != sticks.end(); it++)
	{
		if(l_sum < r_sum)
		{
			left.push_back(*it);
			l_sum += *it;
		}
		else
		{
			right.push_back(*it);
			r_sum += *it;
		}
	}
	return r_sum + l_sum + div(left) + div(right);
}
int main()
{
	int x,n;
	cin >> x >> n;
	vector<ll> sticks;
	sticks.resize(n);
	for(int ii = 0; ii < n; ii++)
	{
		cin >> sticks[ii];
	}
	sort(sticks.rbegin(),sticks.rend());
	ll cost = div(sticks);
	cout << cost << endl;
}
