#include<bits/stdc++.h>
using namespace std;
#define MAX 1000001

int main(){
	int t; 
	cin>>t;
	int cas= 1;
	bool *isprime= new bool[MAX];
	for(int i=2;i < MAX;i++){
		isprime[i] = true;
	}

	isprime[0]= false;
	isprime[1]= false;
	for(int i=2;i*i<=MAX;i++)
	{
		if(isprime[i]){
			for(int j= i*i;j<=MAX;j+=i){
				isprime[j] = false;
			}
		}
	}

	int* ans= new int[MAX];
	
	int pos=2;
	for(int i=0;i<MAX;i++){
		ans[i]=1;	
	}
	ans[0]=0;

	for(int i= 2;i<MAX;i++){
		//cout<<i<<endl;
		if(isprime[i]){
			//long long overflow = i*i*i;
			ans[i]= pos;
			pos++;
			//cout<<"here "<<i<<endl;
		  	if(i<=100)	
		  	{ 	int overflow= i*i*i;
		  		ans[overflow] = 0;   // fking overflow   

		 	}
			
			continue;
		}
		if(ans[i] == 0){  // triplet case all its multiples shud be 0
			int j=2*i;
			while(j < MAX){
				ans[j]=0;
				j+= i;
			}
			continue;
		}

		if(ans[i]==1){  // not prime but also not triplet
			ans[i] = pos;
			pos++;
		}


	}
 	//cout<<"here ";
	while(t--){

		int x; cin>>x;
		if(ans[x]==0){
			cout<<"Case "<<cas<<": Not Cube Free";
		}
		else{
			cout<<"Case "<<cas<<": "<<ans[x]<<endl;
		}

		cas++;


	}

	return 0;
}