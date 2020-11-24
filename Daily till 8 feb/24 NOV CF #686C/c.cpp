// Created by yadav_gaurav
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
         int n; cin>>n;
         int arr[n+1]; arr[0]=0;
         unordered_map<int,int> m;
         for(int i=1;i<n+1;i++){
         	cin>>arr[i];
         	m[arr[i]]++;

         }
         if(m[arr[0]]==1 || m[arr[n]]==1){
         	cout<<1;
            //cout<<"here";
         }
         else{
         	//min ans is 2;
         	int min=INT_MAX;
         	int element=arr[0];
         	for(auto i:m){
                //db2(i.first,i.second);
         		if(i.second < min && i.first!=0) {min= i.second; element= i.first; }
         	}
         	//need to find contiguous block of element
            //db2(min,element);
         	for(int i=1;i<=n;i++){
         		if(arr[i]== element){
         			int contiguous=0;
         			for(int j=i+1;j<=n;j++){
         				
         				if(arr[j]== element) contiguous++;
                        else break;
         			}
         			min -= contiguous;
         		}
         	}
         	// choose bw m[arr[0]] and min+1;
            int ans1= m[arr[1]];
            if(arr[1]== arr[n]) ans1-=1;
            for(int i=2;i<=n;i++){
                if(arr[i]== arr[1]){
                    int contiguous=0;
                    for(int j=i+1;j<=n;j++){
                        
                        if(arr[j]== element) contiguous++;
                        else break;
                    }
                    ans1 -= contiguous;
                }
            }
            if(m[arr[1]]== n) cout<<0;
            else if(ans1 <= min+1 ) cout<<ans1;
            else cout<<min+1;

         }

        cout<<'\n';
    }
    return 0;
}