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




ll modular_inverse(ll a, ll m){
    ll m0=m, x0=0, x1=1;

    while(a>1) {
        ll q=a/m;
        ll t=m;

        m=a%m;
        a=t;

        t=x0;
        x0=x1-q*x0;
        x1=t;
    }

    if (x1<0) x1+=m0;

    return x1;
}

ll chinese_remainder_theorem(vector <ll> a, vector <ll> m){
    ll prod=1;
    for(ll i=0; i<m.size(); i++) prod*=m[i];

    ll ans=0;
    for(ll i=0; i<a.size(); i++){
        ll p=prod/m[i];
        ans+=(a[i]*modular_inverse(p, m[i])*p)%prod;
        ans%=prod;
    }

    return ans;
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

        vector <ll> a(n);
        vector <ll> m(n);

        for(ll i=0; i<n; i++){
            cin>>a[i]>>m[i];
        }

        cout<<chinese_remainder_theorem(a, m);
    }
    return 0;
}

