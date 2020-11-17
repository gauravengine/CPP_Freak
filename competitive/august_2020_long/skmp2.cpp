#include<bits/stdc++.h>
using namespace std;
int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		string s;
		string p;
		string res1="",res2="";

		cin>>s>>p;
		unordered_map <char,int> freq1,freq2;
		for(int i=0;i<s.length();i++){
			freq1[s[i]] ++;
			freq2[s[i]] ++;
		}

		for(int i=0;i<p.length();i++){
			freq1[p[i]] --;
			freq2[p[i]] --;
		
		}
		

		for(int i=97;i<123;i++){
			char c= static_cast<char>(i);
			
			
			while( freq1[c] > 0 && c <= p[0] ){
				res1= res1 + c; // p[0] pehle wala
				freq1[c] --;
			}

			

			
				while(freq2[c] > 0 && c < p[0] ){
				res2= res2 + c; // p[0] baad wala
				freq2[c] --;
			}
			



		}

		res1.append(p);
		res2.append(p);
		for(int i=97;i<123;i++){
			char c= static_cast<char>(i);
			while(freq1[c]>0){
				res1= res1 +c; // pehle wala
				freq1[c]--;
			}
			while(freq2[c]>0){
				res2= res2 +c; // pehle wala
				freq2[c]--;
			}

		}

		// now comparing both
		bool flag1=false, flag2=false;
		for(int i=0;i<s.length();i++){
			if(res1[i] < res2[i] ){
				flag1 =true;
				break;
			}
			if(res2[i] < res1[i] ){
				flag2= true;
				break;
			}
		}

		if(flag1)
		cout<<res1<<"\n";
		else
		cout<<res2<<"\n";

	}


	return 0;
}