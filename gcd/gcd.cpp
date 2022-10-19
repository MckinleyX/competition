// CSES: Common Divisors
#include <iostream>
using namespace std;

const int MAX_VAL = 1e6;
int divisors[MAX_VAL+1];
int main()
{
	cin.tie(0) -> sync_with_stdio(0);
	int n;
	cin >> n;
	for(int ii = 0; ii < n; ii++)
	{
		int a;
		cin >> a;
		for(int jj = 1; jj*jj <= a; jj++)
		{
			if(a % jj == 0)
			{
				divisors[jj]++;
				if(jj*jj != a)
					divisors[a/jj]++;
			}
		}
	}
	for(int ii = MAX_VAL; ii >= 1; ii--)
	{
		if(divisors[ii] > 1)
		{
			cout << ii << '\n';
			return 0;
		}
	}
}
