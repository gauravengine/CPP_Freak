#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
bool comparator(const vector<int> &a,const vector<int> &b){
	return a[1]<b[1];
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n; cin>>n;
	vector<vector<int>> v(n,vector<int>(2));
	for(int i=0;i<n;i++){
		cin>>v[i][0]>>v[i][1];
	}
	sort(v.begin(),v.end(),comparator);
	//cout<<endl;
	/*
	for(int i=0;i<n;i++){
		cout<<v[i][0]<<" "<<v[i][1];
		cout<<endl;
	 }
			*/	
	int count=0;
	int last_time=-1;
	for(int i=0;i<n;i++){
		if(last_time <= v[i][0]){
			count++;
			last_time=v[i][1];
		}
	}
	//	cout<<endl;
		cout<<count<<endl;

	return 0;
}