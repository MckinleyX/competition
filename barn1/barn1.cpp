/* 
ID: mckinle2
TASK: barn1
LANG: C++
 */
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int main()
{
	ifstream fin("barn1.in");
	ofstream fout("barn1.out");
	int num_boards, num_stalls, num_cows;
	fin >> num_boards >> num_stalls >> num_cows;
	int *stalls = new int[num_cows];
	for(int ii = 0; ii < num_cows; ii++)
	{
		fin >> stalls[ii];
	}
	sort(stalls, stalls + num_cows);
	int num_covered = stalls[num_cows - 1] - stalls[0] + 1;
	//fout << "1 board: " << num_covered << endl;
	int *distances = new int[num_stalls - 1];
	int max_dist = 0;
	for(int ii = 1; ii < num_cows; ii++)
	{
		distances[ii - 1] = stalls[ii] - stalls[ii - 1] - 1;//Number of empty stalls between two stalls
		//fout << distance << " empty stalls between " << stalls[ii - 1] << " and " << stalls[ii] << endl;
	}
	sort(distances, distances + num_stalls - 1);
	for(int ii = 1; ii < num_boards && ii < num_stalls - 1; ii++)
	{
		num_covered -= distances[num_stalls - 1 - ii];
	}
	fout << num_covered << endl;
}
