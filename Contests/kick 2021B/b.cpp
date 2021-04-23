#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>


#define db1(x) cout<<#x<<"="<<x<<'\n'
#define db2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<'\n'
#define db3(x,y,z) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<","<<#z<<"="<<z<<'\n'
#define ff              first
#define endl            '\n'
#define ss              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
#define MOD 1000000007
using namespace std;
using ll = long long;
inline int powMod(int a, int b) { int x = 1; while (b > 0) { if (b & 1) x = (x * a) % MOD; a = (a * a) % MOD; b >>= 1; } return x; }
inline int multiply(int x, int y) { return ((x % MOD) * (y % MOD)) % MOD; }
inline int divide(int x, int y) { return ((x % MOD) * powMod(y % MOD, MOD - 2)) % MOD; }
inline int ceil(int a, int b) { return (a + b - 1) / b; }
int gcd (int a, int b) { while (b) { a %= b; swap(a, b); } return a; }
int lcm (int a, int b) { return a / gcd(a, b) * b; }
int inverseMod(int a, int m) { a = a % m; for (ll x = 1; x < m; x++) if ((a * x) % m == 1) return x; return -1; }

template<int D, typename T> struct vec : public vector < vec < D - 1, T >> { static_assert(D >= 1, "Vector dimension must be greater than zero!");  template<typename... Args> vec(int n = 0, Args... args) : vector < vec < D - 1, T >> (n, vec < D - 1, T > (args...)) { } }; template<typename T> struct vec<1, T> : public vector<T> { vec(int n = 0, T val = T()) : vector<T>(n, val) { }};

const long long MAX_SIZE = 1000001;
#define MAX 100001

vector<long long >isprime(MAX_SIZE , true);
vector<long long >prime;
vector<long long >SPF(MAX_SIZE);
vector<int> bigprime;


vector<int>* sieve() {
    vector<int> * primes = new vector<int>();
    bool *sieve = new bool[MAX];
    for (int i = 0; i < MAX; i++) sieve[i] = true;

    sieve[0] = false;
    sieve[1] = false;
    for (int i = 2; i * i < MAX; i++) {
        if (sieve[i]) {
            //primes->push_back(i);
            for (int j = i * i; j < MAX; j += i) {
                sieve[j] = false;
            }
        }
    }
    for (int i = 0; i < MAX; i++) {
        if (sieve[i]) {
            primes->push_back(i);
        }
    }
    return primes;


}
void print(vector<int>*  primes, ll l, ll u) {
    bool* ans = new bool[u - l + 1];
    for (int i = 0; i < u - l + 1 ; i++) ans[i] = true;
    for (unsigned int i = 0; i < primes->size(); i++) {
        int x = primes->at(i);
        //int just_low= (l/x)*x +x ;   what if l/x * x is starting index ?
        long long just_low =  (l / x) * x;
        if (just_low < l ) just_low += x;
        //cout<<just_low<<" ";
        if ((long long)x * x <= u ) {

            for (ll j = just_low; j <= u ; j += x ) {
                ans[j - l] = false;
            }

            if (x == just_low) { ans[just_low - l] = true ; /* cout<<"here for : "<<just_low<<endl; cout<<" "<<ans[just_low]<<endl; */}
        }

        else break;
    }

    for (int i = 0; i < u - l + 1 ; i++) {
        if (ans[i] == true) {
            //cout<<i+l<<"\n";
            bigprime.push_back(i + 1);
        }

        //  cout<<i+l<<" is "<<ans[i]<<endl;
    }

}
void manipulated_seive(int N)
{

    isprime[0] = isprime[1] = false ;


    for (int i = 2; i < N ; i++)
    {
        // If isPrime[i] == True then i is
        // prime number
        if (isprime[i])
        {
            // put i into prime[] vector
            prime.push_back(i);

            // A prime number is its own smallest
            // prime factor
            SPF[i] = i;
        }

        // Remove all multiples of  i*prime[j] which are
        // not prime by making isPrime[i*prime[j]] = false
        // and put smallest prime factor of i*Prime[j] as prime[j]
        // [ for exp :let  i = 5 , j = 0 , prime[j] = 2 [ i*prime[j] = 10 ]
        // so smallest prime factor of '10' is '2' that is prime[j] ]
        // this loop run only one time for number which are not prime
        for (int j = 0;
                j < (int)prime.size() &&
                i * prime[j] < N && prime[j] <= SPF[i];
                j++)
        {
            isprime[i * prime[j]] = false;

            // put smallest prime factor of i*prime[j]
            SPF[i * prime[j]] = prime[j] ;
        }
    }
}

void solve(int caseno) {
    int ans = 0;
    int z; cin >> z;
    if (z <= (int)1e9) {
        manipulated_seive(1000000);
        vec<1, int> prod;
        for (int i = 0; i < prime.size() - 1; i++) {
            prod.push_back(prime[i]*prime[i + 1]);
        }
        ans = lower_bound(prod.begin(), prod.end(), z) - prod.begin();
        int ind;
        if (prod[ans] == z) ind = ans;
        else ind = ans - 1;
        cout << "Case #" << caseno << ": " << prod[ind] << '\n';
    }
    else {
        vector<int> *primes = sieve();
        int u = sqrt(z);
        int l = ((u - (int)1e6) >= 0) ? (u - (int)1e6) : 0;
        print(primes , l , u);
        vec<1,int> prod;
        for (int i = 0; i < bigprime.size() - 1; i++) {
            prod.push_back(bigprime[i]*bigprime[i + 1]);
        }
        ans = lower_bound(prod.begin(), prod.end(), z) - prod.begin();
        int ind;
        if (prod[ans] == z) ind = ans;
        else ind = ans - 1;
        cout << "Case #" << caseno << ": " << prod[ind] << '\n';
    }
}

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //#ifndef ONLINE_JUDGE
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //#endif
    int t = 1;
    cin >> t;
    int i = 1;
    while (t--) {
        solve(i);
        i++;
    }
    return 0;
}