#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define endl "\n"
#define mod 1000000009

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin>>t;
	while(t--){
		int x[3],y[3];
		for(int i=0;i<3;i++) cin>>x[i];
		for(int i=0;i<3;i++) cin>>y[i];
		int num_of_equal=0;
		int difference[3];
		double multiplication[3];
		// calculating difference and number of equals
		int equal; //see if use
		for(int i=0;i<3;i++){
			difference[i]=x[i]-y[i];   //not taking abs b/c -7 and +7 pe same aega fer usse dikkat hogi
			if(x[i]!=0 && y[i]!= 0)                        // dono ko isliye kyon ki 0->7 me bhi 0 aega orr 0->0 pe bhi zero aega !
			{
				multiplication[i]=(double)y[i]/x[i];
			}
			else{
				if(x[i]==0 && y[i]!=0) multiplication[i]=y[i];
				if(x[i]!=0 && y[i]==0) multiplication[i]=0;
				if(x[i]==0&&y[i]==0) multiplication[i]=0;
			}
			if(difference[i]==0){ num_of_equal++; equal=i;}

		}	
		int different_index1[2];
		if(num_of_equal==1){
			int j=0;
			for(int i=0;i<3;i++){
			if(i!=equal){
				different_index1[j]=i; j++;
			}
			}
		}
		// multiplication same 
		bool ans1=false; // first calculating conditions for 1 to be true
		if(multiplication[0]==multiplication[1]&&multiplication[1]==multiplication[2]) ans1=true;
		if(difference[0]==difference[1] && difference[1]==difference[2] )  ans1=true;
		if(num_of_equal==1){
			if(difference[different_index1[0]]==difference[different_index1[1]]) ans1=true;
			if(multiplication[different_index1[0]]==multiplication[different_index1[1]]) ans1=true;
		}
		if(num_of_equal==2) {ans1=true; cout<<"here";}
		bool ans2=false;
		if(num_of_equal==1){
			if(difference[0]==difference[1]||difference[1]==difference[2]||difference[0]==difference[2]||multiplication[0]==multiplication[1]||multiplication[1]==multiplication[2]||multiplication[0]==multiplication[2]){
				ans2=true;
			}
		}
		if(difference[0]==difference[1]||difference[1]==difference[2]||difference[0]==difference[2]||multiplication[0]==multiplication[1]||multiplication[1]==multiplication[2]||multiplication[0]==multiplication[2]){
				ans2=true;
			}
		int ans;
		if(num_of_equal==3) ans=0;
		else if(ans1) ans=1;     //for ans=1
		else if(ans2) ans=2;
		else ans=3;
		cout<<ans<<endl;

	}


	return 0;
}