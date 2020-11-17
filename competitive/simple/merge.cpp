#include<iostream>
using namespace std;
void merge(int a[],int low,int mid,int high){

    int c[high+1];
    int i=low,j=mid +1,k=low;
    while(i<=mid && j<=high){
      if(a[i]>a[j]){
        c[k]=a[j]; j++; k++;
    }
  else if(a[i]<a[j]){
    c[k]=a[i];
    i++; k++;
  }
  else{
    c[k]=a[i]; k++;
    c[k]=a[i]; k++;
    i++; j++;// k++;
  }
  }
  while(i<=mid){
    c[k]=a[i]; k++; i++;
  }
  while(j<=high){
    c[k]=a[j]; k++; j++;
  }
  int m=0;
  for(int i=low;i<=high;i++){
    a[i]=c[m]; m++;
  }
}
int main(){

  int size;
  cin>>size;
  int arr[size];
  for (int i = 0; i < size; i++) {
    /* code */ cin>>arr[i];
  } int low=0;
  int high=size-1;
  int mid=low+high/2;
  merge(arr,low,mid,high);
  for (int i = 0; i < size; i++) {
    /* code */ cout<<arr[i]<<"  ";
  }
}
