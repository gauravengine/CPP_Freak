#include<bits/stdc++.h>
using namespace std;
void merge(int a[],int b[],int sizea,int sizeb)
{
  int c[sizea+sizeb];
  int i=0,j=0,k=0;
  while(i<sizea && j<sizeb){
    if(a[i]>b[j]){
      c[k]=b[j]; j++; k++;
  }
else if(a[i]<b[j]){
  c[k]=a[i];
  i++; k++;
}
else{
  c[k]=a[i]; k++;
  c[k]=a[i]; k++;
  i++; j++;// k++;
}
}
while(i<sizea){
  c[k]=a[i]; k++; i++;
}
while(j<sizeb){
  c[k]=b[j]; k++; j++;
}

for(int i=0;i<sizea+sizeb;i++){
  cout<<c[i]<<"  ";
}
}
int main(){
  int sizea,sizeb;
  cin>>sizea; int a[sizea];
  for(int i=0;i<sizea;i++){
    cin>>a[i];
  }
cin>>sizeb; int b[sizeb];
for(int i=0;i<sizeb;i++){
  cin>>b[i];
}
merge(a,b,sizea,sizeb);





  return 0;
}
