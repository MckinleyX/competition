/* 
ID: mckinle2
TASK: dualpal
LANG: C++
 */
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
using namespace std;

string reverse(string str)
{
	for(int ii = 0; ii < str.size()/2; ii++)
	{
		swap(str[ii], str[str.size() - ii - 1]);
	}
	return str;
}
		
bool palcheck(string input)
{
	if(input.size() < 2)
		return true;
	return (input[0] == input[input.size() - 1]) && palcheck(input.substr(1, input.size() - 2));
}

string c_base(int input, int base)//reversed, but this is a palindrone anyway, so whatever
{
	string result;
	do
	{
		char next_char = input%base;
		if(next_char > 9)
			next_char += 'A' - 10;
		else
			next_char += '0';
		result += next_char;
		input /= base;
	}while(input != 0);
	return result;
}

int main()
{
	ifstream fin("dualpal.in");
	ofstream fout("dualpal.out");
	int num_nums;
	fin >> num_nums;
	int num;
	fin >> num;
	int counter = 0;
	while(counter < num_nums)
	{
		int num_pal = 0;
		num++;
		for(int ii = 2; ii <= 10; ii++)
		{
			if(palcheck(c_base(num, ii)))
				num_pal++;
		}
		if(num_pal > 1)
		{
			fout << num << endl;
			counter++;
		}
	}
	return 0;
}
