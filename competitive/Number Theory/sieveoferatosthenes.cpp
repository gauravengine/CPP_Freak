#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
int main(){
ios::sync_with_stdio(false);
cin.tie(0);
int n;
cin>>n;
bool* sieve= new bool[n+1];
sieve[0]=false;
sieve[1]=false;
for(int i=2;i<= n;i++){
	sieve[i]= true;
}
for(int i=2;i*i<=n;i++){
	if(sieve[i]==true){
		int temp=i;
		for(int j= i*i;j<=n;j=(i*temp)){
			sieve[j]= false;
			temp++;
		}


	}

}

int count=0;
for(int i=2;i<=n;i++){
	if(sieve[i]) count++;
}

cout<<count<<endl;
	return 0;
}