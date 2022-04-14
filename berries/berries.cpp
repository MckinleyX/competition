#include <bits/stdc++.h>
using namespace std;
int main()
{
	ifstream fin("berries.in");
	ofstream fout("berries.out");
	int num_t, num_b;
	fin >> num_t >> num_b;
	multiset<int> elsie;
	multiset<int> bessie;
	for(int ii = 0; ii < num_t; ii++)
	{
		int num;
		fin >> num;
		elsie.insert(num);
	}
	while((int)elsie.size() < num_b)
		elsie.insert(0);
	while((int)elsie.size() > num_b)
		elsie.erase(elsie.begin());

	auto it = elsie.begin();
	for(int ii = 0; ii < num_b/2; ii++)
	{
		bessie.insert(*it);
		it = elsie.erase(it);
	}
	
	int delta = 0;
	//The change in Bessies sum as a result of splitting 
	//the largest term
	
	int e_max = *elsie.rbegin();
	if(e_max > 2**bessie.rbegin())
		delta = *elsie.begin() - *bessie.begin();
	else
		delta = e_max
			- (*bessie.begin() + *bessie.rbegin());
	while(delta >= 0)
	{
		elsie.erase(--elsie.end());
		if(e_max > 2**bessie.rbegin())
		{
			//Split e_max
			elsie.insert(e_max/2);
			elsie.insert(e_max - e_max/2);

			//Shift one down
			bessie.insert(*elsie.begin());
			elsie.erase(elsie.begin());
			bessie.erase(bessie.begin());
		}
		else
		{
			//Split e_max
			bessie.insert(e_max/2);
			bessie.insert(e_max - e_max/2);
			
			//Shift one up
			elsie.insert(*bessie.rbegin());
			bessie.erase(--bessie.end());
			bessie.erase(bessie.begin());
		}
		e_max = *elsie.rbegin();
		if(e_max > 2**bessie.rbegin())
			delta = *elsie.rbegin()/2 - *bessie.begin();
		else
			delta = *elsie.rbegin() 
				- (*bessie.begin() + *bessie.rbegin());
	}

	int ans = 0;
	for(auto it = bessie.begin(); it != bessie.end(); it++)
	{
		ans += *it;
	}
	fout << ans << endl;
}
