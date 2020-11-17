#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")

#include <complex>
#include <queue>
#include <set>
#include <unordered_set>
#include <list>
#include <chrono>
#include <random>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <iomanip>
#include <fstream>
 
using namespace std;
 
typedef long long ll;

#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)


int solve(int n,int* c){
	sort(c,c+n);
	if(n==1){
		return c[0];
	}
	if(n==2){
		return max(c[0],c[1]);
	}
	if(n==3){
		// if(c[0]+c[1] <= c[2]) return c[2];
		
		// else{
		// 	return min(max(c[0]+c[1],c[2]),min(max(c[0]+c[2],c[1]),max(c[1]+c[2],c[0]) ) );
		// } 
		return max(c[0]+c[1],c[2]);
	}
	if(n==4){
		 if
		 	(c[0]+c[1]+c[2] <= c[3]) return  c[3];
		// else
		// 	return min( max((c[3]+c[0]),(c[2]+c[1])),min(max((c[3]+c[1]),(c[2]+c[0])) ,max((c[3]+c[2]),(c[1]+c[0])) ) );
		else
			return min( max(c[3]+c[1],c[2]+c[0]),min(max(c[3]+c[0],c[1]+c[2]),max(c[0]+c[1]+c[2],c[3])) );

	}
	return 0;
}
int main()
{
 fast_cin();
 ll t;
 cin >> t;
 while(t--) {
    int n; cin>>n;
    int* c= new int[n];
    for(int i=0; i<n; i++) {
    	cin>>c[i];
    }
    cout<<solve(n,c)<<"\n";
	
 }
 return 0;
}