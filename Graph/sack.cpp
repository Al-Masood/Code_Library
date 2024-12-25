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




vector <ll> adj[maxn], sub[maxn], sz(maxn), col(maxn), cnt(maxn);

void dfs_size(ll u, ll p){
    sz[u]=1;
    for(auto v: adj[u]){
        if(v==p) continue;
        dfs_size(v, u);
        sz[u]+=sz[v];
    }
}

void dfs(ll u, ll p, ll keep){
    ll mx=-1, bigchild=-1;
    for(auto v: adj[u]){
        if(v==p) continue;
        if(sz[v]>mx){
            mx=sz[v];
            bigchild=v;
        }
    }

    for(auto v: adj[u]){
        if(v==p || v==bigchild) continue;
        dfs(v, u, 0);
    }

    if(bigchild!=-1){
        dfs(bigchild, u, 1);
        swap(sub[u], sub[bigchild]);
    }

    sub[u].pb(u);
    cnt[col[u]]++;

    for(auto v: adj[u]){
        if(v==p || v==bigchild) continue;
        for(auto x: sub[v]){
            cnt[col[x]]++;
            sub[u].pb(x);
        }
    }

    if(!keep){
        for(auto x: sub[u]){
            cnt[col[x]]--;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
 

    ll t;
    t=1;
    while(t--){
        ll n;
        cin>>n;
    }
    return 0;
}
