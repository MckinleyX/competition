#include <bits/stdc++.h>
#define MOD 1000000009ll
using namespace std;
using ll = long long;
int main()
{
	int num, tol;
	cin >> num >> tol;
	ll* blocks = new ll[num];
	for(int ii = 0; ii < num; ii++)
		cin >> blocks[ii];
	sort(blocks,blocks+num);
	int l;
	l = 0;
	ll* addable = new ll[num];
	for(int r = 0; r < num; r++)
	{
		while(blocks[l]+tol < blocks[r])
			l++;
		addable[r] = r-l;
	}
	ll* ans = new ll[num];
	ans[0] = 1;
	for(int ii = 1; ii < num; ii++)
	{
		ans[ii] = ans[ii-1]*(addable[ii]+1);
		ans[ii] %= MOD;
	}
	cout << ans[num-1] << '\n';
	return 0;
}
