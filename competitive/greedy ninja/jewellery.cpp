#include<bits/stdc++.h>
using namespace std;
#define ll long long

bool cmp(const pair<int,int> &a,const pair<int,int> &b){
	if(a.second != b.second){
		return a.second>b.second;
	}
	else{
		return a.first<b.first;
	}
}


int main(){
	int n,k;
	cin>>n>>k;
	pair<int,int>* jewellery= new pair<int,int>[n];
	for(int i=0;i<n;i++){
		cin>>jewellery[i].first>>jewellery[i].second;  // first denotes mass second denotes value
	}
	sort(jewellery,jewellery+n,cmp);
	//sorted
	ll ans=0;
	multiset<int> bag;
	for (int i = 0; i < k; ++i)
	{
		int x; cin>>x;
		bag.insert(x);
	}
	for(int i=0;i<n;i++){
		if(bag.lower_bound(jewellery[i].first) == bag.end()){
			continue;
		}
		else{
			ans +=  jewellery[i].second;
			bag.erase(bag.lower_bound(jewellery[i].first));
		}
	}
	cout<<ans;
	return 0;
}