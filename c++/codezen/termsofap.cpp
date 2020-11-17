#include<iostream>
using namespace std;

int main() {
	// Write your code here
  int x; int count=1;
  cin>>x;
  for(int i=1;count<=x;i++){
    if(!((3*i+2)%4==0)){
      cout<<(3*i+2)<<" "; count++;

    }

  }


}
