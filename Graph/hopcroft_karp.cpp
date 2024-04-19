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
#define maxn            200001




struct Hopcroft_Karp {
    static const int inf = 1e9;
    vector <vector<int>> adj;
    int n, m;
    vector <int> lef, rig, dis;
    queue <int> q;

    Hopcroft_Karp(int n, int m) : n(n), m(m) {
        int p=n+m+1;
        adj.resize(p);
        lef.resize(p, 0);
        rig.resize(p, 0);
        dis.resize(p, 0);
    }

    void add_edge(int u, int v) {
        adj[u].pb(v+n);
    }

    bool bfs() {
        for(int i=1; i<=n; i++){
            if(!lef[i]){
                dis[i]=0;
                q.push(i);
            }
            else dis[i]=inf;
        }

        dis[0]=inf;
        while (!q.empty()) {
            int u=q.front();
            q.pop();
            for(int i=0; i<adj[u].size(); i++){
                int v=adj[u][i];
                if(dis[rig[v]]==inf){
                    dis[rig[v]]=dis[u]+1;
                    q.push(rig[v]);
                }
            }
        }

        return dis[0]!=inf;
    }

    bool dfs(int u){
        if(!u) return true;
        for(int i=0; i<adj[u].size(); i++){
            int v=adj[u][i];
            if(dis[rig[v]]==dis[u]+1 && dfs(rig[v])){
                lef[u]=v;
                rig[v]=u;
                return true;
            }
        }
        dis[u]=inf;
        return false;
    }

    ll matching(){
        ll max_matching=0;
        while(bfs()){
            for(int i=1; i<=n; i++){
                if(!lef[i] && dfs(i)) max_matching++; 
            }
        }
        return max_matching;
    }
};



int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
 

    int t;
    t=1;
    while(t--){
        int n, m, p;
        cin>>n>>m>>p;
        Hopcroft_Karp h(n, m);
        l0(i, p){
            int u, v;
            cin>>u>>v;
            h.add_edge(u, v);
        }
        cout<<h.matching();
        nl
    }
    return 0;
}