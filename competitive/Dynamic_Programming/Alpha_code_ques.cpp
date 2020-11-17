
#include<bits/stdc++.h>
using namespace std;
#define M 1000000007
int num_code(int * input,int size){
	int * output= new int[size+1];
	output[0]=1;
	output[1]=1;
	for(int i=2;i<=size;i++){
        if(input[i-1]!= 0)
			output[i]= output[i-1];
        else
            output[i]=0;
		if(input[i-2]*10 + input[i-1] <=26 && input[i-2]*10 + input[i-1]>=10  ){
			output[i] =(output[i] + output[i-2] )%M;
            //output[i] += output[i-2] % M;
			//cout<<"output "<<i<<" "<< output[i]<<endl;
		}
	}
	int ans= output[size];
	delete [] output;
	return ans % M;

}
int main(){
	string s;
	cin>>s;
	while(s[0]-'0'!=0){
		int arr[s.size()];
		for(int i=0;i<s.size();i++){
			arr[i]=s[i]-'0';
           // cout<<arr[i];
		}
		// modulo bhi lena h
		cout<<num_code(arr,s.size())<<endl;

		cin>>s;

	}


return 0;
}

/*
#include<bits/stdc++.h>
using namespace std;
# define M 1000000007
int num_code(int * input,int size){
	int * output= new int[size+1];
	output[0]=1;
	output[1]=1;
	for(int i=2;i<=size;i++){
		output[i]= output[i-1];
		if(input[i-2]*10 + input[i-1] <=26){
			output[i] += output[i-2];
			//cout<<"output "<<i<<" "<< output[i]<<endl;
		}
	}
	int ans= output[size];
	delete [] output;
	return ans% M;

}
int main(){
	string s;
	cin>>s;
	while(s[0]-'0'!=0){
		int arr[s.size()];
		for(int i=0;i<s.size();i++){
			arr[i]=s[i]-'0';
		}
		// modulo bhi lena h
		cout<<num_code(arr,s.size())<<endl;

		cin>>s;

	}


return 0;
}
*/