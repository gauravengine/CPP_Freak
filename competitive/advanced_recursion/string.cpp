#include<bits/stdc++.h>
using namespace std;
int main(){

	int n;
	cin>>n;
	string* my_String=new string[n];
	for(int i=0;i<n;i++){
		cin>>*(my_String+i);
	}
	for(int i=0;i<=n;i++){
		cout<<my_String[i];
	}
	

	//output gaurav despite i=n ;)


	return 0;

}