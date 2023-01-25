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




vector <ll> extendeuclid(ll x, ll y){
    if(x==0){
        return {0, 1, y};
    }
    vector <ll> v=extendeuclid(y%x, x);
    ll a=v[0];
    ll b=v[1];
    ll tempb=a;
    ll tempa=b-(y/x)*a;
    return{tempa, tempb, v[2]};
}

vector <ll> extendeuclidwrap(ll x, ll y){
    if(x>y){
        vector <ll> v=extendeuclid(y, x);
        return {v[1], v[0], v[2]};
    }
    return extendeuclid(x, y);
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
 

    ll t;
    cin>>t;
    while(t--){
        ll a, b;
        cin>>a>>b;
        vector <ll> v=extendeuclid(a, b);
        cout<<v[0]<<" "<<v[1]<<" "<<v[2];
        nl
    }
    return 0;
}
