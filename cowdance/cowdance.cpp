#include <bits/stdc++.h>
using namespace std;
int time(int* cows, int num_c, int k)
{
	priority_queue<int,vector<int>,greater<int>> stage;
	for(int ii = 0; ii < k; ii++)
		stage.push(cows[ii]);
	for(int ii = k; ii < num_c; ii++)
	{
		stage.push(stage.top() + cows[ii]);
		stage.pop();
	}
	while(stage.size() > 1)
		stage.pop();
	return stage.top();
}
int main()
{
	ifstream fin("cowdance.in");
	ofstream fout("cowdance.out");
	int num;
	int max;
	fin >> num >> max;
	int* cows = new int[num];
	for(int ii = 0; ii < num; ii++)
		fin >> cows[ii];
	int lo = 1;
	int hi = num;
	while(lo < hi)
	{
		int mid = lo + (hi - lo + 1)/2;
		int t = time(cows,num,mid);
		if(t > max)
			lo = mid;
		else
			hi = mid-1;
	}
	fout << lo+1 << endl;
}
