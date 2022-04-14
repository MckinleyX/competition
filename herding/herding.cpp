#include <bits/stdc++.h>
using ll = long long;
using namespace std;
int main()
{
	freopen("herding.in","r",stdin);
	freopen("herding.out","w",stdout);
	int n;
	cin >> n;
	ll* cows = new ll[n];
	for(int ii = 0; ii < n; ii++)
		cin >> cows[ii];
	sort(cows,cows+n);
	ll min_m = 0;
	//Two pointers to find the interval with the most cows
	int l = 0;
	int r = 0;
	while(r < n)
	{
		r++;
		while(cows[r-1]-cows[l] >= n)
			l++;
		if(r-l > min_m)
			min_m = r-l;
	}
	min_m = n-min_m;
	if(min_m == 1) //Hacky workaround
	{
		if((cows[n-1]-cows[1] == n-2 && cows[1]-cows[0] > 2) 
				|| (cows[n-2]-cows[0] == n-2 && cows[n-1]-cows[n-2] > 2))
		{
			min_m = 2;
		}
	}

	ll max_m = cows[n-1]-cows[0]-(n-1);//Distance we need to cover
	max_m -= min(cows[n-1]-cows[n-2],cows[1]-cows[0])-1;
	//Take the smallest jump for the first move
	//Each move after that moves the endpoint by exactly 1

	cout << min_m << '\n' << max_m << endl;
}
