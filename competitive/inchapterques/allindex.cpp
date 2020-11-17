#include<iostream>
#include "Solution.h"
using namespace std;
int allIndexes(int input[],int size,int x,int output[]){
if(size==0) return 0;
int smallans=allIndexes(input+1,size-1,x,output);
if(smallans==0){
  if(input[0]==x){
    output[0]=0; return (smallans+=1);
  }
  else return smallans;
}
else {
for(int i=0;i<smallans;i++) output[i]+=1;
  if(input[0]==x){
  smallans+=1;
  for(int i=0;i<smallans;i++){
    output[i+1]=output[i];
  }
    output[0]=0; return smallans+1;
  }
  else return smallans;
}


}

int main(){
    int n;
    cin >> n;

    int *input = new int[n];

    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }

    int x;

    cin >> x;

    int *output = new int[n];

    int size = allIndexes(input, n, x, output);
    for(int i = 0; i < size; i++) {
        cout << output[i] << " ";
    }

    delete [] input;

    delete [] output;


}



int allIndexes(int input[],int size,int x,int output[]){
if(size==0) return 0;
int smallans=allIndexes(input+1,size-1,x,output);
if(smallans==0){
  if(input[0]==x){
    output[0]=0; return (smallans+=1);
  }
  else return smallans;
}
else {
for(int i=0;i<smallans;i++) output[i]+=1;
  if(input[0]==x){
  smallans+=1;
  for(int i=0;i<smallans;i++){
    output[i+1]=output[i];
  }
    output[0]=0; return smallans+1;
  }
  else return smallans;
}


}



  // If an empty array comes
  // to the function, then
  // return zero
  if (size == 0) {
      return 0;
  }

  // Getting the recursive answer
  int smallAns = allIndexes(input + 1,
                                  size - 1, x, output);

  // If the element at index 0 is equal
  // to x then add 1 to the array values
  // and shift them right by 1 step
  if (input[0] == x) {
      for (int i = smallAns - 1; i >= 0; i--) {
          output[i + 1] = output[i] + 1;
      }

      // Put the start index in front
      // of the array
      output[0] = 0;
      smallAns++;
  }
  else {

      // If the element at index 0 is not equal
      // to x then add 1 to the array values
      for (int i = smallAns - 1; i >= 0; i--) {
          output[i] = output[i] + 1;
      }
  }
  return smallAns; 
