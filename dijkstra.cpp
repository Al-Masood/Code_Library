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
			



vector <pair<ll, ll>> adj[maxn];
vector <ll> dist(maxn, inf);
vector <bool> visited(maxn);

void dijkstra(ll s){
    priority_queue<pair<ll, ll>> pq;
    pq.push({0, s});
    dist[s]=0;
    while(!pq.empty()){
        ll u=pq.top().second;
        pq.pop();
        if(visited[u]) continue;
        visited[u]=true;
        for(ll i=0; i<adj[u].size(); i++){e
           ll v=adj[u][i].first;
           ll w=adj[u][i].second;
           if(dis[v]>dis[u]+w){
               dis[v]=dis[u]+w;
               pq.push({-dis[v], v});
           } 
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
