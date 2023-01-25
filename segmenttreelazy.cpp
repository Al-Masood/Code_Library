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



ll seg[4*maxn];
ll lazy[4*maxn];
ll dt[maxn];


void build(ll st, ll en, ll nd){
    if(st==en){
        seg[nd]=dt[st];
        return;
    }
    ll mid=(st+en)/2;
    build(st, mid, 2*nd);
    build(mid+1, en, 2*nd+1);
    seg[nd]=seg[2*nd]+seg[2*nd+1];
}

void update(ll st, ll en, ll nd, ll l, ll r, ll val){
    if(lazy[nd]!=0){
        ll temp=lazy[nd];
        lazy[nd]=0;
        seg[nd]+=temp*(en-st+1);
        if(st!=en){
            lazy[2*nd]+=temp;
            lazy[2*nd+1]+=temp;
        }
    }
    if(st>r || en<l){
        return;
    }
    if(st>=l && en<=r){
        seg[nd]+=val*(en-st+1);
        if(st!=en){
            lazy[2*nd]+=val;
            lazy[2*nd+1]+=val;
        }
        return;
    }
    ll mid=(st+en)/2;
    update(st, mid, 2*nd, l, r, val);
    update(mid+1, en, 2*nd+1, l, r, val);
    seg[nd]=seg[2*nd]+seg[2*nd+1];
}

ll query(ll st, ll en, ll nd, ll l, ll r){
    if(lazy[nd]!=0){
        ll temp=lazy[nd];
        lazy[nd]=0;
        seg[nd]+=temp*(en-st+1);
        if(st!=en){
            lazy[2*nd]+=temp;
            lazy[2*nd+1]+=temp;
        }
    }
    if(st>r || en<l){
        return 0;
    }
    if(st>=l && en<=r){
        return seg[nd];
    }
    ll mid=(st+en)/2;
    return query(st, mid, 2*nd, l, r) + query(mid+1, en, 2*nd+1, l, r);
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