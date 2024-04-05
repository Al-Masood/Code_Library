#include <bits/stdc++.h>
 
using namespace std;
 
#define ll              long long
#define l1(i, n)        for (ll i = 1; i <= n; i++)
#define l0(i, n)        for (ll i = 0; i < n; i++)
#define pb              push_back
#define xx              first
#define yy              second
#define sorted(x)       sort(x.begin(), x.end())
#define reversed(x)     reverse(x.begin(), x.end())
#define all(x)          x.begin(), x.end()
#define ms(a, b)        memset(a, b, sizeof(a));
#define cases(tc)       cout<<"Case #"<<tc<<": "
#define nl              cout<<"\n";
#define pi              acos(-1)
#define mod             1000000007
#define inf             1000000000000000001
#define maxn            200001




vector <ll> primes;
ll chk[maxn];

void sieve(){
    for(ll i=2; i*i<maxn; i++){
        if(!chk[i]){
            for(ll j=i*i; j<maxn; j+=i) if(!chk[j]) chk[j]=i;
        }
    }

    for(ll i=2; i<maxn; i++){
        if(!chk[i]) chk[i]=i;
    }

    for(ll i=2; i<maxn; i++){
        if(chk[i]==i) primes.pb(i);
    }
}


ll phi(ll a){
    ll val=a;
    ll ans=a;
    for(ll i=0; i<primes.size() && primes[i]*primes[i]<=a; i++){
        if(!(val%primes[i])){
            ans-=ans/primes[i];
            while(!(val%primes[i])){
                val/=primes[i];
            }
        }
    }
    if(val!=1) ans-=ans/val;

    return ans;
}




int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
 
    sieve();
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
    }
    return 0;
}

