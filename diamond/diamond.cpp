#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ran = pair<ll,ll>;
int main()
{
	int n,k;
	freopen("diamond.in","r",stdin);
	freopen("diamond.out","w",stdout);
	cin >> n >> k;
	int* diam = new int[n];
	for(int ii = 0; ii < n; ii++)
	{
		cin >> diam[ii];
	}
	sort(diam,diam+n);
	int bl=0,br=0;//"b"est
	int l=0,r=0;
	while(r<n)
	{
		if(diam[r]-diam[l] > k)
			l++;
		else
		{
			if(r - l > br - bl)
			{
				br = r;
				bl = l;
			}
			r++;
		}
	}
	int best = 0;
	r = l = bl;
	while(l > 0 && diam[l] + k >= diam[r])
		l--;
	if(diam[l]+k < diam[r])
		l++;
	vector<ran> ga;//"g"reedy adjacent
	ga.reserve(2*(br - bl));
	ga.push_back(make_pair(l,r));
	while(l < br && r < n)
	{
		if(diam[r]-diam[l] > k)
			l++;
		else 
		{
			if((l <= bl || r >= br) && diam[r+1]-diam[l] > k)
				ga.push_back(make_pair(l,r));
			r++;
		}

	}
	//int sl,sr;//"s"econd best
	//sl = sr = -1;
	for(int ii = 0; ii < (int)ga.size(); ii++)
	{
		int gl = ga[ii].first;
		int gr = ga[ii].second;
		l=0,r=0;
		while(r<n)
		{
			if(r == gl)
			{
				l = gr+1;
				r = gr+1;
			}
			if(diam[r]-diam[l] > k)
				l++;
			else
			{
				if(gr-gl + r-l +2 > best)
				{
					best = gr-gl + r-l + 2;
				}
				r++;
			}
		}
	}
	cout << best << '\n';
}
