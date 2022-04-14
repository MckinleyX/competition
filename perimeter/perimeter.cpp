#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define MAX_N 1000
bool visited[MAX_N][MAX_N];
bool ice[MAX_N][MAX_N];
using blob = pair<int,int>;
using pos = pair<int,int>;
blob fill(int r, int c, int n)
{
	int area,perimeter;
	area = perimeter = 0;
	queue<pos> frontier;
	frontier.push(make_pair(r,c));
	while(frontier.size() != 0)
	{
		pos p = frontier.front();
		frontier.pop();
		if(max(p.first,p.second) >= n 
				|| min(p.first,p.second) < 0
				|| !ice[p.first][p.second])
			perimeter++;
		else if(!visited[p.first][p.second])
		{
			area++;
			visited[p.first][p.second]=true;
			frontier.push(make_pair(p.first+1,p.second));
			frontier.push(make_pair(p.first-1,p.second));
			frontier.push(make_pair(p.first,p.second+1));
			frontier.push(make_pair(p.first,p.second-1));
		}
		
	}
	return make_pair(area,perimeter);
}
int main()
{
	freopen("perimeter.in","r",stdin);
	freopen("perimeter.out","w",stdout);
	int n;
	cin >> n;
	for(int ii = 0; ii < n; ii++)
	{
		for(int jj = 0; jj < n; jj++)
		{
			char c;
			cin >> c;
			ice[ii][jj] = (c == '#');
		}
	}
	blob best = make_pair(0,0);
	for(int ii = 0; ii < n; ii++)
	{
		for(int jj = 0; jj < n; jj++)
		{
			if(!visited[ii][jj] && ice[ii][jj])
			{
				blob curr = fill(ii,jj,n);
				if(curr.first > best.first
						|| (curr.first == best.first
							&& curr.second < best.second))
					best = curr;
			}
		}
	}
	cout << best.first << " " << best.second << '\n';
}
