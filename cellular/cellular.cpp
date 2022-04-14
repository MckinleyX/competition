#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INFTY = 2000000000ll;
int main()
{
	int num_c,num_t;
	cin >> num_c >> num_t;
	vector<ll> cities(num_c), towers(num_t);
	for(int ii = 0; ii < num_c; ii++)
		cin >> cities[ii];
	for(int ii = 0; ii < num_t; ii++)
		cin >> towers[ii];
	sort(cities.begin(),cities.end());
	sort(towers.begin(),towers.end());
	int t_b = -1;//index before city
	ll ans = 0;
	for(int ii = 0; ii < num_c; ii++)
	{
		while(t_b < num_t-1 && towers[t_b+1] < cities[ii])
			t_b++;
		ll distance = INFTY;
		if(t_b > -1)
			distance = min(distance, cities[ii]-towers[t_b]);
		if(t_b < num_t-1)
			distance = min(distance, towers[t_b+1]-cities[ii]);
		ans = max(ans, distance);
	}
	cout << ans << endl;
}
