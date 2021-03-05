#include<bits/stdc++.h>
using namespace std;
typedef long long ll;



int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		ll** matrix= new ll*[n];
		for(int i=0;i<n;i++){
			matrix[i]=new ll[m];
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cin>>matrix[i][j];
			}
		}
		ll count=0;
		int maxrow,maxcol;
		if(n%2==0) maxrow = n/2;
		else maxrow=n/2 +1;

		if(m%2==0) maxcol=m/2;
		else maxcol = m/2 +1;
		

		for(int i=0;i<maxrow;i++){
			for(int j=0;j<maxcol;j++){
				vector<int> temp;
				temp.push_back(matrix[i][j]);
				if(n-i-1 >= 0 && n-i-1 != i) {
					temp.push_back(matrix[n-i-1][j]);

				}
				if(m-j-1 >= 0 && m-j-1 != j){
					temp.push_back(matrix[i][m-j-1]);

				}
				if(m-j-1 >=0 && n-i-1 >=0){
					temp.push_back(matrix[n-i-1][m-j-1]);
				}
				sort(temp.begin(),temp.end());
				int size= temp.size();

				for(int x=0;x<size/2;x++){
					count += temp[size-x-1]- temp[x];
				}

			}
		}


		cout<<count<<"\n";


	}	


	return 0;
}