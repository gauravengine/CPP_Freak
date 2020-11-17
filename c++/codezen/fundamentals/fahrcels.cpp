#include<iostream>
using namespace std;
int main()
{
 int s,e,w; int cel;
 cin>>s>>e>>w;
 for(int i=s;i<=e;i+=w )
 { cel=(i-32)*(0.55555556);
   cout<<i<<"\t"<<cel<<endl;



 }



}
