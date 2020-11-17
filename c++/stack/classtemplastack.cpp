#include <climits>
template <typename T>

class stackusingarray{
	 int capacity; int nextindex=0;
	T *data;
public:
	stackusingarray(){
		data=new T[4]; capacity=4;
//nextindex=0;
}
void push(T a ) {

if (nextindex==capacity) { //cout<<"stack overflow"<<endl; return;
 T *newdata=new T[capacity*2];
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

T pop(){
 if (nextindex==0) { cout<<"stack underflow"<<endl; return 0;}

 nextindex--;

	return data[nextindex];
}
T top()
{ if(isempty()) return 0;
	return data[nextindex-1];
}


};
