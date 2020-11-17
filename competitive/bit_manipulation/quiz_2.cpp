
/*
#include<iostream>
using namespace std;
int main(){
	
	cout<<(~0); 
} */
/*
#include <iostream>
using namespace std;

int main(){#include <iostream>
using namespace std;

int main(){
    int y = 0;
    if(1 | (y = 1)) {
        cout << "y is " << y;
    }
    else {
        cout << y;
    }
}
    if(~0 == 1) {
        cout << "yes";
    }
    else {
        cout << "no";
    }
}
*/
#include <iostream>
using namespace std;

int main(){
    int y = 0;
    if(y & (y = 1)) { // first inner bracket got solved!
        cout << "y is " << y;
    }
    else {
        cout << y;
	    }
	}
