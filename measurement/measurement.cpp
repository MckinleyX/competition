#include <bits/stdc++.h>
using namespace std;
typedef pair<int, pair<int,int>> entry;
int main()
{
	ifstream fin("measurement.in");
	ofstream fout("measurement.out");
	int n;
	int g;
	fin >> n >> g;
	multiset<int> rank;
	vector<entry> logs(n);
	rank.insert(g);
	for(int ii = 0; ii < n; ii++)
	{
		entry e;
		cin >> e.first >> e.second.first;
		char sign;
		cin >> sign;
		cin >> e.second.second;
		if (sign == '-')
			e.second.second = -e.second.second;
		logs[ii] = (e);
	}
	sort(logs.begin(),logs.end());
	ll ans = 0;
	for(entry e : logs)
	{
		pair<int,int> change = e.second;
		
	}
}
