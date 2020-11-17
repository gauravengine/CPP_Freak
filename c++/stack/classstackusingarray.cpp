#include <climits>
class stackusingarray{
	 int capacity; int nextindex=0;
	int *data;
public:
	stackusingarray(int totalsize){
		data=new int[totalsize]; capacity=totalsize;
//nextindex=0;
}
void push(int a ){

if (nextindex==capacity) { cout<<"stack overflow"<<endl; return;}

else { data[nextindex]=a; nextindex++; }

}
bool isempty()
{
	return (nextindex==0);
}
int size(){
	return nextindex;
}

int pop(){
 if (nextindex==0) { cout<<"stack underflow"<<endl; return INT_MIN;}

 nextindex--;
	
	return data[nextindex];
}
int top()
{ if(isempty()) return INT_MIN;
	return data[nextindex-1];
}


};














