//CSES: Labyrinth
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define f first
#define s second
const int MAX = 1001;
bool maze[MAX][MAX];
int path[MAX][MAX];
using pi = pair<int,int>;
pi moves[] = {{1,0},{0,1},{-1,0},{0,-1}};
char dirs[] = {'U','L','D','R'};//oops
bool is_valid(pi p, int n, int m)
{
	return p.f >= 0 && p.f < n && p.s >= 0 && p.s < m;
}
int main()
{
	cin.tie(0) -> sync_with_stdio(0);
	queue<pi> q;
	pi start, end;
	int m,n;
	cin >> n >> m;
	for(int ii = 0; ii < n; ii++)
	{
		for(int jj = 0; jj < m; jj++)
		{
			char c;
			cin >> c;
			maze[ii][jj] = !(c == '#');
			if(c == 'A')
				start = make_pair(ii,jj);
			else if(c == 'B')
				end = make_pair(ii,jj);
			path[ii][jj] = 'N';//None
		}
	}
	q.push(end);
	while(!q.empty())
	{
		pi c = q.front();
		if(c == start)
			break;
		q.pop();
		for(int ii = 0; ii < 4; ii++)
		{
			pi next = make_pair(c.f + moves[ii].f,c.s + moves[ii].s);
			if(is_valid(next,n,m) && maze[next.f][next.s] 
					&& path[next.f][next.s] == 'N')
			{
				path[next.f][next.s] = ii;
				q.push(next);
			}
		}
	}
	if(q.empty())
	{
		cout << "NO" << '\n';
	}
	else
	{
		cout << "YES" << '\n';
		int cost = 0;
		string ans = "";
		pi p = start;
		while(p != end)
		{
			cost++;
			pi mv = moves[path[p.f][p.s]];
			p.f -= mv.f;
			p.s -= mv.s;
		}
		cout << cost << '\n';
		p = start;
		while(p != end)
		{
			cost++;
			pi mv = moves[path[p.f][p.s]];
			cout << dirs[path[p.f][p.s]];
			p.f -= mv.f;
			p.s -= mv.s;
		}
		cout << '\n';
	}
}
