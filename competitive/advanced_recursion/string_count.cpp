#include <iostream>
using namespace std;
void removeX(char str[]){
	if(str[0]=='\0') return;
	if(str[0]=='x'){
		int i=1;
		for(;str[i]!='\0';i++){
			str[i-1]=str[i];
		}
		str[i-1]='\0';
		removeX(str+1);
	}
	else{
		removeX(str+1);

	}
}
int length(char str[]){
	if(str[0]=='\0' )  return 0;
	int smallstring=length(str+1);
	return smallstring+1;


}
int main(){

	char str[100];
	cin>>str;
	int l= length(str);
	cout<<l<<endl;
	removeX(str);
	cout<<str;
}