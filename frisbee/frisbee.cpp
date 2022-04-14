#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using cow = pair<int,int>;
int main()
{
	cin.tie(0) -> sync_with_stdio(0);
	
	int num_cows;
	stack<cow> st;
	ll ans = 0;
	cin >> num_cows;
	for(int ii = 0; ii < num_cows; ii++)
	{
		int next;
		cin >> next;
		while(st.size() > 0 && st.top().first < next)
		{
			ans += ii - st.top().second + 1;
			st.pop();
		}
		if(st.size() > 0)
			ans += ii - st.top().second + 1;
		st.push(make_pair(next,ii));
	}
	cout << ans << endl;
}
