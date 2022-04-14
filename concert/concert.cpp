#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,m;//tickets then customers
	cin >> n >> m;
	auto cmp = [](int a, int b) { return a > b; };
	multiset<int, decltype(cmp)> tickets(cmp);
	for(int ii = 0; ii < n; ii++)
	{
		long price;
		cin >> price;
		tickets.insert(price);
	}
	for(int ii = 0; ii < m; ii++)
	{
		long price;
		cin >> price;
		auto it = tickets.lower_bound(price);
		if(it != tickets.end())
		{
			cout << *it << endl;
			tickets.erase(it);
		}
		else
			cout << -1 << endl;
	}
	return 0;
}
