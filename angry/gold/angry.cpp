#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int explode(vector<ll> bales, double rad, ll first)
{
	double curr_rad = 0;
	ll curr = first+1;
	while(curr < bales.size()  && curr_rad < rad)
	{
		//Minimum radius from current cow to the left
		curr_rad = max(curr_rad+1,double(bales[curr]-bales[curr-1]));
		curr++;
	}
	if(curr_rad > 2*rad)
		return curr;
	curr_rad = rad-1;
	while(curr < bales.size() && curr_rad >= bales[curr]-bales[curr-1])
	{
		curr++;
		curr_rad--;
	}
	return curr;
}
bool check(vector<ll> bales, double rad)
{
	return explode(bales,rad,0) >= bales.size();
}
int main()
{
	//freopen("angry.in","r",stdin);
	//freopen("angry.out","w",stdout);
	int n;
	cin >> n;
	vector<ll> bales(n);
	for(int ii = 0; ii < n; ii++)
		cin >> bales[ii];
	sort(bales.begin(),bales.end());
	int hi = (bales[n-1]-bales[0]);
	int lo = 0;
	while(lo < hi)
	{
		int mid = lo + (hi-lo+1)/2;
		//cout << double(mid)/2 << '\n';
		if(check(bales,double(mid)/2))
			hi = mid-1;
		else
			lo = mid;
	}
	printf("%1.1f\n",double(lo+1)/2);
}
