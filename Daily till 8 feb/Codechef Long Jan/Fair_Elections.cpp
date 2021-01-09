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

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //#ifndef ONLINE_JUDGE
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //#endif 
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        int *john= new int[n];
        int *jack= new int[m];
        int sumjohn=0;
        int sumjack=0;
        for(int i=0;i<n;i++) {
            cin>>john[i];
            sumjohn += john[i];
           // db1(sumjohn);
        }
        for(int i=0;i<m;i++){
          cin>>jack[i];  
          sumjack+= jack[i];
        } 

        sort(john,john+n);
        sort(jack,jack+m,greater<int>());
        int count=0;
        int jn=0,jk=0;
       // bool flag= false;
        //db2(sumjack,sumjohn);
        if(sumjohn > sumjack){
            cout<<0<<endl;
            continue;
        }
        // cout<<"printing jack"<<endl;
        // for(int i=0;i<m;i++){
        //     cout<<jack[i]<<" ";
        // }
        //cout<<endl;
        while(jn<n && jk <m && sumjohn <= sumjack){
           //TODO if(john[jn] < jack[jk])
            if(john[jn] < jack[jk]) 
            {   sumjohn = sumjohn-john[jn] +jack[jk];
                sumjack = sumjack- jack[jk] +john[jn];
                swap(john[jn],jack[jk]);
                sort(john,john+n);
                sort(jack,jack+m,greater<int>());
                //jn++; 
                count++;
                //db2(sumjohn,sumjack);
            }
            // else{
            //     // john[jn] >= jack[jk];

            //     jn++; 
            //     jk++;
            // }
            // // if(john[jn] > jack[jk]){
            // //     break;
            // // }
            // if(sumjohn > sumjack){
            //     flag =true;
            //     break;
            // }
            else break;
        }
        if(sumjohn > sumjack){
            cout<<count<<endl;
        }
        else {
            cout<<-1<<endl;
        }
        // if(flag){
        //     cout<<count<<endl;
        // }
        // else{
        //     cout<<-1<<endl;
        // }

    }
    return 0;
}