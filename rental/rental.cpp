#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using store = pair<ll,ll>;//price then count
int main()
{
	freopen("rental.in","r",stdin);
	freopen("rental.out","w",stdout);
	int num_cow,num_store,num_renter;
	cin >> num_cow >> num_store >> num_renter;
	ll* cows = new ll[num_cow];
	store* stores = new store[num_store];
	ll* renters = new ll[num_renter];
	for(int ii = 0; ii < num_cow; ii++)
		cin >> cows[ii];
	for(int ii = 0; ii < num_store; ii++)
		cin >> stores[ii].second >> stores[ii].first;
	for(int ii = 0; ii < num_renter; ii++)
		cin >> renters[ii];

	sort(cows,cows+num_cow,greater<>());
	sort(stores,stores+num_store,greater<>());
	sort(renters,renters+num_renter,greater<>());
	int s_ind = 0;//Index of store
	int c_ind = 0;//index of cow
	ll* money = new ll[num_cow];
	for(int ii = 0; ii < num_cow; ii++)
		money[ii] = 0;
	while(c_ind < num_cow && s_ind < num_store)
	{
		int milk_sold = min(cows[c_ind],stores[s_ind].second);
		money[c_ind] += milk_sold * stores[s_ind].first;
		cows[c_ind] -= milk_sold;
		stores[s_ind].second -= milk_sold;
		if(stores[s_ind].second == 0)
			s_ind++;
		if(cows[c_ind] == 0)
			c_ind++;
	}
	for(int ii = 0; ii < num_cow && ii < num_renter; ii++)
	{
		if(renters[ii] > money[num_cow - 1 - ii])
			money[num_cow - 1 - ii] = renters[ii];
	}
	ll ans = 0;
	for(int ii = 0; ii < num_cow; ii++)
		ans += money[ii];
	cout << ans << endl;
}
