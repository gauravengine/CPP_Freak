// it worked dunno how ;)
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
		string temp = p;
		for( unsigned int i=0;i<s.length();i++){
			freq[s[i]] ++;
		}

		for( unsigned int i=0;i<p.length();i++){
			freq[p[i]] --;
		}
		
		bool flag1= false;
		string res1 = temp.append(freq[p[0]] , p[0]);     // end me append kardia
		string res2 ="" ;                             // beg me append p[0]

		//cout<<"res1 "<<res1<<endl;
		

		for(int i=0;i<freq[p[0]];i++){
			res2= res2+ p[0];

		}  

		freq[p[0]]= 0;
		res2.append(p);
		//cout<<"res2 "<<res2<<endl;
		for(unsigned int i=0;i<s.length();i++){
			if(res1[i] < res2[i] ){
				flag1 =true;
				break;
			}
			if(res2[i] < res1[i] ){
				
				break;
			}
		}
		for(int i=97;i<123;i++){
			char c= static_cast<char>(i);
			
			while(freq[c] > 0 && c < p[0] ){
				res= res + c;
				freq[c] --;
			}


		}
		if(flag1) res.append(res1);
		else res.append(res2);

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