#include<bits/stdc++.h>
using namespace std;
int main(){
	int sum,digits;
	cin>>sum>>digits;
	int arr[digits];
	arr[0]=1;
	int temp=sum-1;
	for(int i=digits-1;i>=0;--i){
		if(temp > 9){ 
			arr[i]=9;

			temp=temp-9;
			//cout<<"temp "<<temp<<endl;
			continue;
		}
		if(temp<=9 && i!=0){
			if(i>=1) {arr[i]=temp; temp=0;
			}
		}
		if(i==0){
		arr[0] += temp;}

	}
	string s;
	//cout<<arr[0]<<endl;
	for(int i=0;i<digits;i++){
		s.push_back(arr[i]+'0');
	}
	cout<<s;

	
	return 0;
}