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




ll nxt[maxn][26];
ll created[maxn];
ll endmark[maxn];
ll sz;
char str[maxn];

void clr(){
    memset(nxt[0], 0, sizeof nxt[0]);
    for(ll i=0; i<=sz; i++){
        created[i]=0;
        endmark[i]=0;
    }
    sz=0;
}

void insert(){
    ll curr=0;
    ll len=strlen(str);
    for(ll i=0; i<len; i++){
        ll ch=str[i]-'a';
        if(!created[nxt[curr][ch]]){
            nxt[curr][ch]=++sz;
            memset(nxt[sz], 0, sizeof nxt[sz]);
            created[nxt[curr][ch]]=1;
        }
        curr=nxt[curr][ch];
    }
    endmark[curr]++;
}

bool search(){
    ll curr=0;
    ll len=strlen(str);
    for(ll i=0; i<len; i++){
        ll ch=str[i]-'a';
        if(!created[nxt[curr][ch]]){
            return false;
        }
        curr=nxt[curr][ch];
    }
    if(endmark[curr]) return true;
    else return false;
}




int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
 

    ll t;
    cin>>t;
    while(t--){
        ll n, q;
        cin>>n>>q;
        for(ll i=0; i<n; i++){
            cin>>str;
            insert();
        }

        for(ll i=0; i<q; i++){
            cin>>str;
            cout<<search()<<"\n";
        }

        clr();
    }
    return 0;
}
