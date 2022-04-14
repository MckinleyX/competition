#include <bits/stdc++.h>
using namespace std;
struct cow
{
	int x,y;
	int sum = -1;
	vector<cow*> stop;
	int ind;
	int compute_sum()
	{
		if(sum != -1)
			return sum;
		sum = 1;
		for(cow* c : stop)
		{
			sum += (*c).compute_sum();
		}
		return sum;
	}
};
bool ncmp(const cow& a, const cow& b) { return a.x < b.x; }
bool ecmp(const cow& a, const cow& b) { return a.y < b.y; }
bool icmp(const cow& a, const cow& b) { return a.ind < b.ind; }
int main()
{
	int num;
	freopen("rut.in","r",stdin);
	cin >> num;
	vector<cow> ecow;
	vector<cow> ncow;
	for(int ii = 0; ii < num; ii++)
	{
		char dir;
		cow c;
		cin >> dir >> c.x >> c.y;
		c.ind = ii;
		if(dir == 'E')
			ecow.push_back(c);
		else
			ncow.push_back(c);
	}
	sort(ecow.begin(),ecow.end(),ecmp);
	sort(ncow.begin(),ncow.end(),ncmp);
	for(cow c : ecow)
	{
		auto it = lower_bound(ncow.begin(),ncow.end(),c,ncmp);
		while(it != ncow.end())
		{
			cow nc = *it;
			if(nc.y <= c.y && nc.x + nc.y > c.x + c.y)
			{
				c.stop.push_back(&(*it));
				it = ncow.end();
			}
			else
				it++;
		}
	}
	for(cow c : ncow)
	{
		auto it = lower_bound(ecow.begin(),ecow.end(),c,ecmp);
		while(it != ecow.end())
		{
			cow ec = *it;
			if(ec.y <= c.y && ec.x + ec.y > c.x + c.y)
			{
				c.stop.push_back(&(*it));
				it = ecow.end();
			}
			else
				it++;
		}
	}
	ecow.insert(ecow.end(),ncow.begin(),ncow.end());
	sort(ecow.begin(),ecow.end(),icmp);
	for(cow c : ecow)
		cout << c.compute_sum() << '\n';
			
	return 0;
}
