#include <iostream>
using namespace std;
int main()
{
	long long n;
	cin >> n;
	long long* sums = new long long[n];
	sums[0] = 1;
	long long pre = 0;
	long long ans = 0;
	for(long long ii = 0; ii < n; ii++)
	{
		long long num;
		cin >> num;
		pre += num;
		pre = (pre % n + n) % n;
		ans += sums[pre];
		sums[pre]++;
	}
	cout << ans;
	return 0;
}
