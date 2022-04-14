#include <bits/stdc++.h>
using namespace std;
int main()
{
	//ifstream fin("candies.in");
	//ofstream fout("candies.out");
	int num_t;//number of test cases
	cin >> num_t;
	for(int ii = 0; ii < num_t; ii++)
	{
		int num_c;//Number of candies
		int num_q;//Number of queries
		cin >> num_c >> num_q;
		vector<int> candies;
		candies.reserve(num_c+1);
		for(int jj = 0; jj < num_c; jj++)
		{
			cin >> candies[jj];
		}
		vector<long long> p_sum;
		p_sum.reserve(num_c+1);
		//A1 - A2 + A3...
		vector<long long> s_sum;
		s_sum.reserve(num_c+1);
		//A1 - 2A2 + 3A3...
		p_sum[0] = 0;
		s_sum[0] = 0;
		for(int jj = 1; jj <= num_c; jj++)
		{
			int sign = 1;
			if(jj % 2 == 0)
				sign = -1;
			p_sum[jj] = p_sum[jj-1] + sign*candies[jj-1];
			s_sum[jj] = s_sum[jj-1] + sign*jj*candies[jj-1];
		}
		long long ans = 0;
		for(int jj = 0; jj < num_q; jj++)
		{
			char type;//'U' for update, 'Q' for query
			cin >> type;
			if(type == 'Q')
			{
				int start,end;
				cin >> start >> end;
				int sign = 1;
				if(start % 2 == 0)
					sign = -1;
				ans += sign*(s_sum[end] - s_sum[start-1]);
				ans -= sign*(start-1)*(p_sum[end] - p_sum[start-1]);
			}
			else if(type == 'U')
			{
				int ind,val;
				cin >> ind >> val;
				int old = candies[ind-1];
				candies[ind-1] = val;
				int sign = 1;
				if(ind % 2 == 0)
					sign = -1;
				//Can't think of an intelligent way to do this
				for(int kk = ind; kk <= num_c; kk++)
				{
					p_sum[kk] += sign*(val - old);
					s_sum[kk] += sign*(ind)*(val-old);
				}
			}
		}
		cout << "Case #";
		cout << ii+1;
		cout << ": "; 
		cout << ans << "\n";
	}
}
