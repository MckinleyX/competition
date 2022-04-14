//Codeforces: USB vs PS/2
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using mouse = pair<int, int>; //0 for usb, 1 for ps/2
int main()
{
	cin.tie(0) -> sync_with_stdio(0);
	int a,b,c;//usb, ps2, both
	cin >> a >> b >> c;
	int n;
	cin >> n;
	vector<mouse> mice;
	mice.reserve(n);
	for(int ii = 0; ii < n; ii++)
	{
		int price;
		string type;
		cin >> price >> type;
		mice.push_back(make_pair(price, type=="PS/2"));
	}
	
	sort(mice.begin(),mice.end());
	
	ll total_price = 0;
	int num_equip = 0;
	for(int ii = 0; ii < n && a+b+c > 0; ii++)
	{
		if(b > 0 && mice[ii].second)
		{
			total_price += mice[ii].first;
			num_equip++;
			b--;
		}
		else if(a > 0 && !mice[ii].second)
		{
			total_price += mice[ii].first;
			num_equip++;
			a--;
		}
		else if(c > 0)
		{
			total_price += mice[ii].first;
			num_equip++;
			c--;
		}
	}
	cout << num_equip << " " << total_price << endl;
}
