#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> cow_s;
//First number is production, second is count
int main()
{
	ifstream fin("pairup.in");
	ofstream fout("pairup.out");
	int n;
	fin >> n;
	int max = 0;
	cow_s* cows = new cow_s[n];
	for(int ii = 0; ii < n; ii++)
	{
		fin >> cows[ii].second >> cows[ii].first;
	}
	sort(cows,cows+n);
	int l = 0;
	int r = n-1;
	int sum = 0;
	while(l < r)
	{
		sum = cows[l].first + cows[r].first;
		if(sum > max)
			max = sum;
		if(cows[l].second > cows[r].second)
		{
			cows[l].second -= cows[r].second;
			r--;
		}
		else if(cows[l].second < cows[r].second)
		{
			cows[r].second -= cows[l].second;
			l++;
		}
		else
		{
			l++;
			r--;
		}
	}
	fout << max << endl;
	return 0;
}
