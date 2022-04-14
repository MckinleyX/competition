#include <iostream>
#include <map>
using namespace std;
int main()
{
	int n;
	long x;
	cin >> n >> x;
	map<long, int> sums;
	sums[0] = 1;
	long pre = 0;
	long ans = 0;
	for(int ii = 0; ii < n; ii++)
	{
		long num;
		cin >> num;
		pre += num;
		ans += sums[pre-x];
		sums[pre]++;
	}
	cout << ans;
	return 0;
}
