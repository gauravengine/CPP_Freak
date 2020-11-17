#include<bits/stdc++.h>
using namespace std;
#define MAX 100001
#define ll long long 

vector<int>* sieve(){
	vector<int> * primes= new vector<int>();
	bool *sieve= new bool[MAX];
	for(int i=0;i<MAX;i++) sieve[i] = true;

	sieve[0]= false;
	sieve[1]= false;
	for(int i=2;i*i<MAX;i++){
		if(sieve[i]){
			//primes->push_back(i);
			for(int j=i*i;j<MAX;j+=i){
				sieve[j]= false;
			}
		}
	}
	for(int i=0;i<MAX;i++){
		if(sieve[i]){
			primes->push_back(i);
		}
	}
	return primes;


}

void print(vector<int>*  primes, ll l, ll u){
	bool* ans= new bool[u-l+1];
	for(int i=0;i<u-l+1 ; i++) ans[i] = true;
	for(unsigned int i=0;i<primes->size();i++){
		int x= primes->at(i);
		//int just_low= (l/x)*x +x ;   what if l/x * x is starting index ?
		long long just_low =  (l/x)*x;
		if(just_low < l ) just_low+=x;
		//cout<<just_low<<" ";
		if((long long)just_low <= u ){

			for(ll j=just_low;j <= u ;j += x ){
				ans[j-l] = false;
			}

			if(x == just_low){ ans[just_low-l] = true ; /* cout<<"here for : "<<just_low<<endl; cout<<" "<<ans[just_low]<<endl; */}
		}
		
		else break;
	}

	for(int i=0;i<u-l+1 ; i++){
		if(ans[i] == true){
			cout<<i+l<<"\n";
		} 

	//	cout<<i+l<<" is "<<ans[i]<<endl;
	}

}

int  main(){
	int t; cin>>t;
	vector<int>* primes= sieve();
	//for(int i=0;i<200;i++) cout<<primes->at(i)<<" ";
	while(t--){
		ll u,l;
		cin>>l>>u;
		print(primes , l , u);

	}

	return 0;
}