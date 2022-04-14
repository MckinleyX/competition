#include <bits/stdc++.h>
using namespace std;
typedef pair<unsigned long long,int> num;
int main()
{
	int n;
	unsigned long long x;
	cin >> n >> x;
	num* nums = new num[n];
	for(int ii = 0; ii < n; ii++)
	{
		cin >> nums[ii].first;
		nums[ii].second = ii+1;
	}
	sort(nums,nums+n);
	for(int ii = 0; ii < n; ii++)
	{
		int jj = ii+1;
		int kk = n-1;
		while(kk > jj)
		{
			unsigned long long sum = nums[ii].first + nums[jj].first 
				+ nums[kk].first; 
			if(sum > x)
				kk--;
			else if(sum < x)
				jj++;
			else
			{
				cout << nums[ii].second << " ";
				cout << nums[jj].second << " ";
				cout << nums[kk].second << endl;
				return 0;
			}
		}
	}
	cout << "IMPOSSIBLE" << endl;
	return 0;
}
