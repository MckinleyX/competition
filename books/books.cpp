#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
	int n,t;
	cin >> n >> t;
	int* bs = new int[n];
	for(int ii = 0; ii < n; ii++)
		cin >> bs[ii];
	ll sum = 0;
	int best = 0;
	int l,r;
	l = r = 0;
	while(r < n)
	{
		sum += bs[r++];
		while(sum > t)
			sum -= bs[l++];
		if(r-l > best)
			best=r-l;
	}
	cout << best << '\n';
}
