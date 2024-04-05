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
			



ll cnt, par[maxn], rnk[maxn], sz[maxn];

void make_set(ll a){
    par[a]=a;
    rnk[a]=1;
    sz[a]=1;
}

ll find(ll a){
    if(a==par[a]) return a;
    return par[a]=find(par[a]);
}
 
void merge(ll a, ll b){
    ll p1=find(a);
    ll p2=find(b);
    if(p1==p2){
        return;
    }
    if(p1>p2) swap(p1, p2);
    par[p1]=p2;
    sz[p2]+=sz[p1];
    if(rnk[p1]==rnk[p2]) rnk[p2]++;
    cnt--;
}

bool same(ll a, ll b){
    return(par[a]==par[b]);
}

ll count(){
    return cnt;
}

ll get_size(ll a){
    return sz[par[a]];
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
        vector<vector <ll>> v(m, vector <ll> (3)); 
        ll ans=0;
        cnt=n;
        l0(i, n) make_set(i);
        l0(i, m){
            ll a, b, c;
            cin>>a>>b>>c;
            v[i]={c, a, b};
        }
        sorted(v);

        l0(i, m){
            if(find(v[i][1])!=find(v[i][2])){
                merge(v[i][1], v[i][2]);
                ans+=v[i][0];
            }
        }
        cout<<ans;
        nl
    }
    return 0;
}