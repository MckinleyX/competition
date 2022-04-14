//CSA: Sure Bet
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
	freopen("surebet.in","r",stdin);
	cin.tie(0) -> sync_with_stdio(0);
	int n;
	cin >> n;
	vector<double> as,bs;
	as.resize(n);
	bs.resize(n);
	for(int ii = 0; ii < n; ii++)
		cin >> as[ii] >> bs[ii];

	sort(as.begin(),as.end(),greater<>());
	sort(bs.begin(),bs.end(),greater<>());
	double a,b;
	a = b = 0;
	int ai,bi;
	ai = bi = 0;
	double profit = 0;
	while(ai < n && bi < n)
	{
		if(a < b)
			a += as[ai++];
		else
			b += bs[bi++];
		profit = max(profit, min(a,b)-(ai+bi));
	}
	printf("%.4lf\n",profit);
	return 0;
}
