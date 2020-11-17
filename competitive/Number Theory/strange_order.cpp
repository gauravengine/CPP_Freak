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
    ll n;
    cin>>n;
    bool *arr= new bool[n+1]();

    ll* lpd = new ll[n+1];    // lowest prime divisor
    for(ll i=0;i<=n;i++){
    	lpd[i]=i;
    }

    for(ll i=2;i<=n;i++){
    	if(lpd[i] ==i){
    		for(ll j=2*i;j<=n;j+=i){
    			lpd[j] = i;
    		}
    	}
    }
   // initialised lpd of all
   // let the coding begin
    for(ll i=n; i>=2; i--) {
    	if(!arr[i]){
    		
    		ll x,y=i;
    		arr[i]=true;
    		int xlpd= lpd[i];
    		//db2(i,xlpd);
    		vector<int> temp;
    		temp.push_back(i);
    		
    		while(xlpd!=1){
    			x=i;
    			while(x-xlpd !=0){
    				x=x-xlpd;
    				if(!arr[x])temp.push_back(x);
                    arr[x]= true;
    			}
    			while(y%xlpd == 0){
    				y=y/xlpd;
    			}

    			xlpd= lpd[y];


    		}
    		sort(temp.begin(),temp.end(),greater<int>());
    		for(ll i=0; i<temp.size(); i++) {
    			cout<<temp[i]<<" ";
    		}


    	}
    }


   cout<<1<<" ";



    return 0;
}