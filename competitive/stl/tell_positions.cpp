#include<bits/stdc++.h>
using namespace std;
struct student {
  int total_marks;
  string name;
  int roll_number;
};
bool comparator(student a, student b){
  if(a.total_marks!=b.total_marks) return (a.total_marks>b.total_marks);
  return (a.roll_number<b.roll_number);
}
int main(){
  int n;
  cin>>n;
  student s[n];
  for(int i=0;i<n;i++){
    cin>>s[i].name; s[i].roll_number=i; int curr_total_marks=0,marks;
    for(int j=0;j<3;j++){
      cin>>marks; curr_total_marks+=marks;
    }
    s[i].total_marks=curr_total_marks;
  }
sort(s,s+n,comparator);
for(int i=0;i<n;i++){
  cout<<i+1<<" "<<s[i].name<<endl;
}



return 0;
}
