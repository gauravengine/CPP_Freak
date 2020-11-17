#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
void solve(double fc,double fr){
	int dc,dr;
	double tempc=fc/9;
	double tempr= fr/9;
	dc= ceil(tempc);
	dr= ceil(tempr);
	//cout<<"dc "<<dc<<endl;
	//cout<<"dr "<<dr<<endl;
	if(dc < dr ){
		cout<<0<<" "<<dc<<endl;
	}
	else{
		cout<<1<<" "<<dr<<endl;
	}


}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin>>t;
	while(t--){
		double fc,fr;
		cin>>fc>>fr;
		solve(fc,fr);

	}



	return 0;
}