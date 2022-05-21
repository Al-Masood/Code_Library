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
#define inf             999999999999999999
#define maxn            100001



ll st[maxn][32];

void buildSparseTable(ll dt[], ll n)
{
    for (ll i=0; i<n; i++) st[i][0]=dt[i];
    for (ll j=1; (1<<j)<=n; j++){
        for(ll i=0; (i+(1<<j)-1)<n; i++) st[i][j]=min(st[i][j-1], st[i+(1<<(j-1))][j-1]);
    }
}

ll query(ll l, ll r)
{
    ll j=(ll)log2(r-l+1);
    if (st[l][j]<=st[r-(1<<j)+1][j]) return st[l][j];
    else return st[r-(1<<j)+1][j];
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