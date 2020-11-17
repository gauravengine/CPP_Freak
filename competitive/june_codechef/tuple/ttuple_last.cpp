// last attempt ;(
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
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
			//difference[i]=x[i]-y[i];   //not taking abs b/c -7 and +7 pe same aega fer usse dikkat hogi
			difference[i]=y[i]-x[i];			
			if(x[i]!=0 )                        // dono ko isliye kyon ki 0->7 me bhi 0 aega orr 0->0 pe bhi zero aega !
			{
				multiplication[i]=(double)y[i]/x[i];
			}
			else{
				multiplication[i]=rand();
				/*
				if(x[i]==0 && y[i]!=0) multiplication[i]=y[i];
				if(x[i]!=0 && y[i]==0) multiplication[i]=0;
				if(x[i]==0&&y[i]==0) multiplication[i]=0; */
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
		bool ans1=false; // first calculating conditions for 1 to be true
		if(multiplication[0]==multiplication[1]&&multiplication[1]==multiplication[2]) ans1=true;
		if(difference[0]==difference[1] && difference[1]==difference[2] )  ans1=true;
		if(num_of_equal==1){
			if(difference[different_index1[0]]==difference[different_index1[1]]) ans1=true;
			if(multiplication[different_index1[0]]==multiplication[different_index1[1]]) ans1=true;
		}
		if(num_of_equal==2) ans1=true;
		// answ 1 fine h 
		
		bool ans2=false;
		if(num_of_equal==1) ans2=true;
		if(num_of_equal==0){
		if(x[0]-x[1]!=0 && x[1]-x[2] !=0){ 
			if( ( (y[0]-y[1])/(x[0]-x[1]) == (y[1]-y[2])/(x[1]-x[2]) ) && ( ( y[0]*x[1]-y[1]*x[0])/(x[1]-x[0]) == (y[1]*x[2]-y[2]*x[1])/( x[2]-x[1] ) ) ){
				ans2=true; 
			}
		}

		if(x[0]-x[1]==0 || x[1]-x[2]==0){
			if(difference[0]==difference[1]||difference[1]==difference[2]||difference[0]==difference[2]){/*cout<<"here1 ";*/ ans2=true; }
			if(multiplication[0]==multiplication[1]||multiplication[1]==multiplication[2]||multiplication[0]==multiplication[2]){ /*cout<<"here2 "; */ans2=true;}
			
			// multiplication wala bhi add kar dia online compiler me ;(  par nahi hua ;(
			//cout<<"here";
		}
		if(multiplication[0]==multiplication[1]||multiplication[1]==multiplication[2]||multiplication[0]==multiplication[2]){
			ans2=true; /*cout<<"here3 "; */
		}
		if(difference[0]==difference[1]||difference[1]==difference[2]||difference[0]==difference[2]){ ans2=true;  /*cout<<"here4 "; */}


		}



		if(num_of_equal==3){
			cout<<0<<endl;
		}
		else if(ans1) {cout<<1<<endl;}
		else if(ans2) {cout<<2<<endl;}
		else {cout<<3<<endl;}
	
	}// while ends
	return 0;
}