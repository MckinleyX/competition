#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll combine(ll a, ll b)
{ return a+b; }
const int START_VAL = 0;

void update(int ind, ll val, ll *arr, int len)
{
	ind += len;
	arr[ind] = val;
	ind = ind >> 1;
	while(ind > 0)
	{
		arr[ind] = combine(arr[ind << 1], arr[(ind << 1) + 1]);
		ind = ind >> 1;
	}
}
ll query(int l, int r, ll *arr, int len)
{
	int l_ind = l + len;
	int r_ind = r + len;
	ll ans = START_VAL;
	while(l_ind < r_ind)
	{
		//move left up a layer
		if(l_ind % 2)
			ans = combine(ans, arr[l_ind]);
		l_ind = (l_ind+1) >> 1;

		//move right up a layer
		if(!(r_ind % 2))
			ans = combine(ans, arr[r_ind]);
		r_ind = (r_ind-1) >> 1;
	}
	if(l_ind == r_ind)
		ans = combine(ans, arr[l_ind]);
	return ans;
}
int main()
{
	cin.tie(0) -> sync_with_stdio(0);
	int num_v,num_q;
	cin >> num_v >> num_q;
	ll* arr = new ll[2*num_v];
	//binary tree, root at 1
	for(int ii = 0; ii < num_v; ii++)
	{
		int a;
		cin >> a;
		update(ii, a, arr, num_v);
	}
	for(int ii = 0; ii < num_q; ii++)
	{
		int type, a,b;
		cin >> type >> a >> b;
		if(type == 1)
			update(a-1,b,arr,num_v);
		else
			cout << query(a-1,b-1,arr,num_v) << '\n';
	}
	//for(int ii = 0; ii < 2*num_v; ii++)
	//	cout << arr[ii] << " ";
	//cout << '\n';
	delete[] arr;
}
