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




struct FlowEdge {
    int u, v;
    ll cap, flow=0;
    FlowEdge(int u, int v, ll cap) : u(u), v(v), cap(cap) {}
};

struct Dinic {
    vector<FlowEdge> edges;
    vector<vector<int>> adj;
    int n, m=0;
    int s, t;
    vector<int> level, ptr;
    queue<int> q;

    Dinic(int n, int s, int t) : n(n), s(s), t(t) {
        adj.resize(n);
        level.resize(n);
        ptr.resize(n);
    }

    void add_edge(int u, int v, ll cap) {
        edges.emplace_back(u, v, cap);
        edges.emplace_back(v, u, 0);
        adj[u].pb(m++);
        adj[v].pb(m++);
    }

    bool bfs() {
        while (!q.empty()) {
            int u=q.front();
            q.pop();
            for(int i=0; i<adj[u].size(); i++){
                int id=adj[u][i];
                if (edges[id].cap - edges[id].flow < 1) continue;
                if (level[edges[id].v] != -1) continue;
                level[edges[id].v] = level[u]+1;
                q.push(edges[id].v);
            }
        }
        return level[t]!=-1;
    }

    ll dfs(int u, ll pushed) {
        if (!pushed) return 0;
        if (u==t) return pushed;

        for (int &i=ptr[u]; i<adj[u].size(); i++) {
            int id=adj[u][i];
            int v=edges[id].v;
            if(level[u]+1!=level[v] || edges[id].cap-edges[id].flow<1) continue;
            ll curr=dfs(v, min(pushed, edges[id].cap-edges[id].flow));
            if (curr==0) continue;
            edges[id].flow+=curr;
            edges[id^1].flow-=curr;
            return curr;
        }
        return 0;
    }

    ll flow() {
        ll max_flow = 0;
        while (true) {
            fill(level.begin(), level.end(), -1);
            level[s] = 0;
            q.push(s);
            if (!bfs()) break;
            fill(ptr.begin(), ptr.end(), 0);
            while (ll pushed=dfs(s, inf)) {
                max_flow+=pushed;
            }
        }
        return max_flow;
    }
};



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