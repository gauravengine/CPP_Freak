#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define endl "\n"
#define mod 1000000009
bool helper(int* arr ,int n,int count_5,int count_10){
	bool flag;
	//base conditions count_5 and count_10<10 flag=false
	if(n<=0){
		if(count_5>=0 && count_10>=0) {
			return true; 
		}
		else
			return false;
	}

	if((count_5<0 && count_10<0 ) ){
		//flag=false;
	 return false; 
	}
	for(int i=0;i<n;i++){
		if(arr[i]==5){
			count_5++;
			flag=helper(arr+1,n-1,count_5,count_10);
		}
		if(arr[i]==10){
			count_5--;
			count_10++;
			flag=helper(arr+1,n-1,count_5,count_10);
		}
		if(arr[i]==15){
			bool flag1=helper(arr+1,n-1,count_5,count_10--);
			bool flag2=helper(arr+1,n-1,count_5-2,count_10);
			if(flag1 || flag2 ) flag=true;
			else flag=false;
		}
	}
	return flag;

}
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
 	//bool flag=true;
 	if(helper(arr,n,count_5,count_10)) cout<<"YES"<<endl;
 	else cout<<"NO"<<endl;



  }

return 0;
}