// CSES: Distinct Values Queries
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define IT(ARR) ARR.begin(), ARR.end()
int main()
{
	cin.tie(0) -> sync_with_stdio(0);
	int n,q;
	cin >> n >> q;
	int arr_size = 1;
	while(arr_size < n)
		arr_size = arr_size << 1;
	vector<set<int>> seg_tree(2*arr_size+1);
	for(int ii = arr_size; ii < arr_size+n; ii++)
	{
		int num;
		cin >> num;
		seg_tree[ii].insert(num);
	}
	for(int ii = arr_size-1; ii >= 0; ii--)
	{
		seg_tree[ii].insert(IT(seg_tree[2*ii]));
		seg_tree[ii].insert(IT(seg_tree[2*ii+1]));
	}
	for(int ii = 0; ii < q; ii++)
	{
		int start, stop;
		cin >> start >> stop;
		start = start + arr_size - 1;
		stop = stop + arr_size - 1;
		set<int> query;
		while(start < stop)
		{
			if((start & 1) == 1)
			{
				query.insert(IT(seg_tree[start]));
				start++;
			}
			if((stop & 1) == 0)
			{
				query.insert(IT(seg_tree[stop]));
				stop--;
			}
			start /= 2;
			stop /= 2;
		}
		if(start == stop)
			query.insert(IT(seg_tree[start]));
		cout << query.size() << '\n';
	}
}
