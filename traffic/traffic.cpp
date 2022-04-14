#include <bits/stdc++.h>
using namespace std;
int main()
{
	cin.tie(0) -> sync_with_stdio(0);
	int x;
	int n;
	cin >> x >> n;
	set<int> road;
	road.insert(0);
	road.insert(x);
	multiset<int> lengths;
	lengths.insert(x);
	for(int ii = 0; ii < n; ii++)
	{
		int light;
		cin >> light;
		road.insert(light);
		auto it = road.find(light);
		int a = *prev(it), b = *next(it);
		lengths.erase(lengths.find(b - a));
		lengths.insert(light - a);
		lengths.insert(b - light);
		cout << *lengths.rbegin() << " ";
	}
	return 0;
}
