#include <bits/stdc++.h>
using namespace std;
int main()
{
	ifstream fin("berries.in");
	ofstream fout("berries.out");
	int num_t, num_b;
	fin >> num_t >> num_b;
	multiset<int> baskets;
	for(int ii = 0; ii < num_t; ii++)
	{
		int num;
		fin >> num;
		baskets.insert(num);
	}
	while((int)baskets.size() < num_b)
		baskets.insert(0);
	while((int)baskets.size() > num_b)
		baskets.erase(baskets.begin());

	
	
	pair<int,int> max;//Maximum change
	max.first = 0;
	max.second = 0;
	do
	{
		int max_b = *baskets.rbegin();
		multiset<int> best;
		for(int ii = 1; ii <= num_b; ii++)
		{
			multiset<int> test = baskets;
			int split = *test.rbegin()/ii;
			for(int jj = 0; jj < ii; jj++)
			{
				if(jj < max_b % ii)
					test.insert(split+1);
				else
					test.insert(split);
			}
			while(test.size() > num_b)
				test.erase(test.begin());
			int sum = 0;
			auto it = test.begin();
			for(int ii = 0; ii < num_b; ii++)
				sum += *it;
			if(sum > max.second)
			{
				max.first = ii;
				max.second = sum;
				best = test;
			}
		}
		baskets = best;
	}while(max.first != 1);
	auto it = baskets.begin();
	int ans;
	for(int ii = 0; ii < num_b/2; ii++)
	{
		ans += *it;
		it++;
	}
	return 0;
}
