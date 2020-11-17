#include<bits/stdc++.h>
using namespace std;
std::vector<string> crossword[10];
vector<string> words;
int main(){
	for(int i=0;i<10;i++){
		string s;
		cin>>s;
		crossword[i]=s;
	}
	string line,x;
	cin>>line;
	for(auto s:line){
		if(s=';'){
			words.push_back(x);
			x="";
		}
		else{
			x+=s;
		}
		words.push_back(x);
		
	}



	return 0;
}