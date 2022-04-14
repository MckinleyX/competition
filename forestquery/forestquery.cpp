#include <bits/stdc++.h>
using namespace std;
int main()
{
	int size;
	int num_q;
	cin >> size >> num_q;
	size++;
	int* arr = new int[size*size];
	for(int ii = 1; ii < size; ii++)
	{
		for(int jj = 1; jj < size; jj++)
		{
			//ii is y, jj is x
			char tree;
			cin >> tree;
			arr[ii*size + jj] = arr[(ii-1)*size + jj]
				+ arr[ii*size + (jj-1)]
				- arr[(ii-1)*size+(jj-1)];
			if(tree == '*')
			{
				arr[ii*size + jj]++;
				//cout << ii << " " << jj << endl;
			}
		}
	}
	for(int ii = 0; ii < num_q; ii++)
	{
		int y1,x1,y2,x2;
		cin >> y1 >> x1 >> y2 >> x2;
		y1--;
		x1--;
		cout << arr[y2*size + x2] + arr[y1*size + x1]
			- arr[y2*size + x1] - arr[y1*size + x2] << endl;
	}
}
