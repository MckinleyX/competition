/* 
ID: mckinle2
TASK: palsquare
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
	ifstream fin("palsquare.in");
	ofstream fout("palsquare.out");
	unsigned short base;
	fin >> base;
	for(int ii = 1; ii <= 300; ii++)
	{
		string square = c_base(ii * ii, base);
		if(palcheck(square))
			fout << reverse(c_base(ii, base)) << ' '<< square << endl;
	}
	return 0;
}
