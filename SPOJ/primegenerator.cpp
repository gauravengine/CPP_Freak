#include<iostream>
using namespace std;
typedef long long ll ;
int main(){
ios::sync_with_stdio(false);
cin.tie(0);
int t; cin>>t;
int n=100000001;
bool* sieve = new bool[n];
sieve[0]=false;
sieve[1]= false;
for(int i=2;i<= n;i++){
	sieve[i]= true;
}
for(int i=2;i*i<n;i++){
	if(sieve[i]== true){
	int temp=i;
	for(int j=i*i ;j < n;j=(i*temp) ){
		sieve[j]=false;
		temp++;
	}

}


}


while(t--){
	int m,c;
	cin>>m>>c;
	//cout<<"here";
	for(int i=m;i<=c;i++){
		if(sieve[i]== true){
			cout<<i<<"\n";
		
		}
	}





}

	return 0;
}