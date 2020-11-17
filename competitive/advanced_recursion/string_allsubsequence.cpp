#include<bits/stdc++.h>
using namespace std;
int subs(string s, string* output){
	if(s.empty()){
		output[0]="";
		return 1;
	}
	string small_string=s.substr(1);
	int small_output_size=subs(small_string,output);
	for(int i=0;i<small_output_size;i++){
		output[i+small_output_size]=s[0]+output[i];
	}
	return 2*small_output_size;




}
int main(){
	string s;
	cin>>s;
	string* output= new string[500];
	int output_size=subs(s,output);
	for(int i=0;i<output_size;i++){
		cout<<output[i]<<endl;
	}
	return 0;
}