#include<iostream>
using namespace std;

void print(int ** edges,int n,int sv,bool* visted){
	cout<<sv<<endl;
	visted[sv]=true ;
	for(int i=0 ; i<n ;i++){
		if(i==sv){
			continue;
		}
		if(edges[sv][i]==1)
		{
			if(visted[i]==false){
				print(edges,n,i,visted);
			}
		}
	}
}


int main(){
	int n,e;
	cin>>n>>e;
	int** edges= new int*[n];
	for(int i=0;i<n;i++){
		edges[i]= new int [n];
		for(int j=0;j<n;j++){
			edges[i][j]=0;
		}
	}
	//cout<<"here"<<endl;
	for(int i=0;i<e;i++){
		int f,s;
		cin>>f>>s;
		edges[f][s]=1;
		edges[s][f]=1;
	}
	//cout<<"here"<<endl;
	bool* visted =new bool[n];
	for(int i=0;i<n;i++){
		visted[i]=false;
	}
	print(edges,n,0,visted);

	return 0;
}