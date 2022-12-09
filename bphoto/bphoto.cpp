#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <class T> using Tree = tree<
T, null_type, less<T>,
	rb_tree_tag, tree_order_statistics_node_update
	>;
int main()
{
	cin.tie(0) -> sync_with_stdio(0);
	freopen("bphoto.in","r",stdin);
	freopen("bphoto.out","w",stdout);
	int num;
	cin >> num;
	Tree<ll> left;
	Tree<ll> right;
	vector<ll> lis(num);
	vector<ll> ris(num);
	vector<ll> cows(num);
	for(int ii = 0; ii < num; ii++)
		cin >> cows[ii];
	for(int ii = 0; ii < num; ii++)
	{
		lis[ii] = ii - left.order_of_key(cows[ii]);
		left.insert(cows[ii]);
	}
	for(int ii = num-1; ii >= 0; ii--)
	{
		ris[ii] = (num-ii-1) - right.order_of_key(cows[ii]);
		right.insert(cows[ii]);
	}
	int ans = 0;
	for(int ii = 0; ii < num; ii++)
	{
		if(lis[ii] > 2*ris[ii] || 2*lis[ii] < ris[ii])
			ans++;
	}
	cout << ans << '\n';
	
}
