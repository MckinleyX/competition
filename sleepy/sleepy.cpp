//USACO: Sleepy Cow Sort
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <class T> using Tree = tree<T,
null_type, less<T>, rb_tree_tag, 
	tree_order_statistics_node_update>;
int main()
{
	cin.tie(0) -> sync_with_stdio(0);
	freopen("sleepy.in","r",stdin);
	freopen("sleepy.out","w",stdout);
	int n;
	cin >> n;
	vector<int> cows(n);
	Tree<int> tail;
	for(int ii = 0; ii < n; ii++)
		cin >> cows[ii];

	int tail_ind = n-1;
	while(tail_ind >= 0 && tail.order_of_key(cows[tail_ind]) == 0)
		tail.insert(cows[tail_ind--]);
	tail_ind++;
	cout << tail_ind << '\n';
	for(int ii = 0; ii < tail_ind; ii++)
	{
		cout << (n-tail.size()) + tail.order_of_key(cows[ii]) - 1;
		tail.insert(cows[ii]);
		if(ii != tail_ind - 1)
			cout << " ";
	}
	cout << '\n';
}
