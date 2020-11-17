#include <climits>
class stackusingarray{
	 int capacity; int nextindex=0;
	int *data;
public:
	stackusingarray(){
		data=new int[4]; capacity=4;
//nextindex=0;
}
void push(int a ) {

if (nextindex==capacity) { //cout<<"stack overflow"<<endl; return;
 int *newdata=new int[capacity*2];
 for(int i=0;i<capacity;i++)
 {newdata[i]=data[i];}
capacity *=2; newdata[nextindex]=a;
nextindex++;
delete [] data;
data=newdata;


}

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
