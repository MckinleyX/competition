//CSES: Tasks and deadlines
#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> task;
int main()
{
	long long n,ans=0,time=0;
	cin >> n;
	task* tasks = new task[n];
	for(int ii = 0; ii < n; ii++)
	{
		cin >> tasks[ii].first >> tasks[ii].second;
	}
	sort(tasks,tasks+n);
	for(int ii = 0; ii < n; ii++)
	{
		time += tasks[ii].first;
		ans += tasks[ii].second - time;
	}
	cout << ans << endl;
}
