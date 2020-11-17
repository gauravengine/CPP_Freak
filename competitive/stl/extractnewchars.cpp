#include<bits/stdc++.h>
using namespace std;

char* uniqueChar(char *str){
    // Write your code here
    int n=1; char *ptr=str;
    while(ptr!='\0'){
        n++;
        ptr++;
    }
    int i=0;
    set<char>s(str,str+n-1);
    for(auto it:s){
        str[i++]=it;
    }
    str[i]='\0';
    return str;
}int main()
{
   char str[]= "geeksforgeeks";
   int n = sizeof(str) / sizeof(str[0]);
   cout << removeD(str, n);
   return 0;
}
