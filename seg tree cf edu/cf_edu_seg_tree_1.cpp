#include<bits/stdc++.h>
using namespace std;
#define int             long long
struct segtree
{
	int size;
	vector<long long> sums;
	void init(int n){
		size=1;
		while(size<n) size*=2;
		sums.assign(2*size,0LL);
	}
	void build(vector<int> &a,int x,int lx,int rx){
		if(rx-lx==1){
			if(lx<(int)a.size()) sums[x]=a[lx];
			return;
		}
		int mid=(lx+rx)/2;
		build(a,2*x+1,lx,mid);
		build(a,2*x+2,mid,rx);

		sums[x]=sums[2*x+1]+sums[2*x+2];
	}
	void build(vector<int> &a){
		build(a,0,0,size);
	}
	void set(int i,int v,int x,int lx,int rx){
		if(rx-lx==1) {
			sums[x]=v;
			return;
		}
		int mid=(rx+lx)/2;
		if(i>=mid){
			//right
			set(i,v,2*x+2,mid,rx);
		}
		else{
			set(i,v,2*x+1,lx,mid);
		}
		sums[x]=sums[2*x+1]+sums[2*x+2];
	}
	void set(int i,int v){
		set(i,v,0,0,size);
	}
	int sum(int l,int r,int x,int lx,int rx){
		if(lx>=r || l>=rx ) return 0;
		if(lx>=l && rx<=r) return sums[x];
		int mid=(lx+rx)/2;

		long long sum1=sum(l,r,2*x+1,lx,mid);
		long long sum2=sum(l,r,2*x+2,mid,rx);

		return sum1+sum2;
	}

	int sum(int l,int r){
		return sum(l,r,0,0,size);
	}
};

int32_t main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,m;
	cin>>n>>m;

	segtree st;
	st.init(n);
	vector<int> a(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	st.build(a);
	while(m--){
		int op;
		cin>>op;
		if(op==1){
			int i,v;
			cin>>i>>v;

			st.set(i,v);
		}
		else{
			int l,r;
			cin>>l>>r;
			int ans=st.sum(l,r);
			cout<<ans<<'\n';
		}
	}
}