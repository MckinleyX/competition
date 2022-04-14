#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,x;
	int ans = 0;
	cin >> n >> x;
	int* kids = new int[n];
	for(int ii = 0; ii < n; ii++)
	{
		cin >> kids[ii];
	}
	sort(kids,kids+n);
	int a = 0;
	int b = n-1;
	while(b >= a)
	{
		if(kids[a] + kids[b] <= x)
			a++;
		b--;
		ans++;
	}
	cout << ans << endl;
}
