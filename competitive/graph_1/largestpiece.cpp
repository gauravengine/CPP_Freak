#include<bits/stdc++.h>
using namespace std;

int solve(int** cake,int n,int i,int j, bool** visited){
	if(cake[i][j] == 0) return 0;
	visited[i][j]=true;
	int r=0,l=0,u=0,d=0;
	// right
	if(j+1<n && cake[i][j+1] == 1 && visited[i][j+1]== false ){
		r=  solve(cake,n,i,j+1,visited);
	}
	// left
	if(j-1>=0 && cake[i][j-1] == 1 && visited[i][j-1] == false){
		l=  solve(cake,n,i,j-1,visited);
	}
	//down
	if(i+1 < n && cake[i+1][j] == 1 && visited[i+1][j] == false){
		d=  solve(cake,n,i+1,j,visited);
	}
	//up
	if(i-1>=0 && cake[i-1][j]== 1 && visited[i-1][j] ==false){
		u=solve(cake,n,i-1,j,visited);
	}

	
	return (1+ l+r+u+d);
}

int main(){
	int n; cin>>n;
	int** cake= new int* [n];
	for(int i=0;i<n;i++){
		cake[i]= new int[n];

	} 
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>cake[i][j];
		}
	}
	
	bool** visited= new bool*[n];
	for(int i=0;i<n;i++){
		visited[i]= new bool[n];
		for(int j=0;j<n;j++){
			visited[i][j]=false;
		}
	}
	int ans=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){

			if(cake[i][j]==1){

				int a = solve(cake,n,i,j,visited);
				if(a > ans) ans=a;
				
				for(int i=0;i<n;i++){
					for(int j=0;j<n;j++){
					visited[i][j]=false;
					}
				}

			}

		}
	}

	cout<<ans;
	return 0;
}