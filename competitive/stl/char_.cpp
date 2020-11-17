//worked ;)
#include<bits/stdc++.h>
using namespace std;
char* uniqueChar(char *str){
    // Write your code here
  unordered_set<char> s;
  for(int i=0;i<strlen(str);i++){
    s.insert(str[i]);
  }
int i=0,j=0; static char ans[1000000];
while(str[i]!='\0'){
auto it=s.find(str[i]);
if(it!=s.end())//element found in unordered_set
{ans[j]=*it;
  j++; i++; s.erase(it);
}
else {
  i++;
}


}
/*  set<char>::iterator it; int i=0;
  for(it=s.begin();it!=s.end();it++){
    str[i]=*it; i++;
  }
  str[i]='\0';
  return str; */
  if(ans[j]!='\0') ans[j++]='\0';
  return ans;
}
int main(){
  char st[]="Bcr$gw)TcE5S@DHTFw76" ;

cout<<uniqueChar(st);

}
