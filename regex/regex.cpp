//USACO: Find & Replace (2023 Jan Gold)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define f first
#define s second

struct node
{
	char val;
	node *l, *r;
	ll size = 1;
	node()
	{
		val = '`';
		l = nullptr;
		r = nullptr;
	}
	node(char c)
	{
		val = c;
		l = nullptr;
		r = nullptr;
	}
	node(node* left, node* right)
	{
		val = '`';
		l = left;
		r = right;
		size = left->size + right->size;
	}
};
int i(char c)
{
	return c - 'a';
}

//from a string, generate a tree
node* g_tree(string s, node** lets,ll max_size)
{
	if(s.size() > 1)
	{
		node* l = g_tree(s.substr(0,s.size()/2),lets,max_size); 
		//cut off right side if left side is too big
		if(l->size >= max_size)
			return l;
		node* r = g_tree(s.substr(s.size()/2),lets,max_size);

		node* ret = new node(l,r);
		
		//overflow is bad
		assert(ret->size > l->size && ret->size > r->size);
		return ret;
	}
	return lets[i(s[0])];
}

//from tree and indices, give substring
string to_str(node* n, ll start, ll end)
{
	if(n->val == '`')
	{
		string result = "";
		ll l_size = n->l->size;
		if(start <= l_size)
			result += to_str(n->l,start,min(end,l_size));
		if(end > l_size)
			result += to_str(n->r,max(1ll,start - l_size),end - l_size);
		return result;
	}
	return string(1,n->val);
}
int main()
{
	cin.tie(0) -> sync_with_stdio(0);
	//freopen("regex.in","r",stdin);
	//freopen("regex.out","w",stdout);
	ll l,r,n;
	cin >> l >> r >> n;
	vector<pair<char,string>> ops(n);
	for(int ii = 0; ii < n; ii++)
	{
		char c;
		string s;
		cin >> c >> s;
		ops.push_back({c,s});
	}
	node* ls[26];
	for(int ii = 0; ii < 26; ii++)
		ls[ii] = new node('a'+ii);

	//replace operation
	for(int ii = ops.size() - 1; ii >= 0; ii--)
		ls[i(ops[ii].f)] = g_tree(ops[ii].s,ls,r);

	cout << to_str(ls[0],l,r);
	return 0;
}
