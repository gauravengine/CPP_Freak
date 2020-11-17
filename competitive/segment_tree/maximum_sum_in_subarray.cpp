#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
struct attributes {
	int max_sum;
	int sum;
	int best_prefix_sum;
	int best_suffix_sum;
};
void make_tree(int* arr, attributes* tree, int start, int end, int treenode)
{
	if (start == end)
	{
		tree[treenode].sum = arr[start];
		tree[treenode].max_sum = arr[start];
		tree[treenode].best_suffix_sum = arr[start];
		tree[treenode].best_prefix_sum = arr[start];
		return ;
	}
	int mid = (start + end) / 2;
	make_tree(arr, tree, start, mid, 2 * treenode);
	make_tree(arr, tree, mid + 1, end, 2 * treenode + 1);
	tree[treenode].sum = tree[2 * treenode].sum + tree[2 * treenode + 1].sum;
	tree[treenode].best_prefix_sum = max(tree[2 * treenode].best_prefix_sum, tree[2 * treenode].sum + tree[2 * treenode + 1].best_prefix_sum);
	tree[treenode].best_suffix_sum = max(tree[2 * treenode + 1].best_suffix_sum, tree[2 * treenode + 1].sum + tree[2 * treenode].best_suffix_sum);
	tree[treenode].max_sum = max
	(
		tree[2 * treenode].max_sum,
		max
		(
			tree[2 * treenode + 1].max_sum,
			max
			(
				tree[2 * treenode].sum + tree[2 * treenode + 1].best_prefix_sum,
				max
				(
					tree[2 * treenode + 1].sum + tree[2 * treenode].best_suffix_sum,
					tree[2 * treenode].best_suffix_sum + tree[2 * treenode + 1].best_prefix_sum
				)
			)
		)
	);
}
attributes query(attributes* tree, int start, int end, int treenode, int left, int right)
{
	
	if (start > right || end < left)
	{
		return {-100000, -100000, -100000, -100000};
	}
	if (start >= left && end <= right)
	{
		return tree[treenode];
	}
	int mid = (start + end) / 2;
	attributes q1 = query(tree, start, mid, 2 * treenode, left, right);
	attributes q2 = query(tree, mid + 1, end, 2 * treenode + 1, left, right);
	attributes ans;
	ans.sum = q1.sum + q2.sum;
	ans.best_prefix_sum = max(q1.best_prefix_sum, q1.sum + q2.best_prefix_sum);
	ans.best_suffix_sum = max(q1.best_suffix_sum + q2.sum, q2.best_suffix_sum);
	ans.max_sum = max
	(
		q1.max_sum,
		max
		(
			q2.max_sum,
			max
			(
				q1.sum + q2.best_prefix_sum,
				max
				(
					q2.sum + q1.best_suffix_sum,
					q1.best_suffix_sum + q2.best_prefix_sum
				)
			)
		)
	);
	return ans;
}
int main()
{
	int n;
	cin >> n;
	int* arr = new int[n];
	attributes* tree = new attributes[4 * n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	make_tree(arr, tree, 0, n - 1, 1);
	int t;
	cin >> t;
	while (t--)
	{
		int x, y;
		cin >> x >> y;
		cout << query(tree, 0, n - 1, 1, x-1, y-1).max_sum << endl;
	}
	return 0;
}