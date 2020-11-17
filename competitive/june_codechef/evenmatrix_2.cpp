#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define endl "\n"
#define mod 1000000009
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin>>t;
	while(t--){
		int n;
		cin>>n;
		ll square=n*n;
		ll**arr=new ll*[n];
		for(int i=0;i<n;i++){
			arr[i] =new ll[n];
			for(int j=0;j<n;j++){
				arr[i][j]=-1;
			}
		}
		/*
		ll arr[n][n];
		memset(arr,-1,sizeof(arr));
		*/
		

		vector<ll> even_numbers;
		vector<ll> odd_numbers;
		for(ll i=1;i<square+1;i++){
			if(i%2==0) even_numbers.push_back(i);
			else
				odd_numbers.push_back(i);
		}
 	// initiaizing upper triangle diagonals with odd numbers
 	

 	/*
 	for(int i=0;i<n;i++){
 		for(int j=0;j<n;j++){
 			if(i != j && arr[i][j] == -1){
 				if( !odd_numbers.empty() ) {
 					arr[i][j]=odd_numbers.back();
 					odd_numbers.pop_back();
 					arr[j][i]=odd_numbers.back();
 					odd_numbers.pop_back();
 				}
 				else{
 					arr[i][j]=even_numbers.back();
 					even_numbers.pop_back();
 					arr[j][i]=even_numbers.back();
 					even_numbers.pop_back();
 				}
 			}
 			else continue;


 		}
	}

	*/
	// now printing;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
	for(int i=0;i<n;i++){
		delete[] arr[i];
	}
	delete[] arr;
	
	}

	return 0;
}