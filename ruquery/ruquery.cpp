// CSES: Range Update Queries
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll combine(ll a, ll b){return a+b;}
void update(int ind, ll val, ll* arr, int len)
{
	ind += len;
	arr[ind] += val;
	ind = ind >> 1;
	while(ind > 0)
	{
		arr[ind] = combine(arr[ind*2],arr[ind*2+1]);
		ind = ind >> 1;
	}
}
ll query(int ind, ll* arr, int len)
{
	int l_ind = len;
	int r_ind = ind + len;
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
	int n,q;
	cin >> n >> q;
	ll* dat = new ll[n];
	ll* arr = new ll[2*n];
	for(int ii = 0; ii < n; ii++)
		cin >> dat[ii];
	update(0,dat[0],arr,n);
	for(int ii = 1; ii < n; ii++)
		update(ii, dat[ii]-dat[ii-1],arr,n);

	for(int ii = 0; ii < q; ii++)
	{
		int type;
		cin >> type;
		if(type == 1)
		{
			ll a,b,u;
			cin >> a >> b >> u;
			a--;
			b--;
			update(a,u,arr,n);
			if(b < n-1)
				update(b+1,arr[b+1+n]-u,arr,n);
		}
		else
		{
			int v;
			cin >> v;
			cout << query(v-1,arr,n) << '\n';
		}
	}
	//for(int ii = 0; ii < 2*n; ii++)
	//	cout << arr[ii] << ' ';
	//cout << '\n';
	delete[] arr;
}
