#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pa = pair<ll,ll>;
int main()
{
	int num, sum;
	cin >> num >> sum;
	pa* nums = new pa[num];
	for(int ii = 0; ii < num; ii++)
	{
		cin >> nums[ii].first;
		nums[ii].second = ii+1;
	}
	sort(nums,nums+num);
	int l = 0;
	int r = num-1;
	while(l<r)
	{
		ll next = nums[l].first+nums[r].first;
		if(next == sum)
		{
			cout << nums[l].second << " " << nums[r].second << endl;
			return 0;
		}
		else if(next > sum)
			r--;
		else 
			l++;
	}
	cout << "IMPOSSIBLE" << '\n';
	return 0;
}
