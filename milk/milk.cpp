/* 
ID: mckinle2
TASK: milk
LANG: C++
 */
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
#define MAX_FARMERS 5000

struct milk
{
	unsigned long long units;
	unsigned long long cost;
};

bool comp_price(milk& lhs, milk& rhs){return lhs.cost < rhs.cost;}

int main()
{
	ifstream fin("milk.in");
	ofstream fout("milk.out");
	unsigned long long milk_needed;
	fin >> milk_needed;
	unsigned int num_farmers;
	fin >> num_farmers;
	unsigned long long total_pay = 0;
	milk* farmers = new milk[num_farmers];
	for(int ii = 0; ii < num_farmers; ii++)
	{
		fin >> farmers[ii].cost;
		fin >> farmers[ii].units;
	}
	sort(farmers, farmers + num_farmers, comp_price);
	int counter = 0;
	while(milk_needed > 0)
	{
		total_pay += farmers[counter].cost * min(farmers[counter].units, milk_needed);
		milk_needed -= min(milk_needed, farmers[counter].units);
		counter++;
	}
	fout << total_pay << endl;
	return 0;
}
		
		
