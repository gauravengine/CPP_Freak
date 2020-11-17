#include<iostream>
using namespace std;
#include "classstackll.cpp"

int main()
{
  stack <char> s;
  s.push(100);
  s.push(101);
  s.push(98);
  s.push(97);
  s.push(100);
  s.push(100);
  s.push(102);
  s.push(103);
  s.push(94);


  cout<<s.top()<<endl;

  cout<<s.pop()<<endl;
  cout<<s.pop()<<endl;
  cout<<s.pop()<<endl;



cout<<s.getsize()<<endl;
cout<<s.isempty()<<endl;

}
