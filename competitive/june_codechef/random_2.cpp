#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
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
	ll n;
	cin>>n;
	cout<<find_power_two(n)<<endl;
	return 0;
}