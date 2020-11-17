#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h> 

 
using namespace std;
 
typedef long long ll;




int main()
{
 
 ll t;
 cin >> t;
 while(t--) {
     int maximum= 4e6;
     int n; cin>>n;
     int* b= new int[n+1];
     for (int i = 1; i <= n; i++)
     {
         cin>>b[i];
     }
     int* a= new int[n+1];
     for(int i=0;i<=n;i++) a[i]=-1;
    // made new array a
    for(int i=1;i<=n;i++){
        if(a[i]==-1){
            if(b[i] == i ){
                a[i]= maximum;
                maximum= maximum-2;
            }
            else{
                if(a[b[i]] == -1){
                    a[b[i]]= maximum;
                    a[i]= maximum/2;  // do this only if a[b[i]] == -1
                    maximum=maximum-2;
                }
                else{
                    a[i]= a[b[i]]/2;                }

            }
        }
    }
     for(int i=1;i<=n;i++){
         cout<<a[i]<<" ";
     }
     cout<<"\n";
 }
 return 0;
}