#include<bits/stdc++.h>
using namespace std;

class Triplet{
	public:
	int x; 
	int y;
	int gcd;
};

Triplet  extendedEuclid(int a, int b){
	// base case
	if(b==0){
		Triplet ans;
		ans.gcd=a;  // ax + by = a;
		ans.x=1;
		ans.y=0;
		return ans;
	}



	Triplet smallans= extendedEuclid(b,a%b);
	Triplet ans;
	ans.x= smallans.y;
	ans.y= smallans.x - (a/b)*smallans.y;
	ans.gcd = smallans.gcd;

	return ans;


}

int multiplicative_inverse(int a,int m){
	Triplet temp = extendedEuclid(a,m);  // a > m assumed ;
	return temp.x;


}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin>>t;
	while(t--){
		int a,b,d;
		cin>>a>>b>>d;  // given b>a
		int g= __gcd(a,b);

		if(d%g != 0) {
			cout<<0<<"\n";
			continue;
		}
		if(d==0) {
			cout<<1<<"\n";
			continue;
		}

		a/=g;
		b/=g;
		d/=g;
		

		int y1= ((d%a)*multiplicative_inverse(b,a) ) %a;
		if(d/b < y1){
			cout<<0<<"\n";
		}
		else{
			int n= (d/b-y1)/a;
			cout<<n+1<<"\n";
		}

	}

	return 0;
}