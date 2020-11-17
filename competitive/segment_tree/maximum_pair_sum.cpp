#include<bits/stdc++.h>
using namespace std;

pair<int,int> quaery_ans(pair<int,int>* tree, int start, int end, int treeNode, int left, int right){
	
	//poora out matlab
	if (left>end || right<start)
	{
		pair<int,int> temp = make_pair(INT_MIN, INT_MIN);
		return temp;
	}

	//poora inside
	if (start>=left && end<=right)
	{
		return tree[treeNode];
	}

	//aadha inside XD
	int mid = (start+end)/2;

	pair<int,int> l = quaery_ans(tree, start, mid, 2*treeNode+1, left, right);
	pair<int,int> r = quaery_ans(tree, mid+1, end, 2*treeNode+2, left, right);


	pair<int,int> result;
	result.first = max(l.first,r.first);
    result.second = min(max(l.first,r.second),max(l.second,r.first));
   	return result;

}


void renew(int* arr, pair<int,int>* tree, int start, int end, int treeNode, int id, int value){
	int mid = (start+end)/2;

	if (start == end)
	{
		arr[id] = value;
		tree[treeNode] = make_pair(value, INT_MIN);
		return;
	}

	if (id<=mid)
	{
		renew(arr, tree, start, mid, 2*treeNode+1, id, value);
	}else{

		renew(arr, tree, mid+1, end, 2*treeNode+2, id, value);
	}

	pair<int,int> left = tree[2*treeNode+1];
	pair<int,int> right = tree[2*treeNode+2];

	tree[treeNode].first = max(left.first,right.first);
	tree[treeNode].second = min(max(left.first,right.second),max(left.second,right.first));
	return;
}


void build(int* arr, pair<int,int>* tree, int start, int end, int treeNode){
	if (end == start)
	{
		tree[treeNode] = make_pair(arr[start], INT_MIN);
		return;
	}

	int mid = (start+end)/2;

	build(arr, tree, start, mid, 2*treeNode+1);
	build(arr, tree, mid+1, end, 2*treeNode+2);

	pair<int, int> left = tree[2*treeNode+1];
	pair<int, int> right = tree[2*treeNode+2];

	tree[treeNode].first = max(left.first,right.first);
	tree[treeNode].second = min(max(left.first,right.second),max(left.second,right.first));
	
	return;

	
}

int main()
{
	int n, t;
	cin>>n;

	int* arr = new int[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>arr[i];
	}

	cin>>t;
	pair<int,int>* tree = new pair<int,int>[4*n];
	build(arr, tree, 0, n-1, 0);
	while(t--){
		char a;
		int b, c;
		cin>>a>>b>>c;

		if (a == 'Q')
		{
			pair<int,int> result = quaery_ans(tree, 0, n-1, 0, b-1, c-1);
			cout << result.first+result.second << endl;
		}else{
			renew(arr, tree, 0, n-1, 0, b-1, c);
		}

	}

	return 0 ; 
}