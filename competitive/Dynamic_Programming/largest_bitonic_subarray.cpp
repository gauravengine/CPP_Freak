#include<iostream>
using namespace std;

int lbs( int * input,int n){
int * output_incresing= new int[n];
	output_incresing[0]=1;
	for(int i=1;i<n;i++){
		output_incresing[i]=1;
		// int smallans= output_incresing[i];
		for(int j=i-1;j>=0;j--){
			if(input[j]<input[i]){
				int smallans = 1 +  output_incresing[j];
				if(smallans > output_incresing[i]){
					output_incresing[i]=smallans;
				}
			}
		}
	}
 int * output_decreasing= new int[n];
  output_decreasing[n-1]=1;
  for(int i=n-2;i>=0;i--){
  	output_decreasing[i]=1;
  	for(int j=i+1;j<n;j++){
  		if(input[j]< input[i]){
  			int smallans= 1+ output_decreasing[j];
  			if(smallans> output_decreasing[i]){
  				output_decreasing[i]= smallans;
  			}
  		}
  	}
  }
int* output_array=new int[n]; int bestans=1;
for(int i=0;i<n;i++){
	output_array[i]=output_decreasing[i]+output_incresing[i]-1;
	if(output_array[i]> bestans){
		bestans = output_array[i];
	}
} 
return bestans;

}

int main(){
	int n;
	cin>>n; 
	int* arr= new int[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	cout<<lbs(arr,n)<<endl;

delete [] arr;


	return 0;

	//return 0;
}