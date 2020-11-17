#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define endl "\n"
#define mod 1000000009
int main(){
  //ios::sync_with_stdio(false);
 //cin.tie(0);
  int t;
  cin>>t;
  while(t--){
  	int n; cin>>n;
  	ll**arr=new ll*[n];
  	cout<<"i m here"<<endl; //check 1 ok
  	for(int i=0;i<n;i++){
  		arr[i]=new ll[n];
  		for(int j=0;j<n;j++) arr[i][j]=-1;

  	} // answer matrix bangya !
  cout<<"checpoint 2 "<<endl;
  	int even_numbers=n/2;
  	int odd_numbers= n -  even_numbers;
  	int even[even_numbers];	ll even_counter=0;
  	int odd[odd_numbers]; 		ll odd_counter=0;
  	cout<<"check_point 3"<<endl;
  	cout<<"even_numbers "<<even_numbers<<endl;
  	cout<<"odd_numbers "<<odd_numbers<<endl;

  	int k=(n*n)+1;
  	for(int i=1, ec=0, oc=0;i<k,ec<even_numbers,oc<odd_numbers;i++,oc++,ec++){
  		if(i%2==0) {
  			even[ec]=i;
  		}
  		else{
  			odd[oc]=i;
  		}
  	}
  	even_counter=even_numbers-1;
  	odd_counter=odd_numbers-1;
  	cout<<"check_point 4 "<<endl;
  	cout<<"odd_counter "<<odd_counter<<endl;
  	cout<<"even_counter "<<even_counter<<endl;
  	cout<<"odd size "<<sizeof(odd)/sizeof(int)<<endl;
  	cout<<"even size "<<sizeof(even)/sizeof(int)<<endl;
  	/*
  	 even_counter--;
  	 odd_counter--; */
  	for(int i=0;i<odd_numbers;i++){
  		cout<<"odd number "<<odd[i]<<endl;
  	}
  	 // filling the diagonal with odd numbers
  	 for(int i=0;i<n;i++){ 
  	 	arr[i][i]=odd[odd_counter];
  	 	odd_counter--;
	}  	//filling the  rest matrix
	cout<<"check_point 5"<<endl;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(arr[i][j]==-1) // means i have to fill it
			{
				if(odd_counter>0){
					cout<<"hello"<<endl;
					arr[i][j]=odd[odd_counter];
					odd_counter--;
					arr[j][i]=odd[odd_counter];
					odd_counter--;

				}
				else// means odd count =0; time for even XD
				{
					arr[i][j]=even[even_counter];
					even_counter--;
					arr[j][i]=even[even_counter];
					even_counter--;

				}


			}
			else continue;
		
		}
	
	}
	//now print matrix arr;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}

  }
return 0;
}