// CSES: Range Update Queries
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll combine(ll a, ll b){return a+b;}
void update(int ind, const ll val, vector<ll> &arr)
{
	ind += arr.size()/2;
	arr[ind] += val;
	ind = ind >> 1;
	while(ind > 0)
	{
		arr[ind] = combine(arr[ind*2],arr[ind*2+1]);
		ind = ind >> 1;
	}
}
ll query(const int ind, vector<ll> &arr)
{
	int l_ind = arr.size()/2;
	int r_ind = ind + arr.size()/2;
	ll sum = 0;
	while(r_ind > l_ind)
	{
		if((r_ind & 1) == 0)
			sum += arr[r_ind];
		l_ind = l_ind >> 1;
		r_ind = (r_ind - 1) >> 1;
	}
	if(r_ind == l_ind)
		sum += arr[r_ind];
	return sum;
}
int main()
{
	cin.tie(0) -> sync_with_stdio(0);
	//freopen("ruquery.in","r",stdin);
	//freopen("ruquery.out","w",stdout);
	int n,q;
	cin >> n >> q;
	vector<ll> dat(n);
	int tree_size = 1;
	while(tree_size < 2*n)
		tree_size = tree_size << 1;
	vector<ll> arr(tree_size);
	for(int ii = 0; ii < n; ii++)
		cin >> dat[ii];
	update(0,dat[0],arr);


	for(int ii = 1; ii < n; ii++)
		update(ii, dat[ii]-dat[ii-1],arr);

	for(int ii = 0; ii < q; ii++)
	{
		int type;
		cin >> type;
		if(type == 1)
		{
			ll a,b,u;
			cin >> a >> b >> u;
			a--;
			update(a,u,arr);
			if(b < arr.size()/2)
				update(b,-u,arr);
		}
		else
		{
			int v;
			cin >> v;
			cout << query(v-1,arr) << '\n';
		}
	}
}
