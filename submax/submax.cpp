#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int* nums = new int[n];
	for(int ii = 0; ii < n; ii++)
	{
		cin >> nums[ii];
	}
	long max = nums[0];
	long sum = 0;
	for(int ii = 0; ii < n; ii++)
	{
		sum += nums[ii];
		if(sum > max)
			max = sum;
		if(sum < 0)
			sum = 0;
	}
	cout << max;
	return 0;
}
