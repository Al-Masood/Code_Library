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




vector <ll> adj[maxn];
ll dt[2*maxn], st[maxn], en[maxn], cnt=0;

void dfs(ll a, ll p){
    dt[++cnt]=a;
    st[a]=cnt;
    for(ll i=0; i<adj[a].size(); i++){
        if(adj[a][i]!=p) dfs(adj[a][i], a);
    }
    dt[++cnt]=-a;
    en[a]=cnt;
    return;
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
 