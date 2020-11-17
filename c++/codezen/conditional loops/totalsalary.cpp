#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
int main(){
 double basicsalary; char grade;
cin>>basicsalary; cin>>grade; double allow;
double hra=0.2*basicsalary;
double da=0.5*basicsalary;
if(grade=='A') allow=1700;
else if(grade=='B') allow=1500;
else  allow=1300;
double pf=0.11 * basicsalary;
double salary=basicsalary+hra+da+allow-pf; int totalsalary=round(salary);

cout<<totalsalary;


}
