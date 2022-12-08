#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi = pair<int,int>;
#define f first
#define s second

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T> using Tree = tree<
T, null_type, less<T>,
	rb_tree_tag, tree_order_statistics_node_update
	>;

int main()
{
	cin.tie(0) -> sync_with_stdio(0);
	freopen("haircut.in","r",stdin);
	freopen("haircut.out","w",stdout);
	int n;
	cin >> n;
	vector<int> hair(n);
	for(int ii = 0; ii < n; ii++)
		cin >> hair[ii];
	vector<ll> inv_num(n);
	Tree<pi> tree;
	for(int ii = 0; ii < n; ii++)
	{
		inv_num[hair[ii]] += ii - tree.order_of_key({hair[ii],ii});
		tree.insert({hair[ii],ii});
	}
	ll ans = 0;
	for(int ii = 0; ii < n; ii++)
	{
		cout << ans << '\n';
		ans += inv_num[ii];
	}

}

