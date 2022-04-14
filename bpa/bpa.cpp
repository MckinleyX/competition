// Contestant ID: 123456
// THIS TOOK 35 MINUTES TO CODE
#include <bits/stdc++.h>
using namespace std;
bool isPrime(int num);
bool isPerfect(int num);
void prettyPrint(vector<int> num);
static int* sieve;
int main()
{
	char again;
	do
	{
		cout << "Enter the number to count up to: ";
		int max;
		cin >> max;
		sieve = new int[max+1];
		//Memoization is far better than the suggested method
		//Since it runs in O(n) rather than O(n^2)
		for(int ii = 1; ii <= max; ii++)
		{
			for(int jj = ii+1; jj <= max; jj++)
			{
				if(jj % ii == 0)
					sieve[jj] += ii;
			}
		}
		vector<int> primes;
		vector<int> perfect;
		for(int ii = 2; ii <= max; ii++)
		{
			if(isPrime(ii))
				primes.push_back(ii);
			else if(isPerfect(ii))
				perfect.push_back(ii);
		}
		system("clear");
		prettyPrint(perfect);
		cout << "Press any key and then ENTER to continue";
		cin >> again;
		system("clear");
		prettyPrint(primes);
		cout << "Do you want to run this program again? ";
		cin >> again;
	}while((again == 'y') | (again == 'Y'));
}
bool isPrime(int num)
{
	//If the sum of factors not equal to num is equal to 1
	return sieve[num] == 1;
}
bool isPerfect(int num)
{
	//If the sum of factors not equal to num is equal to num
	return sieve[num] == num;
}
void prettyPrint(vector<int> nums)
{
	auto it = nums.begin();
	if(it != nums.end())
		cout << *it;
	it++;
	while(it != nums.end())
	{
		cout << ", " << *it;
		it++;
	}
	cout << endl;
	return;
}
