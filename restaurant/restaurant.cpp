//CSES REstaurant Customers
#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> change;
int main()
{
	int n;
	cin >> n;
	change* delta = new change[2*n];
	for(int ii = 0; ii < n; ii++)
	{
		change arr,dep;//Arrive and depart
		arr.second = 1;
		dep.second = -1;
		cin >> arr.first >> dep.first;
		delta[ii] = arr;
		delta[ii + n] = dep;
	}
	sort(delta, delta + 2*n);
	int num_people = 0;
	int max = 0;
	for(int ii = 0; ii < 2*n; ii++)
	{
		num_people += delta[ii].second;
		if(num_people > max)
			max = num_people;
	}
	cout << max << endl;
}
