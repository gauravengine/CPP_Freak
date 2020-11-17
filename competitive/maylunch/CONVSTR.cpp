#include<bits/stdc++.h>
using namespace std;
/*
bool comparisonFunc(const char c1, const char c2)
{
    return strcmp(c1, c2) < 0;
} */
typedef long long ll;
int main(){
	int t; cin>>t;
	while(t--){
		int n;
		cin>>n;
		string a,b;
		cin>>a>>b;
		string c=a,d=b;
		vector<char> v;
		int ans=1,flag=-1;
		for(int i=0;i<n;i++){
			if(a[i]!=b[i]){
				if(b[i]>a[i]) {cout<<"-1"<<endl; ans=-1;break;}

				else v.push_back(a[i]);
			}
		}
		//int size=v.size();

		//sort(c.begin(),c.end());
		sort(d.begin(),d.end());
		for(int i=0;i<n;i++){
			if(a[i]==d[0]) flag=0;



		}
		if(flag==-1)
		 {ans=-1;   cout<<"-1"<<endl;}
		//int m=0;
		sort(v.begin(),v.end());
		if(ans!=-1){
		while(!v.empty()){
			char x=v.back();
			v.pop_back();
			//cout<<"here "<<m<<" "<<endl;
			//m++;
			for(int i=0;i<n;i++){
				if(a[i]==x){
					cout<<"2"<<" ";
					cout<<i<<" ";
					for(int j=0;j<n;j++){
						if(a[j]<a[i] && a[j]==b[i]){

							a[i]=a[j];
							cout<<j<<endl;
							
						}

					}
					break;

				}


			}


		}
	}

	}


	return 0;
}