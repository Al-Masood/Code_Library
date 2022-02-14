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
			
 
 
 
 
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
 

    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vector <ll> adj[n];
        ll dis[n+1];
        l1(i, n) dis[i]=-1;
        queue <ll> q;
        q.push(1);
        dis[1]=0;
        while(!q.empty()){
            ll a=q.front();
            q.pop();
            for(ll i=0; i<adj[a].size(); i++){
                if(dis[adj[a][i]]==-1){
                    dis[adj[a][i]]=-dis[a]+1;
                    q.push(adj[a][i]);       
                }
            }
        }
    }
    return 0;
}