#include<iostream>
using namespace std;
int main(){
int n;
cin>>n;
for(int row=1;row<=n;row++){ int i=0;

  for(int column=1;column<=n;column ++){
  if(column<=n-row) cout<<" ";
  else{ cout<<row+i;i++; }

} cout<<endl;
}




}
