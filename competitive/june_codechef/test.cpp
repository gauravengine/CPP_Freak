#include <iostream>
#include<string>

using namespace std;

int makePair(string s)
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
	
	int n;
	cin>>n;
    
    string s;
    int *ans=new int[n];
    int i=0;
	while(i<n)
	{

	    cin>>s;

	    ans[i]=makePair(s);
        i++;
	    
	}
    for(int i=0;i<n;++i)
    {
        cout<<ans[i]<<endl;
    }


	return 0;
}