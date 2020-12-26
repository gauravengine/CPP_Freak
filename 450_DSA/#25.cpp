#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>


#define db1(x) cout<<#x<<"="<<x<<'\n'
#define db2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<'\n'
#define db3(x,y,z) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<","<<#z<<"="<<z<<'\n'
#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)

 

#define mod 1000000007

using namespace std;
using ll = long long;

int qs(int *arr,int n){
    int i=-1;
    for(int j=0;j<n;j++){
        if(arr[j]<0){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    return i+1;

}
void rear(int *arr,int pos,int n){
    int temp=pos;
    for(int i=1;i<n ;i+=2,pos++){
        db2(i,pos);
        if(arr[i]<0 && pos<n)swap(arr[i],arr[pos]);
        else break;
        
    }
}
void print(int *arr,int n){
    for(int i=0;i<n;i++){
        
        cout<<arr[i]<<" ";
    }
}
int32_t main()
{
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
    int n; cin>>n;
    int *arr= new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int pos= qs(arr,n);
    print(arr,n);
    db1(pos);
    rear(arr,pos,n);
    print(arr,n);
    return 0;
}