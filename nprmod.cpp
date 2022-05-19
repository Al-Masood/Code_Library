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

ll fac[maxn];

void factorial(){
    fac[0]=1;
    l1(i, maxn-1) fac[i]=(fac[i-1]*i)%mod;
}
 
ll pmod(ll a, ll b){
    if(b==0) return 1;
    ll temp=pmod(a, b/2);
    if(b & 1) return (((a*temp)%mod)*temp)%mod;
    else return (temp*temp)%mod; 
}

ll npr(ll n, ll r){
    ll a=fac[n];
    ll b=pmod(fac[n-r], mod-2);
    return (a*b)%mod;
}
 
 
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
 
    factorial();

    ll t;
    cin>>t;
    while(t--){
        ll n, r;
        cin>>n>>r;

        cout<<npr(n, r);
    }
    return 0;
}