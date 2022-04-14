#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	ifstream fin("bcount.in");
	ofstream fout("bcount.out");
	int num_cows, num_ranges;
	fin >> num_cows >> num_ranges;
	int** cows = new int*[3];
	for(int ii = 0; ii < 3; ii++)
	{
		cows[ii] = new int[num_cows + 1];
		cows[ii][0] = 0;
	}
	for(int ii = 1; ii <= num_cows; ii++)
	{
		for(int jj = 0; jj < 3; jj++)
		{
			cows[jj][ii] = cows[jj][ii-1];
		}
		int type;
		fin >> type;
		cows[type-1][ii]++;
	}
	for(int ii = 0; ii < num_ranges; ii++)
	{
		int start, stop;
		fin >> start >> stop;
		start--;
		fout << cows[0][stop] - cows[0][start] << " ";
		fout << cows[1][stop] - cows[1][start] << " ";
		fout << cows[2][stop] - cows[2][start] << endl;
	}
}
