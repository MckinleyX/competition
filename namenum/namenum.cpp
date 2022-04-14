/* 
ID: mckinle2
TASK: namenum
LANG: C++
 */
#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
	ifstream fin("namenum.in");
	ifstream din("dict.txt");
	ofstream fout("namenum.out");
	unsigned long long number;
	fin >> number;
	fin.close();
	bool found = false;
	string name_num = to_string(number);
	char f_char_max = 3*(name_num[0] - '0' - 2) + 'A' + 2;
	string input;
	do
	{
		bool word_works = true;
		din >> input;
		if(input.size() == name_num.size())
		{
			for(int ii = 0; ii < input.size(); ii++)
			{
				char char_min = 3*(name_num[ii] - '0' - 2) + 'A';
				char char_max = 3*(name_num[ii] - '0' - 2) + 'A' + 2;
				if(char_min >= 'Q')
					char_min++;
				if(char_max >= 'Q')
					char_max++;

				if(input[ii] < char_min || input[ii] > char_max)
				{
					word_works = false;
					break;
				}
			}
			if(word_works)
			{
				found = true;
				fout << input << endl;
			}
		}
	}while(input[0] <= f_char_max);
	if(!found)
		fout << "NONE" << endl;
	return 0;
}
