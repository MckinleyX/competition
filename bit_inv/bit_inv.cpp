//CSES: Bit Inversions
#include <bits/stdc++.h>
using namespace std;
void upd(int num, multiset<int> &lens, set<int> &ds)
{
	if(num >= *ds.rbegin() || num <= *ds.begin())
		return;
	bool unflip = ds.count(num) != 0;
	if(!unflip)
		ds.insert(num);
	auto it = ds.find(num);
	int b = *prev(it);
	int n = *next(it);
	if(!unflip)
	{
		ds.insert(num);
		lens.erase(lens.find(n-b));
		lens.insert(num-b);
		lens.insert(n-num);
	}
	else
	{
		ds.erase(num);
		lens.erase(lens.find(num-b));
		lens.erase(lens.find(n-num));
		lens.insert(n-b);
	}
}
void upd2(int num, multiset<int> &lens, set<int> &ds)
{
	auto it = prev(ds.upper_bound(num));
	if(num == *ds.rbegin()-1)
		upd(num,lens,ds);
	else if(num == 0)
		upd(num+1,lens,ds);
	else if(*it == num && *next(it) == num+1)
	{
		int b = *prev(it);
		int n = *next(it,2);
		lens.erase(lens.begin());
		lens.erase(lens.find(num-b));
		lens.erase(lens.find(n - (num+1)));
		lens.insert(n-b);
		ds.erase(next(it));
		ds.erase(it);
	}
	else if(*it == num)
	{
		int b = *prev(it);
		int c = *it;
		int n = *next(it);
		lens.erase(lens.find(c - b));
		lens.erase(lens.find(n - c));
		lens.insert((c+1) - b);
		lens.insert(n - (c+1));
		ds.erase(it);
		ds.insert(num+1);
	}
	else if(*next(it) == num+1)
	{
		int b = *it;
		int c = *next(it);
		int n = *next(it,2);
		lens.erase(lens.find(c - b));
		lens.erase(lens.find(n - c));
		lens.insert(num - b);
		lens.insert(n - num);
		ds.erase(next(it));
		ds.insert(num);
	}
	else
	{
		int n = *next(it);
		int b = *it;
		lens.erase(lens.find(n - b));
		lens.insert(num - b);
		lens.insert(1);
		lens.insert(n - (num+1));
		ds.insert(num);
		ds.insert(num+1);
	}
}
int main()
{
	cin.tie(0) -> sync_with_stdio(0);
	string s;
	cin >> s;
	set<int> ds;//deltas
	ds.insert(0);
	ds.insert(s.size());
	multiset<int> lens;
	lens.insert(s.size());
	char prev = s[0];
	for(int ii = 1; ii < s.size(); ii++)
	{
		char curr = s[ii];
		if(curr != prev)
			upd(ii,lens,ds);
		prev = curr;
	}
	int num;
	cin >> num;
	for(int ii = 0; ii < num; ii++)
	{
		int flip;
		cin >> flip;
		upd2(flip-1,lens,ds);
		cout << *lens.rbegin() << " ";
	}
	cout << '\n';
	return 0;
}
