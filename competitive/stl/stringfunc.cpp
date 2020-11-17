#include<bits/stdc++.h>
#include<string>
using namespace std;
int main(){
string s="gaurav";// string s1(s);
string s1(s,2,4);// start from 2 and will print next 4 characters;
cout<<s<<endl<<s1<<endl;
string s2=s.substr(1,4);
cout<<s2<<endl;
if(s1.compare(s2)!=0) cout<<"not equal"<<endl;
}
