/* 
ID: mckinle2
TASK: milk2
LANG: C++
 */
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
class shift
{
	public:
	unsigned int start;
	unsigned int end;
};
void swap(shift& a, shift& b)
{
	shift t = a;
	a = b;
	b = t;
}
int partition(shift* arr, int low, int high)
{
	unsigned int pivot = arr[high].start;
	int ii = low - 1;
	for(int jj = low; jj < high; jj++)
	{
		if(arr[jj].start < pivot)
		{
			ii++;
			swap(arr[ii], arr[jj]);
		}
	}
	swap(arr[ii+1], arr[high]);
	return ii + 1;
}
void quicksort(shift* arr, int low, int high)
{
	if(low < high)
	{
		int pi = partition(arr, low, high);
		
		quicksort(arr, low, pi - 1);
		quicksort(arr, pi+1, high);
	}
}

int main()
{
	ifstream fin("milk2.in");
	ofstream fout("milk2.out");
	unsigned int farmers;
	fin >> farmers;
	shift* times = new shift[farmers];
	for(int ii = 0; ii < farmers; ii++)
	{
		fin >> times[ii].start;
		fin >> times[ii].end;
	}
	quicksort(times, 0, farmers - 1);
	for(int ii = 0; ii < farmers; ii++)
		cout << times[ii].start << endl;
	int maxTime = 0;
	int currentTime = 0;
	int maxIdle = 0;
	int currentIdle = 0;
	for(int ii = 0; ii < farmers; ii++)
	{
		currentTime = (times[ii].end - times[ii].start);
		while(ii < farmers - 1 && times[ii].end >= times[ii + 1].start)
		{
			times[ii+1].end = max(times[ii].end, times[ii+1].end);
			currentTime += (times[ii + 1].end - times[ii].end);
			ii++;
		}
		if(ii < farmers - 1)
			currentIdle = times[ii+1].start - times[ii].end;
		
		maxTime = max(currentTime, maxTime);
		maxIdle = max(currentIdle, maxIdle);
	}
	fout << maxTime << " " << maxIdle << endl;
	return 0;
}
