#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MAX = 1000000;
int main()
{
	cin.tie(0) -> sync_with_stdio(0);
	for(int ii = 1; ii < MAX; ii++)
		for(int jj = 0; jj < MAX; jj++)
			cout << ii*jj << ",";
}
