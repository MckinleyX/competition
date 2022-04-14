#include <bits/stdc++.h>
using namespace std;
int main()
{
	ifstream fin("maxcross.in");
	ofstream fout("maxcross.out");
	int n;
	int k;
	int b;
	fin >> n >> k >> b;
	int* lights = new int[n];
	for(int ii = 0; ii < b; ii++)
	{
		int num;
		fin >> num;
		lights[num-1]++;
	}
	int* pre = new int[n+1];
	pre[0] = 0;
	for(int ii = 1; ii <= n; ii++)
	{
		pre[ii] = pre[ii-1]+lights[ii-1];
	}
	int min = pre[k];
	for(int ii = 0; ii <= n-k; ii++)
	{
		int fix = pre[ii+k] - pre[ii];
		if(fix < min)
			min = fix;
	}
	fout << min;
	return 0;
}
