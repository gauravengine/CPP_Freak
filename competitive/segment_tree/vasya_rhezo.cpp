#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
struct warriors
{
	int a;
	int b;
};
struct tree_attributes
{
	int a;
	int b;
	int index;
};
void make_tree(warriors* arr, tree_attributes* tree, int start, int end, int treenode)
{
	if (start == end)
	{
		tree[treenode].a = arr[start].a;
		tree[treenode].b = arr[start].b;
		tree[treenode].index = start;
		return;
	}
	int mid = (start + end) / 2;
	make_tree(arr, tree, start, mid, 2 * treenode);
	make_tree(arr, tree, mid + 1, end, 2 * treenode + 1);
	tree_attributes left_child = tree[2 * treenode];
	tree_attributes right_child = tree[2 * treenode + 1];
	if (left_child.a > right_child.a)
	{
		tree[treenode].a = left_child.a;
		tree[treenode].b = left_child.b;
		tree[treenode].index = left_child.index;
	}
	else if(left_child.a < right_child.a)
	{
		tree[treenode].a = right_child.a;
		tree[treenode].b = right_child.b;
		tree[treenode].index = right_child.index;
	}
	else
	{
		if (left_child.b < right_child.b)
		{
			tree[treenode].a = left_child.a;
			tree[treenode].b = left_child.b;
			tree[treenode].index = left_child.index;
		}
		else if (left_child.b > right_child.b)
		{
			tree[treenode].a = right_child.a;
			tree[treenode].b = right_child.b;
			tree[treenode].index = right_child.index;
		}
		else
		{
			if (left_child.index < right_child.index)
			{
				tree[treenode].a = left_child.a;
				tree[treenode].b = left_child.b;
				tree[treenode].index = left_child.index;
			}
			else
			{
				tree[treenode].a = right_child.a;
				tree[treenode].b = right_child.b;
				tree[treenode].index = right_child.index;
			}
		}
	}
}
tree_attributes question(tree_attributes* tree, int start, int end, int treenode, int left, int right)
{
	
	if (start > right || end < left)
	{
		tree_attributes ans;
		ans.a = INT_MIN;
		ans.b = INT_MAX;
		ans.index = INT_MAX;
		return ans;
	}
	
	if (start >= left && end <= right)
	{
		return tree[treenode];
	}
	
	int mid = (start + end) / 2;
	tree_attributes left_child = question(tree, start, mid, 2 * treenode, left, right);
	tree_attributes right_child = question(tree, mid + 1, end, 2 * treenode + 1, left, right);
	if (left_child.a > right_child.a)
	{
		return left_child;
	}
	else if (left_child.a < right_child.a)
	{
		return right_child;
	}
	else
	{
		if (left_child.b < right_child.b)
		{
			return left_child;
		}
		else if (left_child.b > right_child.b)
		{
			return right_child;
		}
		else
		{
			if (left_child.index < right_child.index)
			{
				return left_child;
			}
			else
			{
				return right_child;
			}
		}
	}
}
int main()
{
	int n;
	cin >> n;
	warriors* arr = new warriors[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i].a;
	}
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i].b;
	}
	tree_attributes* tree = new tree_attributes[4 * n]();
	make_tree(arr, tree, 0, n - 1, 1);
	int q;
	cin >> q;
	while (q--)
	{
		int left, right;
		cin >> left >> right;
		cout << question(tree, 0, n - 1, 1, left - 1, right - 1).index+1 << endl;
        
	}
}