#include <bits/stdc++.h>
using namespace std;
int main()
{
	ifstream fin("lazy.in");
	ofstream fout("lazy.in");
	int n,k;
	fin >> n >> k;
	int** vals = new int*[n];
	int** sums = new int*[n];
	for(int ii = 0; ii < n; ii++)
	{
		vals[n] = new int[n];
		sums[n] = new int[n];
	}
	for(int ii = 0; ii < n; ii++)
	{
		for(int jj = 0; jj < n; jj++)
		{
			fin >> vals[ii][jj];
		}
	}


	return 0;
}
