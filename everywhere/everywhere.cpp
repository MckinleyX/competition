//Codeforces: They are everywhere
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
	int num;
	cin >> num;
	unordered_set<char> types;
	map<char,int> found;
	string arr;
	arr.resize(num);
	for(int ii = 0; ii < num; ii++)
	{
		cin >> arr[ii];
		types.insert(arr[ii]);
	}
	int l = 0;
	int r = 0;
	int best = num;
	while(r < num)
	{
		if(found.size() == types.size())
		{
			if(best > r-l)
				best = r-l;
			found[arr[l]]--;
			if(found[arr[l]] == 0)
				found.erase(arr[l]);
			l++;
		}
		else
			found[arr[r++]]++;
	}
	return 0;
}
