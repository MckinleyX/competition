#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template<class T> using Tree = tree<
T, null_type, less<T>,
	rb_tree_tag, tree_order_statistics_node_update
	>;
int main()
{
	cin.tie(0) -> sync_with_stdio(0);
	freopen("circlecross.in","r",stdin);
	freopen("circlecross.out","w",stdout);
	int n;
	cin >> n;
	ll ans = 0;
	Tree<int> circle;
	vector<int> ind_find(n+1);//given cow, find first index
	for(int ii = 1; ii <= 2*n; ii++)
	{
		int cow;
		cin >> cow;
		if(circle.find(ind_find[cow]) == circle.end())
		{
			ind_find[cow] = ii;
			circle.insert(ii);
		}
		else
		{
			ans += circle.size() - circle.order_of_key(ind_find[cow]) - 1;
			circle.erase(circle.find(ind_find[cow]));
		}
	}
	cout << ans << '\n';
}
