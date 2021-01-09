#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>


#define db1(x) cout<<#x<<"="<<x<<'\n'
#define db2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<'\n'
#define db3(x,y,z) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<","<<#z<<"="<<z<<'\n'
#define endl            '\n'
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

void lps(string t, int m , int *lpsarr){
    int j=0,i=1;
    lpsarr[0]=0;
    while(i<m){
        if(t[i]== t[j]){
            lpsarr[i]=j+1;
            j+=1;
            i+=1;
        }
        else{
            if(j!=0){
                j=lpsarr[j-1];
            }
            else{
            lpsarr[i]=0;
            i+=1;
            }
        }
    }
}

int kmpSearch(string s, string t, int n, int m , int *lpsarr){
    // int i=0,j=0;
    // while(i<n){
    //     if(s[i]==t[j]){
    //         i++;
    //         j++;
    //     }
    //     else if(i<n && s[i]!=t[j]){
    //         if(j!=0){
                
    //             j= lpsarr[j-1];
    //         }
    //         else{
    //             i++;
    //         }
    //     }
    //     if(j==m){
    //         return i-j;
    //     }
    // }
    // return -1;
    int i=0,j=0;
    while(i<n){
        if(s[i]==t[j]){
            i++;
            j++;
        }
        else{
            if(j==0){
                i++;
            }
            else{
                j=lpsarr[j-1];
            }
        }
        if(j==m){
            return i-j;
        }
    }

    return -1;
}

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //#ifndef ONLINE_JUDGE
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //#endif 
    string s,t; cin>>s>>t;
    int n= s.length();
    int m = t.length();
    int *lpsarr= new int[m];
    for(int i=0;i<m;i++) lpsarr[i]=0;
    lps(t,m,lpsarr);
    // for(int i=0;i<m;i++){
    //     cout<<lpsarr[i]<<" ";
    // }
    // cout<<endl;
    int ans=kmpSearch(s,t,n,m,lpsarr);
    cout<<ans;
    return 0;
}

// void lps(string t, int m , int*lpsarr){
//     int j=0;
//     int i=1;
//     lpsarr[0]=0;
//     while(i<m){
//         if(t[i]==t[j]){
//             lpsarr[i]=j+1;
//             i++;
//             j++;
//         }
//         else{
//             if(j==0){
//                 lpsarr[i]=0;
//                 i+=1;
//                 continue;
//             }
//             j=lpsarr[j-1];
//         }
//     }
// }

