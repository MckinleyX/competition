#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
	cin.tie(0) -> sync_with_stdio(0);
	int num_courses, num_requirements;
	cin >> num_courses >> num_requirements;
	vector<vector<int>> graph(num_courses);
	vector<int> num_req(num_courses);
	for(int ii = 0; ii < num_requirements; ii++)
	{
		int a,b;
		cin >> a >> b;
		a--;
		b--;
		graph[a].push_back(b);
		num_req[b]++;
	}
	vector<int> courses;
	bool cycle = false;
	while(!cycle)
	{
		cycle = true;
		for(int ii = 0; ii < num_courses; ii++)
		{
			if(num_req[ii] == 0)
			{
				courses.push_back(ii+1);
				cycle = false;
				for(int ind : graph[ii])
					num_req[ind]--;
				num_req[ii] = -1;
			}
		}
		for(int ii = num_courses - 1; ii >= 0; ii--)
		{
			if(num_req[ii] == 0)
			{
				courses.push_back(ii+1);
				cycle = false;
				for(int ind : graph[ii])
					num_req[ind]--;
				num_req[ii] = -1;
			}
		}
	}
	if(courses.size() < num_courses)
	{
		int start = 0;
		while(num_req[start] < 1)
			start++;
		//TODO
	}
	else
		cout << "IMPOSSIBLE";
	cout << endl;
}
