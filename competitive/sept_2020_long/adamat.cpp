#include<bits/stdc++.h>
using namespace std;

void swap(int row,int col, int** matrix){
	for(int i=1;i<= row;i++){
		for(int j=1;j<=col;j++){
			if( i >= j) continue;
			int temp=matrix[i][j];
			matrix[i][j]= matrix[j][i];
			matrix[j][i]= temp;
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
		while(t--){
			int n;
			cin>>n;
			int** matrix= new int*[n+1];
			for(int i=1;i<=n;i++){    // lets see if this works otherwise i will do it 0 :)
				matrix[i]= new int[n+1];

			}
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					cin>>matrix[i][j];
				}
			}
			int count=0;
			for(int i=n;i>=2;i--){
				if(matrix[i][i-1] != ((i-1)*n + i-1)){
					
					swap(i,i,matrix);
					count++;

				}
			}

			cout<<count<<"\n";
		}

	return 0;
}