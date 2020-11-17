#include<iostream>
using namespace std;
int main(){
int n;
cin>>n;
for (int row=1;row<=n;row++){
for(int column=1;column<=(n-row+1);column++){
  cout<<column;

}
cout<<endl;
}



}
