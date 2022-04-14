#include <bits/stdc++.h>
using namespace std;
using ll = long long;
bool test(ll nn, ll kk, ll min, ll mid)
{
	double base = (double)(mid-1)/mid;
	ll d_days = max(0.0,log((double)mid*min/nn)/log(base));
	ll milk_exp = ceil(nn*(1-exp(log(base)*d_days)));
	ll milk_min = (kk-d_days)*min;
	return nn <= milk_min + milk_exp;
	/*
	ll days = 0;
	while(nn/mid > min)
	{
		days++;
		nn -= nn/mid;
	}
	return days + ceil((double)nn/min) <= kk;
	*/
}
int main()
{
	freopen("loan.in","r",stdin);
	//freopen("loan.out","w",stdout);
	ll nn, kk, min;
	cin >> nn >> kk >> min;
	ll lo = 1;
	ll hi = nn/min + 1;
	while(lo < hi)
	{
		ll mid = lo + (hi-lo+1)/2;
		if(test(nn,kk,min,mid))
			lo = mid;
		else
			hi = mid-1;
	}
	cout << lo << endl;
}
