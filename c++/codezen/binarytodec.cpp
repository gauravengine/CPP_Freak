#include<iostream>
#include<math.h>
using namespace std;
int main(){
int n;
cin>>n;
int i=0; int temp=n; int dec=0;
while (temp>0) {
  dec+= (temp%10)*pow(2,i); i++;
  temp=temp/10;
}
cout<<dec;


}
