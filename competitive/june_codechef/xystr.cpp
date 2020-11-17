#include <iostream>
#include<string>

using namespace std;

int helper(string s)
{
    int n=s.size();
    int count=0;
    int i=0;
    while(i<n)
    {
        if(s[i]=='y')
        {
            if(s[i+1]=='x')
               {
                    count++;
                    i+=2;
                    continue;
               }
                
        }
        if(s[i]=='x')
        {
            if(s[i+1]=='y')
            {
                count++;
                i+=2;
                continue;
            }
        }
        i++;
        
    }
    return count;
}

int main() {
  
  int t;
  cin>>t;
    
    
   
  while(t--)
  {   string s;

      cin>>s;

     cout<<helper(s)<<endl;
        
      
  }
    
  return 0;
}