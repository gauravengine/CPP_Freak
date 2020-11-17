#include<iostream>
#include<algorithm>
using namespace std;
struct tree_attrs
{
	int even;
	int odd;
};
void make_tree(int* arr, tree_attrs* tree, int start, int end, int treenode)
{
	if (start == end)
	{
		if (arr[start] % 2 == 0)
		{
			tree[treenode].even = 1;
			tree[treenode].odd = 0;
		}
		else
		{
			tree[treenode].odd = 1;
			tree[treenode].even = 0;
		}
		return;
	}
	int mid = (start + end) / 2;
	make_tree(arr, tree, start, mid, 2 * treenode);
	make_tree(arr, tree, mid+1, end, 2 * treenode+1);
	tree[treenode].odd = tree[2 * treenode].odd + tree[2 * treenode + 1].odd;
	tree[treenode].even = tree[2 * treenode].even + tree[2 * treenode + 1].even;
}
void modify(int *arr, tree_attrs* tree, int start, int end, int treenode, int index, int value)
{
	if (start == end)
	{
		arr[index] = value;
		if (value % 2 == 0)
		{
			tree[treenode].even = 1;
			tree[treenode].odd = 0;
		}
		else
		{
			tree[treenode].even = 0;
			tree[treenode].odd = 1;
		}
		return;
	}
	int mid = (start + end) / 2;
	if (index > mid)//right
	{
		modify(arr, tree, mid + 1, end, 2 * treenode + 1, index, value);
	}
	else//left
	{
		modify(arr, tree, start, mid, 2 * treenode, index, value);
	}
	tree[treenode].even = tree[2 * treenode].even + tree[2 * treenode + 1].even;
	tree[treenode].odd = tree[2 * treenode].odd + tree[2 * treenode + 1].odd;
}
tree_attrs query(tree_attrs* tree, int start, int end, int treenode, int left, int right)
{
	//completely outside
	if (start > right || end < left)
	{
		tree_attrs ans;
		ans.even = 0;
		ans.odd = 0;
		return ans;
	}
	//complete overlap
	if (start >= left && end <= right)
	{
		return tree[treenode];
	}
	//partial overlap
	int mid = (start + end) / 2;
	tree_attrs left_child = query(tree, start, mid, 2 * treenode, left, right);
	tree_attrs right_child = query(tree, mid + 1, end, 2 * treenode + 1, left, right);
	tree_attrs ans;
	ans.even = left_child.even + right_child.even;
	ans.odd = left_child.odd + right_child.odd;
	return ans;
}
int main()
{
	int n;
	cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	tree_attrs* tree = new tree_attrs[4 * n]();
	make_tree(arr, tree, 0, n - 1, 1);
	int t;
	cin >> t;
	while (t--)
	{
		int query_type;
		cin >> query_type;
		if (query_type == 0)
		{
			int index, value;
			cin >> index >> value;
			modify(arr, tree, 0, n - 1, 1, index-1, value);
		}
		else if (query_type == 1)
		{
			int left, right;
			cin >> left >> right;
			cout << query(tree, 0, n - 1, 1, left - 1, right - 1).even<<endl;
		}
		else
		{
			int left, right;
			cin >> left >> right;
			cout << query(tree, 0, n - 1, 1, left - 1, right - 1).odd<<endl;
		}
	}
}