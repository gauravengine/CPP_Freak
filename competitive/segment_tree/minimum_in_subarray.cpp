#include<bits/stdc++.h>
using namespace std;
void Btree(int* arr, int* tree, int start, int end, int treenode)
{
	if (start == end)
	{
		tree[treenode] = arr[start];
		return;
	}
	int mid = (start + end) / 2;
	Btree(arr, tree, start, mid, 2 * treenode);
	Btree(arr, tree, mid + 1, end, 2 * treenode + 1);
	tree[treenode] = min(tree[2 * treenode] , tree[2 * treenode + 1]);
}
void Utree(int* arr, int* tree, int start, int end, int treenode, int index, int value)
{
	if (start == end)
	{
		arr[index] = value;
		tree[treenode] = value;
		return;
	}
	int mid = (start + end) / 2;
	if (index > mid) // right wala
	{
		Utree(arr, tree, mid + 1, end, 2 * treenode + 1, index, value);
	}
	else// it means left
	{
		Utree(arr, tree, start, mid, 2 * treenode, index, value);
	}
	tree[treenode] = min(tree[2 * treenode] , tree[2 * treenode + 1]);
}
int query(int* tree, int start, int end, int treenode, int left, int right)
{
	if(start>right || end <left)
	{
		return INT_MAX;
        
	}
    
    if(start>=left && end<=right)
    {
        return tree[treenode];
    }
	int mid=(start+end)/2;
	int ans1=query(tree, start, mid, 2*treenode, left, right);
	int ans2=query(tree, mid+1, end, 2*treenode+1, left, right);
	return min(ans1, ans2);
}
int main()
{
	int n, t;
	cin>>n>>t;
	int *arr=new int [n];
	for(int i=0; i<n; i++)
	{
		cin>>arr[i];
	}
	int *tree=new int [4*n];
	Btree(arr, tree, 0, n - 1, 1);
	
	while(t--)
	{
		char quearyT;
		cin>>quearyT;
		if(quearyT=='q')
		{
			int l, r;
			cin>>l>>r;
			cout<<query(tree, 0, n-1, 1, l-1, r-1)<<endl;
		}
		else
		{
			int x, y;
			cin>>x>>y;
			
			Utree(arr, tree, 0, n - 1, 1, x-1, y);
		}
	}
}