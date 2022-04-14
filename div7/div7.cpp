#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	ifstream fin("div7.in");
	ofstream fout("div7.out");
	int num;
	fin >> num;
	int* pre = new int[num+1];
	pre[0] = 0;
	for(int ii = 1; ii <= num; ii++)
	{
		int inp;
		fin >> inp;
		pre[ii] = (pre[ii-1] + inp)%7;
	}
	for(int ii = num; ii > 0; ii--)
	{
		for(int jj = 0; jj < num - ii; jj++)
		{
			if(pre[jj+ii] == pre[jj])
			{
				fout << ii << endl;
				return 0;
			}
		}
	}
	return 0;
}
