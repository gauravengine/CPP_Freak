#include <iostream>
using namespace std;

int fib(int n, int * arr){
if(n==0 || n==1){
	return n;
}
if(arr[n]>0){
	return arr[n];
}
int output= fib(n-1,arr) + fib(n-2,arr);
arr[n]=output;
return output;


}

int fib2(int n ){
	int * arr= new int[n+1];
	arr[0]=0;
	arr[1]=1;
	for(int i=2;i<=n;i++){
		arr[i]=arr[i-1]+arr[i-2];

	}
	int ans=arr[n];
	delete [] arr;
	return ans;
}


int main(){
	int n;
	cin>>n;
	int * arr= new int[n+1]();
// nth fibo number by DP
	cout<<fib(n,arr)<<"\n"<<fib2(n);


	return 0;
}