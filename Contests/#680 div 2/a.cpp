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
        int x; cin>>x;
       	int* a= new int[n];
		int* b= new int[n];
		for(int i=0; i<n; i++) {
			cin>>a[i];
		}        
    	for(int i=0; i<n; i++) {
			cin>>b[i];
		}
		bool flag= true;
		for(int i=0; i<n; i++) {
			if(a[i]+b[n-i-1] > x){
				flag= false;
			}
		}

		if(flag) cout<<"Yes";
		else cout<<"No";

        cout<<'\n';
    }
    return 0;
}