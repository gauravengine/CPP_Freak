#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
/*
int power_greater(int x){

}
*/
bool perfect_two(ll n){
	return ( n&&(!(n&(n-1))) ); 

}
int find_power_two(ll x){
	/*
	int count=0;
	while((x-(x/2))%2 == 0) {
		count++;
		x=x-(x/2);
	}
return count+1; */
	/*int ans;
	for(int i=0;;++i){
		if((x&(1<<i)) ==0) {
			ans=i-1; break;}
	} 
	return ans; */

	ll initial=2; int i=0;
	if(x%initial==0)
	{	++i;
		initial=pow(2,i);
	} 
	return i;
}
int main(){
 ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin>>t;
  while(t--){
  	ll n;
  	cin>>n;
  	ll ans;
  	if(n%2 != 0) ans=(int)n/2;
  	else if(perfect_two(n)) ans =0;
  	else{
  		int x=find_power_two(n);
 		//cout<<" x "<<x<<endl;
  		ll i=1;
  		ll num=pow(2,x+1);
  		//ans=power_greater(num);
  		
  		ll count=0;
  		while(num*i < n){
  			//cout<<num*i<<endl;
  			i++;
  			count++;
  		}
  		//cout<<count<<endl;
  		//ans=count;  
  		//cout<<num<<endl;
  		double y=(double)(n-num)/num;
  		//cout<<y<<endl;
  		ans=ceil(y);
  		
  	}
  	cout<<ans<<endl;



  }


	return 0;
}