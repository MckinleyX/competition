#include <bits/stdc++.h>
using namespace std;
struct cow
{
	long x;
	long y;
	long d;
};
int main()
{
	int num;
	cin >> num;
	cow* cows = new cow[num];
	vector<cow> east;
	vector<cow> north;
	for(int ii = 0; ii < num; ii++)
	{
		char dir;
		cin >> dir;
		vector<cow>* add;
		if(dir == 'E')
		{
			add = &east;
		}
		else if(dir == 'N')
		{
			add = &north;
		}
		else
		{
			assert(false);
		}
		long x,y;
		cin >> x >> y;
		cow c = {x, y, 0};
		(*add).push_back(c);
	}
	for(int ii = 0; ii < num; ii++)
	{
		cout << cows[ii].d << endl;
	}
	return 0;
}
