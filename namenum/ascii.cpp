#include <iostream>
using namespace std;
int main()
{
	/*
	for(char ii = 'A'; ii < 'Z'; ii++)
	{
		int id = (ii - 'A')/3 + 2;
		if(ii > 'Q')
			id--;
		if(ii != 'Q' && ii != 'Z')
		{
			cout << ii << ' ' << id << endl;
		}
	}
	*/
	for(int ii = 2; ii <= 9; ii++)
	{
		cout << ii;
		for(int jj = 0; jj < 3; jj++)
		{
			char output = 3*(ii - 2) + 'A' + jj;
			if(output >= 'Q')
				output++;
			cout << ' ' << output;
		}
		cout << endl;
	}
	return 0;
}
