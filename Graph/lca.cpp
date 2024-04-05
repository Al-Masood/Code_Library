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
#define logn            19




vector <ll> adj[maxn];
ll par[maxn][logn], lev[maxn];

void dfs(ll u, ll p){
    par[u][0]=p;
    lev[u]=lev[p]+1;
    for(ll i=1; i<logn; i++){
        par[u][i]=par[par[u][i-1]][i-1];
    }
    for(ll i=0; i<adj[u].size(); i++){
        if(adj[u][i]!=p) dfs(adj[u][i], u);
    }
    return;
}

ll lca(ll u, ll v) {
    if (lev[u]<lev[v]) swap(u, v);
    for(ll k=logn-1; k>=0; k--) if (lev[par[u][k]] >= lev[v]) u = par[u][k];
    if (u == v) return u;
    for(ll k=logn-1; k>=0; k--) if (par[u][k] != par[v][k]) u = par[u][k], v = par[v][k];
    return par[u][0];
}

ll kth(ll u, ll d){
    if(lev[u]-d<=0) return -1;
    for(ll k=0, p=1; k<logn; k++, p*=2){
        if(d&p){
            u=par[u][k];
        }
    }
    return u;
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

