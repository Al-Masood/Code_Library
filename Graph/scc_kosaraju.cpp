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
vector <ll> rev[maxn];

stack <ll> s;
bool visited[maxn];

ll component[maxn];
vector <ll> components[maxn];
ll numComponents;

void dfs_1(ll u) {
    visited[u]=true;
    for (ll i=0; i<adj[u].size(); i++){
        ll v=adj[u][i];
        if (!visited[v]) dfs_1(v);
    }
    s.push(u);
}

void dfs_2(ll u) {
    component[u]=numComponents;
    components[numComponents].push_back(u);
    visited[u]=true;
    for (ll i=0; i<rev[u].size(); i++){
        ll v=rev[u][i];
        if (!visited[v]) dfs_2(v);
    }
}

void Kosaraju(ll n) {
    for (ll i=1; i<=n; i++)
        if(!visited[i]) dfs_1(i);

    for (ll i=1; i<=n; i++)
        visited[i]=false;

    while (!s.empty()){
        ll v=s.top();
        s.pop();
        if(!visited[v]){
            dfs_2(v);
            numComponents++;
        }
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