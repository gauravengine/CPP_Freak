#include<bits/stdc++.h>
using namespace std;

int gcd (int a,int b){
	if(b== 0){
		return a;
	}
	return gcd(b,a%b);

}

int main(){
	int t;
	cin>>t;
	while(t--){
		int a;
		string b;
		cin>>a>>b;  // b>a  gcd(a,b)= gcd(b,a) = gcd(a, b%a); so ill calculate b%a;
		if(a==0) {
			cout<<b<<endl;
			continue;
		}
		int temp=0;
		for(int i=0;i<b.size();i++){
			temp= ( (temp * (10%a) )%a + (b[i]-'0')%a)%a;

		}
		cout<<gcd(a,temp)<<endl; 



	}



	return 0;
}