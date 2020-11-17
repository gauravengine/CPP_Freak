#include<bits/stdc++.h>
using namespace std;
int power[100001];

void Bpower(){
    power[0] = 0;
    power[0]++;
    for(int i = 1; i < 100001; i++) power[i] = (power[i-1]*2)%3;
}
void Btree(int* arr, int* tree, int start, int end, int treenode)
{
	if (start == end)
	{
		tree[treenode] = arr[start];
		return;
	}
	int mid = (start+end)/2;
	Btree(arr, tree, start, mid, 2 * treenode);
	Btree(arr, tree, mid + 1, end, 2 * treenode + 1);
	int right_child = tree[2 * treenode + 1];
	int left_child = tree[2 * treenode];
	tree[treenode] = (power[end-mid]*left_child + right_child)%3;
}

void renew_flip(int *arr, int* tree, int start, int end, int treenode, int index)
{
	if (start == end)
	{
		arr[index]=1;
        tree[treenode]=1;
        return;
    }
	int mid = (start + end) / 2;
	if (index > mid)
	{
		renew_flip(arr, tree, mid + 1, end, 2 * treenode + 1, index);
	}
	else
	{
		renew_flip(arr, tree, start, mid, 2 * treenode, index);
	}

	int right_child = tree[2 * treenode + 1];
	int left_child = tree[2 * treenode];
	tree[treenode] = (power[end-mid]*left_child + right_child)%3;
}

int quaery_v(int* tree, int start, int end, int treenode, int left, int right)
{
	
	if (start > right || end < left)
	{
		return 0;
	}

	if (start >= left && end <= right)
	{
		return (tree[treenode]*power[right-end])%3;
	}
	
	int mid = (start + end) / 2;
	int answer_from_left = quaery_v(tree, start, mid, 2 * treenode, left, right);
	int answer_from_right = quaery_v(tree, mid + 1, end, 2 * treenode + 1, left, right);
	return (answer_from_left+answer_from_right)%3;
}
int main()
{
    Bpower();
	int n;
	cin >> n;
	string s;
	cin >> s;
	int arr[n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = s[i]-'0';
	}
	int* tree = new int[4 * n]();
	Btree(arr, tree, 0, n - 1, 1);
	int t;
	cin >> t;
	while (t--)
	{
		int query_type;
		cin >> query_type;
		if (query_type == 0)
		{
			int left, right;
			cin >> left >> right;
			cout << quaery_v(tree, 0, n - 1, 1, left, right) << endl;;
		}
		else
		{
			int index;
			cin >> index;
            if(arr[index]==0)
			    renew_flip(arr, tree, 0, n - 1, 1, index);
		}
	}
	return 0;
}