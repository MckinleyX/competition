/* 
ID: mckinle2
TASK: transform
LANG: C++
 */
#include <iostream>
#include <fstream>
using namespace std;

void rot(bool*& pattern, int size)
{
	bool *output = new bool[size*size];
	for(int ii = 0; ii < size; ii++)
	{
		for(int jj = 0; jj < size; jj++)
		{
			output[size*ii + jj] = pattern[size*(size - jj - 1) + ii];
		}
	}
	delete[] pattern;
	pattern = output;
	return;
}

void refl(bool*& pattern, int size)
{
	bool *output = new bool[size*size];
	for(int ii = 0; ii < size; ii++)
	{
		for(int jj = 0; jj < size; jj++)
		{
			output[size*(ii+1) - jj - 1] = pattern[size*ii + jj];
		}
	}
	delete[] pattern;
	pattern = output;
	return;
}

bool check(bool* pattern, bool* end, int size)
{
	bool result = true;
	for(int ii = 0; ii < size * size; ii++)
	{
		result &= (pattern[ii] == end[ii]);
	}
	return result;
}
		
void print(bool* pattern, int size)
{
	for(int ii = 0; ii < size; ii++)
	{
		for(int jj = 0; jj < size; jj++)
		{
			if(pattern[ii*size + jj])
				cout << '@';	
			else
				cout << '-';
		}
		cout << '\n';
	}
	cout << '\n';
}

int main()
{
	ifstream fin("transform.in");
	ofstream fout("transform.out");
	int size;
	fin >> size;
	int total_size = size * size;
	bool* pattern = new bool[total_size];
	bool* end = new bool[total_size];
	char input;
	for(int ii = 0; ii < total_size; ii++)
	{
		fin >> input;
		if(input == '@')
			pattern[ii] = true;
		else if(input == '-')
			pattern[ii] = false;
	}
	for(int ii = 0; ii < total_size; ii++)
	{
		fin >> input;
		if(input == '@')
			end[ii] = true;
		else if(input == '-')
			end[ii] = false;
	}
	print(pattern, size);
	for(int ii = 1; ii < 4; ii++)
	{
		rot(pattern, size);
		print(pattern, size);
		if(check(pattern, end, size))
		{
			fout << ii << endl;
			return 0;
		}
	}
	rot(pattern, size);
	refl(pattern, size);
	if(check(pattern, end, size))
	{
		fout << 4 << endl;
		return 0;
	}
	for(int ii = 0; ii < 3; ii++)
	{
		rot(pattern, size);
		if(check(pattern, end, size))
		{
			fout << 5 << endl;
			return 0;
		}
	}
	rot(pattern, size);
	refl(pattern, size);
	if(check(pattern, end, size))
		fout << 6 << endl;
	else
		fout << 7 << endl;

	return 0;

}

