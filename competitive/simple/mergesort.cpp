#include<bits/stdc++.h>
using namespace std;
#include "merge.cpp"
void mergesort(int a[],int size)
{
  int low,mid,high,p,i;
  for(p=2;p<=size;p*=2){
    for(i=0;i+p-1<size;i=i+p){
      low=i;
      high=i+p-1;
      mid=(low+high/2);
      merge(a,low,mid,high);
    }
  }
  if(p/2<size)
  merge(a,0,p/2,size-1);
}
int main()
{
  int size;
  cin>>size;
  int arr[size];
  for (int i = 0; i < size; i++) {
    /* code */ cin>>arr[i];
  }
  mergesort(arr,size);
  for (int i = 0; i < size; i++) {
    /* code */ cout<<arr[i]<<"  ";
  }

}
