// Created by Yadav_Gaurav
#include <bits/stdc++.h>

#define db1(x) cout<<#x<<"="<<x<<'\n'
#define db2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<'\n'
#define db3(x,y,z) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<","<<#z<<"="<<z<<'\n'
#define rep(i,n) for(int i=0;i<(n);++i)
#define repA(i,a,n) for(int i=a;i<=(n);++i)
#define repD(i,a,n) for(int i=a;i>=(n);--i)
#define mod 1000000007
#define max 750000

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
 		//int* input= new int[n];
 		int* ans= new int[max];
 		for(int i=0;i<max;i++) ans[i]=0;

 		for(int i=0;i<n;i++) {
 			int x; cin>>x;
 			ans[x]++;
 		}

 		for(int i=1;i<max;i++){
 			if(ans[i] > 0){
 				// go to its multiples
 				for(int j=2*i;j<max;j+=i){
 					if(ans[j] > 0){
 						ans[j] = (ans[i]%mod + ans[j]%mod)%mod;
 					}


 				}
			}
		}

        ll sum=0;
        for(int i=0;i<max;i++){
        	if(ans[i]>0){
        		sum = (sum%mod + ans[i]%mod) %mod;
        	}
        }
    	cout<<sum;
        cout<<'\n';
    }
    return 0;
}