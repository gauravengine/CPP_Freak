#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long  ll;
void update_add(ll* tree, ll* lazy, ll start, ll end, ll treenode, ll left, ll right, ll value)
{
	if (start > end)
	{
		return;
	}
	if (lazy[treenode] != 0)
	{
		tree[treenode] += (end - start + 1) * lazy[treenode];
		if (start != end)
		{
			lazy[2 * treenode] += lazy[treenode];
			lazy[2 * treenode + 1] += lazy[treenode];
		}
		lazy[treenode] = 0;
	}
	
	if (start > right || end < left)
	{
		return;
	}
	if (start >= left && end <= right)
	{
		tree[treenode] += (end - start + 1) * value;
		if (start != end)
		{
			lazy[2 * treenode] += value;
			lazy[2 * treenode + 1] += value;
		}
		return;
	}
	
	ll mid = (start + end) / 2;
	update_add(tree, lazy, start, mid, 2 * treenode, left, right, value);
	update_add(tree, lazy, mid + 1, end, 2 * treenode + 1, left, right, value);
	tree[treenode] = tree[2 * treenode] + tree[2 * treenode + 1];
	return;
}
ll quesr_add(ll* tree, ll* lazy, ll start, ll end, ll treenode, ll left, ll right)
{
	if (start > end)
	{
		return 0;
	}
	if (lazy[treenode] != 0)
	{
		tree[treenode] += (end - start + 1) * lazy[treenode];
		if (start != end)
		{
			lazy[2 * treenode] += lazy[treenode];
			lazy[2 * treenode + 1] += lazy[treenode];
		}
		lazy[treenode] = 0;
	}
	
	if (start > right || end < left)
	{
		return 0;
	}
	
	if (start >= left && end <= right)
	{
		return tree[treenode];
	}
	
	ll mid = (start + end) / 2;
	ll left_child = quesr_add(tree, lazy, start, mid, 2 * treenode, left, right);
	ll right_child = quesr_add(tree, lazy, mid + 1, end, 2 * treenode + 1, left, right);
	return left_child + right_child;
}
int main()
{
	ll t;
	cin >> t;
	while (t--)
	{
		ll n, c;
		cin >> n >> c;

		ll* tree = new ll[4 * n]();
		ll* lazy = new ll[4 * n]();
		while (c--)
		{
			ll command_type;
			cin >> command_type;
			if (command_type == 0)
			{
				ll left, right, value;
				cin >> left >> right >> value;
				update_add(tree, lazy, 0, n - 1, 1, left - 1, right - 1, value);
			}
			else
			{
				ll left, right;
				cin >> left >> right;
				cout << quesr_add(tree, lazy, 0, n - 1, 1, left - 1, right - 1) << endl;
			}
		}
	}
}