#include<iostream>

using namespace std;
#include "Pair.cpp"

int main()
{ /*Pair<double, int> p1;
  p1.setx(10.1);
  cout<<"int x is : "<<p1.getx()<<endl;
  p1.sety(12.2);
  cout<<"int y is : "<<p1.gety()<<endl;
*/
Pair<Pair<int,int>,int> p2;
p2.sety(10);
Pair<int,int> p4;
p4.setx(5);
p4.sety(16);
p2.setx(p4);
cout<<p2.getx().getx()<<" "<<p2.getx().gety()<<endl;
}
