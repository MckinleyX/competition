#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("censor.in", "r",stdin);
	freopen("censor.out", "w",stdout);
	ofstream fout("censor.out");
	string s,t;
	cin >> s;
	cin >> t;
	string r;
	for(unsigned int ii = 0; ii < s.size(); ii++)
	{
		r += s[ii];
		if(r.size() > t.size() && r.substr(r.size() - t.size()) == t)
			r.resize(r.size() - t.size());
	}
	cout << r;
	return 0;
}
