#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
	cin.tie(0) -> sync_with_stdio(0);
	freopen("feast.in","r",stdin);
	freopen("feast.out","w",stdout);
	int t,a,b;
	cin >> t >> a >> b;
	set<int> s1,s2;
	s1.insert(0);
	queue<int> q1,q2;
	q1.push(0);
	s1.insert(0);
	while(!q1.empty())
	{
		int next = q1.front();
		q1.pop();
		if(next + a <= t && s1.count(next+a) == 0)
		{
			q1.push(next+a);
			s1.insert(next+a);
		}
		if(next + b <= t && s1.count(next+b) == 0)
		{
			q1.push(next+b);
			s1.insert(next+b);
		}
		q2.push(next/2);
		s2.insert(next/2);
	}
	while(!q2.empty())
	{
		int next = q2.front();
		q2.pop();
		if(next + a <= t && s2.count(next+a) == 0)
		{
			q2.push(next+a);
			s2.insert(next+a);
		}
		if(next + b <= t && s2.count(next+b) == 0)
		{
			q2.push(next+b);
			s2.insert(next+b);
		}
	}
	cout << max(*s1.rbegin(),*s2.rbegin()) << '\n';
}
