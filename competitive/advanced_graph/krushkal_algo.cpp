#include<iostream>
using namespace std;
bool comp(edge a, edge b){
	return (a.w < b.w );
}

int getparent(parent,src){
	if(src==dest){
		return src;
	}
	return getparent(parent,parent[src]) ;
}

class edge{
public:
	int v1,v2,w;

};

int main(){

int n,e;
cin>>n>>e;
edge* input= new edge[e];
for(int i=0;i<e;i++){
	cin>>input[i].v1>>input[i].v2>>input[i].w;
}
sort(edge,edge+e,comp);
int count= 0;
int* parent = new int[n];

for(int i=0;i<n;i++){
	parent[i]= i;
}
edge* output= new edge[n-1];
int i=0;  // for input array
int j=0; // for output array
while(count < n-1 ){ // since count starts from 0
// parent difft
	int src= input[i].v1;
	int dest= input[i].v2;
 if( getparent(dest,parent) != getparent(src,parent) ){
	output[j].v1= input[i].v1;
	output[j].v2= input[i].v2;
	output[j].w= input[j].w;
	parent[input[i].v1]= parent[input[i].v2];

} 


i++;
}

// print output 
return 0;
}