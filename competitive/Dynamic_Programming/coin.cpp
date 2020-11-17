#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int dont_be_dumb(int denominations[], int numDenominations, int value, ll** output){ // i am a dumb XD
	if(value==0){
		return 1;
	}
	if(value<0){
		return 0;
	}
	if(numDenominations==0){
		return 0;
	}
	cout<<value<<endl;
	cout<<numDenominations<<endl;

	if(output[value][numDenominations] > -1){
		return output[value][numDenominations];
	}

	ll first_option= dont_be_dumb(denominations+1,numDenominations-1,value,output);
	ll second_option= dont_be_dumb(denominations,numDenominations,value - denominations[0],output);
	output[value][numDenominations]= first_option+second_option;
	return first_option+ second_option;
}
int countWaysToMakeChange(int denominations[], int numDenominations, int value){

  
	ll ** output = new ll*[value+1];
    for(int i=0;i<value+1;i++){
    	output[i]= new ll [numDenominations+1];
    	
    	for(int j=0;j<=numDenominations;j++){
    		output[i][j]=-1;
    	} 
    }
    //memset(output,-1,sizeof(int)*(value+1)*(numDenominations+1)); // isme dikkat h ;(
       for(int i=0;i<=value;i++){
   		for(int j=0;j<=numDenominations;j++){
   			cout<<output[i][j]<<" ";
   		}
   		cout<<endl;


   }



    int a= dont_be_dumb(denominations,numDenominations,value,output);
    return a;

	
}
int main(){
	int value;
	cin>>value;
	int numDenominations;
	cin>>numDenominations; int denominations[numDenominations];
	for(int i=0;i<numDenominations;i++){
		cin>> denominations[i];
	}
	cout<<countWaysToMakeChange(denominations,numDenominations,value)<<endl;

	return 0;
}
// ninja solution 
/*
#include <iostream>
using namespace std;

int coin_change(int n, int* d, int numD, int** output) {
	if (n == 0) {
		return 1;
	}
	if (n < 0) {
		return 0;
	}
	if (numD == 0) {
		return 0;
	}
	if (output[n][numD] > -1) {
		return output[n][numD];
	}
	int first = coin_change(n - d[0], d, numD);
	int second = coin_change(n, d + 1, numD - 1);
	output[n][numD] = first + second;
	return first + second;
}

int main() {
	int d[2] = {1,2};
	// allocate 2d array here, n + 1 * numD + 1
	// put all -1
	cout << coin_change(4, d, 2) << endl;
}
 */