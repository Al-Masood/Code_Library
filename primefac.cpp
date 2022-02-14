#include <bits/stdc++.h>
 
using namespace std;
 
#define ll              long long
#define l1(i, n)        for (ll i = 1; i <= n; i++)
#define l0(i, n)        for (ll i = 0; i < n; i++)
#define lo(i, s, n)     for (ll i = s; i <= n; i++)
#define sca(n)          scanf("%lld", &n)
#define pri(n)          printf("%lld", n)
#define pb              push_back
#define mp              make_pair
#define sorted(x)       sort(x.begin(), x.end())
#define reversed(x)     reverse(x.begin(), x.end())
#define all(x)          x.begin(), x.end()
#define ms(a, b)        memset(a, b, sizeof(a));
#define cases(tc)       cout<<"Case "<<tc<<": "
#define nl              cout<<"\n";
#define pnl             printf("\n");
#define pi              acos(-1)
#define mod             1000000007
#define inf             999999999999999999
#define maxn            100001
			
vector <ll> primes;
bool chk[100001];
vector <ll> fac;

void sieve(){
    for(ll i=2; i*i<=100000; i++){
        if(!chk[i]){
            for(ll j=i*i; j<=100000; j+=i) chk[j]=true;
        }
    }

    for(ll i=2; i<=100000; i++){
        if(!chk[i]) primes.pb(i);
    }
}


void factors(ll a){
    fac.clear();
    ll val=a;
    for(ll i=0; i<primes.size() && primes[i]*primes[i]<=a; i++){
        if(!(val%primes[i])){
            fac.pb(primes[i]);
            while(!(val%primes[i])){
                val/=primes[i];
            }
        }
    }
    if(val!=1) fac.pb(val);
}


 
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
 

    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
    }
    return 0;
}