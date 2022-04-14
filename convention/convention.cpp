#include "bits/stdc++.h"
using namespace std;
bool max_time(int* cows, int num_c, int num_b, int cap, int max_t)
{
	int buses = 1;
	int bus_ind = 0;
	for(int ii = 0; ii < num_c; ii++)
	{
		if(ii - bus_ind + 1 > cap 
				|| cows[ii] - cows[bus_ind] > max_t)
		{
			buses++;
			bus_ind = ii;
			ii--;
		}
	}
	//cout << max_t << " " << buses << endl;
	return buses <= num_b;
}
int main()
{
	freopen("convention.in","r",stdin);
	freopen("convention.out","w",stdout);
	//ofstream fout("convention.out");
	int num_c, num_b, cap;
	cin >> num_c >> num_b >> cap;
	int* cows = new int[num_c];
	for(int ii = 0; ii < num_c; ii++)
	{
		cin >> cows[ii];
	}
	sort(cows,cows+num_c);
	int lo = 0;
	int hi = cows[num_c-1];
	while(lo < hi)
	{
		int mid = lo + (hi - lo)/2;
		if(max_time(cows,num_c,num_b,cap,mid))
			hi = mid;
		else
			lo = mid+1;
	}
	cout << hi << endl;
}
