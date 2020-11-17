typedef long long ll;
long staircase(int n){
    /*  Don't write main().
     *  Don't read input, it is passed as function argument.
     *  Return output and don't print it.
     *  Taking input and printing output is handled automatically.
     */
    ll* output = new ll[n+1];
    output[0]=1;
    output[1]=1;
    output[2]=2;
    for(int i=3;i<=n;i++){
        output[i]= output[i-1]+ output[i-2]+ output[i-3];
    }
    ll ans= output[n];
    delete [] output;
    return ans;
    
}
