#include <bits/stdc++.h>
 
using namespace std;
 
#define ll              long long
#define l1(i, n)        for (ll i = 1; i <= n; i++)
#define l0(i, n)        for (ll i = 0; i < n; i++)
#define lo(i, s, n)     for (ll i = s; i <= n; i++)
#define sca(n)          scanf("%lld", &n)
#define pri(n)          printf("%lld", n)
#define pb              push_back
#define mp              make_pair
#define sorted(x)       sort(x.begin(), x.end())
#define reversed(x)     reverse(x.begin(), x.end())
#define all(x)          x.begin(), x.end()
#define ms(a, b)        memset(a, b, sizeof(a));
#define cases(tc)       cout<<"Case "<<tc<<": "
#define nl              cout<<"\n";
#define pnl             printf("\n");
#define pi              acos(-1)
#define mod             1000000007
#define inf             999999999999999999
#define maxn            100001

vector <ll> adj[maxn];
bool visited[maxn];	
void dfs(ll a){
    if(!visited[a]){
        visited[a]=true;
        for(ll i=0; i<adj[a].size(); i++){
            dfs(adj[a][i]);
        }
    }
    return;
}
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
 

    ll t;
    t=1;
    while(t--){
        ll n, m;
        cin>>n>>m;
        l0(i, m){
            ll a, b;
            cin>>a>>b;
            adj[a].pb(b);
            adj[b].pb(a);
        }
        
        for(ll i=1; i<=n; i++){
            if(!visited[i]){
                dfs(i);
            }
        }
    }
    return 0;