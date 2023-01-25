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
ll del[maxn], sz[maxn], par[maxn], cursz;

void dfs(ll a, ll p){
    sz[a]=1;
    for(ll i=0; i<adj[a].size(); i++){
        ll nd=adj[a][i];
        if(nd!=p && !del[nd]){
            dfs(adj[a][i], a);
            sz[a]+=sz[adj[a][i]];
        }
    }
} 

ll findcen(ll a, ll p){
    for(ll i=0; i<adj[a].size(); i++){
        ll nd=adj[a][i];
        if(nd!=p && !del[nd] && sz[nd]>cursz/2){
            return findcen(nd, a);
        }
    }
    return a;
}

void decomp(ll a, ll p){
    dfs(a, -1);
    cursz=sz[a];
    ll cen=findcen(a, -1);
    if(p==-1) p=cen;
    par[cen]=p, del[cen]=1;

    for(ll i=0; i<adj[cen].size(); i++){
        ll nd=adj[cen][i];
        if(!del[nd]) decomp(nd, cen);
    }
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
