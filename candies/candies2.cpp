#include <bits/stdc++.h>
//Now with comments!
using namespace std;
using ll = long long;
ll solve()
{
		int num_c;//Number of candies
		int num_q;//Number of queries
		cin >> num_c >> num_q;
		vector<int> candies;
		candies.reserve(num_c+1);
		for(int ii = 0; ii < num_c; ii++)
		{
			cin >> candies[ii];
		}

		//prefix sum
		//A1 - A2 + A3...
		vector<ll> p_sum; 
		p_sum.reserve(num_c+1);

		//sweetness sum
		//A1 - 2A2 + 3A3...
		vector<ll> s_sum; 
		s_sum.reserve(num_c+1);
		
		p_sum[0] = 0;
		s_sum[0] = 0;

		for(int ii = 1; ii <= num_c; ii++)
		{
			int sign = 1;
			if(ii % 2 == 0)
				sign = -1;
			//Calculating prefix (not suffix!) sums
			p_sum[ii] = p_sum[ii-1] + sign*candies[ii-1];
			s_sum[ii] = s_sum[ii-1] + sign*candies[ii-1]*ii;
		}

		ll ans = 0;
		for(int ii = 0; ii < num_q; ii++)
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

				//Truncate via prefix sums
				ans += sign*(s_sum[end] - s_sum[start-1]); 
				
				//Reduce, so that the first term starts at +1, instead of +(start)
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
				//Somehow it works though
				for(int jj = ind; jj <= num_c; jj++)
				{
					p_sum[jj] += sign*(val-old);
					s_sum[jj] += sign*(val-old)*(ind);
				}
			}
		}
		return ans;
}
int main()
{
	int num_t;//number of test cases
	cin >> num_t;
	for(int ii = 0; ii < num_t; ii++)
	{
		cout << "Case #";
		cout << ii+1;
		cout << ": "; 
		cout << solve() << "\n";
	}
}
