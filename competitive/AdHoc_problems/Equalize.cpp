#include<bits/stdc++.h>
using namespace std;
int main(){
 string giv,eql;
 int n;
 cin>>n;
 cin>>giv>>eql;
 int cost=0;
 int i=0;
 while(i<n){
if(giv[i]!=eql[i]){
if(giv[i]==eql[i+1] && i+1<n && giv[i+1]==eql[i]){
	//swap
	/* 
	char temp=giv[i+1];
	giv[i+1]=giv[i];
	giv[i]=temp;
	 */
	cost++;
	i+=2;
}else{
giv[i]=eql[i];
cost++;
i++;
}


}
else{ 
	i++;}



 }

cout<<cost;

	return 0;
}