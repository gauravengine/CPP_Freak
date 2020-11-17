#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define endl "\n"
#define mod 1000000009
bool helper(int* arr ,int n,int count_5,int count_10){
	//cout<<"count_5 : "<<count_5<<endl;
	//cout<<"count_10 : "<<count_10<<endl;
	bool flag;
	//base conditions count_5 and count_10<10 flag=false
	if(n<=0){
		if(count_5<0 || count_10<0) {
			return false; 
		}
		else
			return true;
	}

	if((count_5<0 || count_10<0 ) ){
		//flag=false;
	 return false; 
	}
	
		if(arr[0]==5){
			//count_5++;
			flag=helper(arr+1,n-1,count_5+1,count_10);
		}
		if(arr[0]==10){
			//count_5--;
			//count_10++;
			flag=helper(arr+1,n-1,count_5-1,count_10+1);
		}
		if(arr[0]==15){
			bool flag1=helper(arr+1,n-1,count_5,count_10-1);
			if(flag1==false){
			bool flag2=helper(arr+1,n-1,count_5-2,count_10);
			if(flag2==false) flag=false;
			else flag=true;

			}
			//cout<<"flag1 "<<flag1<<endl;
			//cout<<"flag2 "<<flag2<<endl;
			/*
			if(flag1 || flag2 ) flag=true; // optimising a bit 
			else flag=false; */
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