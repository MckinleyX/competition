#include <bits/stdc++.h>
using namespace std;
using ll = long long;
bool check(ll* bales, int num_b, int num_c, int rad)
{
	int cows_used = 1;
	int first_ind = 0;
	for(int ii = 0; ii < num_b; ii++)
	{
		if(bales[ii] - bales[first_ind] > 2*rad)
		{
			first_ind = ii;
			cows_used++;
		}
	}
	return cows_used <= num_c;
}
int main()
{
	freopen("angry.in","r",stdin);
	freopen("angry.out","w",stdout);
	int n,k;
	cin >> n >> k;
	ll* bales = new ll[n];
	for(int ii = 0; ii < n; ii++)
		cin >> bales[ii];
	sort(bales,bales+n);
	int hi = (bales[n-1]-bales[0])/2;
	int lo = 0;
	while(lo < hi)
	{
		int mid = lo + (hi-lo+1)/2;
		if(check(bales,n,k,mid))
			hi = mid-1;
		else
			lo = mid;
	}
	cout << lo+1 << endl;
}
