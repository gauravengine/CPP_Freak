#include <iostream> 
using namespace std; 
int count(int a[], int m, int n) 
{ 
    int odd = 0, even = 0; 
    int counter, i, j, p = 1; 
    int pow_set_size = (1 << n);  
    for (counter = 1; counter < pow_set_size;  
                                   counter++) 
    { 
        p = 1; 
        for (j = 0; j < n; j++)  
        { 
  
            // Check if jth bit in the  
            // counter is set If set  
            // then pront jth element from set  
            if (counter & (1 << j))  
            { 
                p *= a[j]; 
            } 
        } 
  
        // if set bits is odd, then add to 
        // the number of multiples 
        if (__builtin_popcount(counter) & 1) 
            odd += ( m / p ); 
        else
            even += ( m / p ); 
    } 
  
    return odd - even; 
} 
int main() 
{ 
    int n;
    int* a = new int[n];
    cout<<"Enter number of elements : ";
    cin>>n;
    cout<<"Enter the prime numbers : "; 
    for(int i=0;i<n;++i)
    {
    	cin>>a[i];
    }
    int m = 100; 
    cout << count(a, m, n); 
    return 0; 
}
