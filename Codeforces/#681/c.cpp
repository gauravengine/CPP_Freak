// Created by Yadav_Gaurav
#include <bits/stdc++.h>

#define db1(x) cout<<#x<<"="<<x<<'\n'
#define db2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<'\n'
#define db3(x,y,z) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<","<<#z<<"="<<z<<'\n'
#define rep(i,n) for(int i=0;i<(n);++i)
#define repA(i,a,n) for(int i=a;i<=(n);++i)
#define repD(i,a,n) for(int i=a;i>=(n);--i)
#define mod 1000000007

using namespace std;
using ll = long long;

ll solve(int * a,int* b, int n){
	// return the answer
	vector<pair<ll,int>> times;
	for(int i=0; i<n; i++) {
		times.push_back(make_pair(a[i],b[i]));
	}
	sort(times.begin(), times.end());
	ll sum=0;
	for(int i=0; i<n; i++) {
		sum+= times[i].second;
	}
	ll ans= sum;
	for(int i=0;i<n;i++){
		ans= min(ans,max(times[i].first,sum-times[i].second));
		sum= sum-times[i].second;
	}

	return ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
       	int n;
       	cin>>n;
       	int* a=new int[n];
       	int* b= new int[n];
       	for(int i=0; i<n; i++){
       		cin>>a[i];
       	}
       	for(int i=0; i<n; i++){
       		cin>>b[i];
       	}
       	cout<<solve(a,b,n);
    
        cout<<'\n';
    }
    return 0;
}