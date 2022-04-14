#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,m,k,ans = 0,ind = 0;
	cin >> n >> m >> k;
	int* appl = new int[n];
	int* size = new int[m];
	for(int ii = 0; ii < n; ii++)
		cin >> appl[ii];
	for(int ii = 0; ii < m; ii++)
		cin >> size[ii];
	sort(appl,appl+n);
	sort(size,size+m);
	for(int ii = 0; ii < n; ii++)
	{
		while(ind < m && appl[ii] - k > size[ind])
			ind++;
		if(ind < m && size[ind] <= appl[ii] + k)
		{
			ans++;
			ind++;
		}
	}
	cout << ans << endl;
}
