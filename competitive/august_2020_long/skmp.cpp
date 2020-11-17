#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		string s;
		string p;
		string res="";
		cin>>s>>p;
		unordered_map <char,int> freq;
		for(int i=0;i<s.length();i++){
			freq[s[i]] ++;
		}

		for(int i=0;i<p.length();i++){
			freq[p[i]] --;
		}
		bool flag= false; // p me koi chhota char nahi h p[0] se , aage
		int m= freq[p[0]];
		int n= p.length();
		int y= min( m,n );
		for(int i=0;i < y;i++){
			
			if(p[i] < p[0] ){
				flag=true;
			}
		}

		for(int i=97;i<123;i++){
			char c= static_cast<char>(i);
			if(!flag){
			
			while( freq[c] > 0 && c <= p[0] ){
				res= res + c;
				freq[c] --;
			}

			}

			else {
				while(freq[c] > 0 && c < p[0] ){
				res= res + c;
				freq[c] --;
			}
			}



		}

		res.append(p);
		for(int i=97;i<123;i++){
			char c= static_cast<char>(i);
			while(freq[c]>0){
				res= res +c;
				freq[c]--;
			}
		}


		cout<<res<<"\n";
	}


	return 0;
}