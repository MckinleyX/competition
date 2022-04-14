#include <bits/stdc++.h>
using namespace std;
struct pers //person
{
	int num;
	int s;//start
	int e;//end
	int room;
};
using room = pair<int, int>;//end time, room number
bool cmps(pers &a, pers &b) { return a.s < b.s; }
bool cmpn(pers &a, pers &b) { return a.num < b.num; }

int main()
{
	cin.tie(0)->sync_with_stdio(0);
//	freopen("room.in","r",stdin);
	int n;
	cin >> n;
	vector<pers> people;
	priority_queue<room,vector<room>, greater<room>> rooms;
	people.resize(n);
	//set<cust,decltype(&cmpe)> rooms(cmpe);
	//set<int> available;
	for(int ii = 0; ii < n; ii++)
	{
		int arr,dep;
		cin >> arr >> dep;
		people[ii] = {ii, arr, dep, -1};
	}
	sort(people.begin(),people.end(),cmps);
	for(int ii = 0; ii < n; ii++)
	{
		if(rooms.empty() || rooms.top().first >= people[ii].s)
		{
			people[ii].room = rooms.size() + 1;
			rooms.push(make_pair(people[ii].e, people[ii].room));
		}
		else
		{
			people[ii].room = rooms.top().second;
			rooms.push(make_pair(people[ii].e, people[ii].room));
			rooms.pop();
		}
	}
	sort(people.begin(),people.end(),cmpn);
	cout << rooms.size() << '\n';
	for(int ii = 0; ii < n; ii++)
		cout << people[ii].room << " ";

}
