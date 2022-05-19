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
#define maxn            400001

ll sq;
 
bool compare(pair<ll, ll> p1, pair<ll, ll> p2){
    if(p1==p2) return false;
    if(p1.first/sq!=p2.first/sq) return p1.first/sq<p2.first/sq;
    return p1.second<p2.second;
}
 
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
 

    ll t;
    t=1;
    while(t--){
        ll n, q;
        cin>>n>>q;
        vector <ll> x(n+1);
        l1(i, n) cin>>x[i];
        vector <pair<ll, ll>> v;
        l0(i, q){
            ll a, b;
            cin>>a>>b;
            v.pb({a, b});
        }
        sq=sqrt(n);
        sort(v.begin(), v.end(), compare);
        
        vector <ll> freq(n+1, 0);

        ll l=0, r=-1;

        ll ans=0;
        l0(i, q){
            if(l<v[i].first){
                while(l!=v[i].first){
                    freq[x[l]]--;
                    if(!freq[x[l]]) ans--;
                    l++;
                }
            }
            else if(l>v[i].first){
                while(l!=v[i].first){
                    freq[x[l-1]]++;
                    if(freq[x[l-1]]==1) ans++;
                    l--;
                }
            }
            if(r<v[i].second){
                while(r!=v[i].second){
                    freq[x[r+1]]++;
                    if(freq[x[r+1]]==1) ans++;
                    r++;
                }
            }
            else if(r>v[i].second){
                while(r!=v[i].second){
                    freq[x[r]]--;
                    if(!freq[x[r]]) ans--;    
                    r--;
                }
            }
            cout<<ans;
            nl
        }
    }
    return 0;
}