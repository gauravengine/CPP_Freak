#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int momo_prices[n];
    for(int i=0;i<n;i++){
    	cin>>momo_prices[i];
    }
    int no_of_days; cin>>no_of_days;
    int money_on_given_day[no_of_days];
    for(int i=0;i<no_of_days;i++){
    	cin>>money_on_given_day[i];
    }
    //normal approach
    for(int i=0;i<no_of_days;i++){
    	int j=0; int no_of_momos=0;
    	while(j!=-1){
    		if(money_on_given_day[i]-momo_prices[j]>0){
    			money_on_given_day[i]=(money_on_given_day[i]-momo_prices[j]);
    			j++; no_of_momos++;
    		}
    		else j=-1;

    	}
    	cout<<no_of_momos<<" "<<money_on_given_day[i]<<endl;
    }



	return 0;
}
