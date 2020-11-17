#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define endl "\n"
#define mod 1000000009
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin>>t;
  while(t--){
  	int n;
  	cin>>n;
  	int *arr= new int[n];
  	for(int i=0;i<n;i++) cin>>arr[i] ;
  	int count_5=0,count_10=0;
  	bool flag=true;
  	for(int i=0;i<n;i++){
  		if(arr[i]==5){
  			count_5++;
  		}
  		if(arr[i]==10){
  			count_5--;
  			count_10++;
  			if(count_5<0) {
  				flag=false;
  				break;
  			}
  		}
  		if(arr[i]==15){
  			//count_5--;
  			count_10--;

  			if(count_10<0 || count_5<0){
  				//count_5++;
  				count_10++;
  				count_5= count_5-2;
  				if(count_5<0){
  					flag=false;
  					break;
  				}
  			}
  		}

  	}
  	
  		if(flag==true) cout<<"YES"<<endl;
  		else cout<<"NO"<<endl;

  }

return 0;
}