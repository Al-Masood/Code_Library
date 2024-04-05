// solution for a^x%mod=n in O(sqrt(mod))
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




map <ll, ll> lhs;

ll fastexpo(ll a, ll b, ll MOD){
    if(b==0) return 1;
    ll temp=fastexpo(a, b/2, MOD);
    if(b & 1) return (((a*temp)%MOD)*temp)%MOD;
    else return (temp*temp)%MOD; 
}

ll dislog(ll a, ll n, ll MOD){
    ll b=sqrt(MOD);
    for(ll i=1; i<=b; i++){
        lhs[fastexpo(a, b*i, MOD)]=i;
    }
    ll x=inf;
    for(ll j=0; j<b; j++){
        ll rhs=(n*fastexpo(a, j, MOD))%MOD;
        if(lhs.find(rhs)!=lhs.end()){
            x=min(x, lhs[rhs]*b-j);
        }
    }
    return x;
}




int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
 

    ll t;
    cin>>t;
    while(t--){
        ll a, n, MOD;
        cin>>a>>n>>MOD;
    }
    return 0;
}

