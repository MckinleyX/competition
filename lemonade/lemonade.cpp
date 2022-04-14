#include <bits/stdc++.h>
using namespace std;
int main()
{
	ifstream fin("lemonade.in");
	ofstream fout("lemonade.out");
	long long num;
	fin >> num;
	long long* cows = new long long[num];
	for(int ii = 0; ii < num; ii++)
		fin >> cows[ii];
	sort(cows,cows+num);
	long long ans = 0;
	while(ans < num && cows[num - 1 - ans] >= ans)
		ans++;
	fout << ans << endl;
	return 0;
}
