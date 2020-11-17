#include <iostream>
using namespace std;
const int MAX_CHAR =26;
string* sortString(string &str) 
{ 
    // Hash array to keep count of characters. 
    // Initially count of all charters is 
    // initialized to zero. 
    int charCount[MAX_CHAR] = {0}; 
    
    // Traverse string and increment 
    // count of characters 
    for (int i=0; i<str.length(); i++) 

        // 'a'-'a' will be 0, 'b'-'a' will be 1, 
        // so for location of character in count 
        // array we wil do str[i]-'a'. 
        charCount[str[i]-'a']++;     
    
    // Traverse the hash array and print 
    // characters 
    for (int i=0;i<MAX_CHAR;i++) 
        for (int j=0;j<charCount[i];j++) 
            cout << (char)('a'+i); 
} 
int returnPermutations(string input, string output[], string temp="", int count = 0){
   	/* Don't write main() function.
	 * Don't read input, it is passed as function argument.
	 * Print output as specified in the question
	*/
    if(input.length()==0) {
        output[count] = temp;
        return ++count;
    }
    
    string p;
    int j;
    for(int i=0; i<input.length(); i++) {
        j = 0;
        p = "";
        while(j<input.length()) {
            if(j!=i) {
                p += input[j];
                j++;
            }
            else
                j++;
        }
        count = returnPermutations(p,output,temp+input[i],count);
    }
    return count;
}
int main() {
	// your code goes here
	string input = "abcd";
	string output[100];
    sortString(input);
	int size = returnPermutations(input,output,"");
	for(int i=0; i<size; i++)
	    cout << output[i] << endl;
	return 0;
}
