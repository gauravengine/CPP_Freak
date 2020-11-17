#include<bits/stdc++.h>
using namespace std;

int lcs(string a,string b){
	if(a.empty()|| b.empty()){
		return 0;
	}
	if(a[0]==b[0]){
		return 1+lcs(a.substr(1),b.substr(1));
	} 
	else{
		int option1=lcs(a.substr(1),b);
		int option2=lcs(a,b.substr(1));
		return max(option1,option2);
	}


}

int main(){
string a,b;
cin>>a>>b;
cout<<lcs(a,b);
std::vector<char> v;

	return 0;
}