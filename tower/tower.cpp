//CSES: Towers
#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	multiset<int> towers;
	for(int ii = 0; ii < n; ii++)
	{
		int next;
		cin >> next;
		if(towers.upper_bound(next) != towers.end())
			towers.erase(towers.upper_bound(next));
		towers.insert(next);
	}
	cout << towers.size() << endl;
}
