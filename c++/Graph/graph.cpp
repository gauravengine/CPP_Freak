#include<iostream>
using namespace std;
int main(){
	int n,e;
	cin>>n;
	cin>>e;
	int** edges=new int*[n];
	for(int i=0;i<n;i++){
		edges[i]=new int[n];
		for(int j=0;j<n;j++){
			cin>>f>>s;
			edges[i][j]=0;
		}

	// taking input;
	
	for(int i=0;i<e;i++){
		int f,s;
		cin>>f>>s;
		edges[f][s]=1;
		edges[s][f]=1;

	}


	}


	return 0;
}