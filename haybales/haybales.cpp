#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
	cin.tie(0) -> sync_with_stdio(0);
	ll num_bales;
	ll num_queries;
	cin >> num_bales >> num_queries;
	vector<int> bales(num_bales);
	for(int ii = 0; ii < num_bales; ii++)
		cin >> bales[ii];
	sort(bales.begin(),bales.end());
	for(int ii = 0; ii < num_queries; ii++)
	{
		int start,end;
		cin >> start >> end;
		cout << upper_bound(bales.begin(),bales.end(),end) - lower_bound(bales.begin(),bales.end(),start);
		cout << '\n';
	}
}
