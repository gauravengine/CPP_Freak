#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		double h,p,sum=0;
		cin>>h>>p;
		while(p!=0 && sum < h){
			sum = sum + p;
			p= floor(p/2);
		}
		if(h-sum <= 0){
			cout<<1<<endl;
		}
		else
			cout<<0<<endl;


	}

return 0;
}
