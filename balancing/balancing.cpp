#include <bits/stdc++.h>
using namespace std;
int main()
{
	ifstream fin("balancing.in");
	ofstream fout("balancing.out");
	//FOR SILVER
	unsigned int num;
	fin >> num;
	//FOR BRONZE
	//unsigned int num,size;
	//fin >> num >> size;
	vector<pair<unsigned long,unsigned long>> cows(num);
	set<unsigned long> xs;
	set<unsigned long> ys;
	for(unsigned int ii = 0; ii < num; ii++)
	{
		unsigned long x,y;
		fin >> x >> y;
		cows[ii] = make_pair(x,y);
		xs.insert(x);
		ys.insert(y);
	}
	int opt = ceil(((float)num)/4);
	int best = num;
	bool flag1 = false;
	for(unsigned int x : xs)
	{
		if(!flag1)
		{
			bool flag2 = false;
			for(unsigned int y : ys)
			{
				if(!flag2 && !flag1)
				{
					int sectors[4] = {0,0,0,0};
					for(pair<unsigned long, unsigned long> p : cows)
					{
						int index = 0;
						if(p.first < x)
							index += 2;
						if(p.second < y)
							index += 1;
						sectors[index]++;
					}
					int max = 0;
					for(int m : sectors)
					{
						if(m > max)
							max = m;
					}
					flag1 = 2*best < sectors[2] + sectors[3];
					flag2 = max == sectors[3];
					//cout << max << " " << x << " " << y << endl;
					if(max < best)
						best = max;
					if(best == opt)
					{
						fout << best << endl;
						return 0;
					}
				}
			}
		}
	}
	fout << best << endl;
	return 0;

}
