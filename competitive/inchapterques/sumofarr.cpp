#include <iostream>
using namespace std;
int sum(int a[],int size)
{
  if(size==1) return a[0];
  int smallans =sum(a,size-1);
return a[size-1] +smallans;
}
int main(){
int size;
cin>>size;
int arr[size];
for (int i=0;i<size;i++){
  cin>>arr[i];

}

cout<<sum(arr,size);
}
