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




ll dt[maxn], seg[120*maxn], lazy[120*maxn], lef[120*maxn], rig[120*maxn], ver[maxn], nf=1;
 

void build(ll st, ll en, ll nd){
    if(st==en){
        seg[nd]=dt[st];
        return;
    }
    lef[nd]=++nf;
    rig[nd]=++nf;
    ll mid=(st+en)/2;
    build(st, mid, lef[nd]);
    build(mid+1, en, rig[nd]);
    seg[nd]=seg[lef[nd]]+seg[rig[nd]];
}

ll propogate(ll st, ll en, ll nd, ll val){
    ll nnd=++nf;
    lef[nnd]=lef[nd];
    rig[nnd]=rig[nd];
    lazy[nnd]=lazy[nd];
    lazy[nnd]+=val;
    seg[nnd]=seg[nd]+(en-st+1)*val;
    return nnd;
}

ll update(ll st, ll en, ll nd, ll l, ll r, ll val){
    if(lazy[nd]!=0){
        ll temp=lazy[nd];
        lazy[nd]=0;
        if(st!=en){
            ll mid=(st+en)/2;
            lef[nd]=propogate(st, mid, lef[nd], temp);
            rig[nd]=propogate(mid+1, en, rig[nd], temp);
        }
    }
    if(st>r || en<l){
        return nd;
    }
    ll nnd=++nf;
    if(st>=l && en<=r){
        seg[nnd]=seg[nd]+(en-st+1)*val;
        lazy[nnd]=val;
        lef[nnd]=lef[nd];
        rig[nnd]=rig[nd];
        return nnd;
    }
    ll mid=(st+en)/2;
    lef[nnd]=update(st, mid, lef[nd], l, r, val);
    rig[nnd]=update(mid+1, en, rig[nd], l, r, val);
    seg[nnd]=seg[lef[nnd]]+seg[rig[nnd]];
    return nnd;
}

ll query(ll st, ll en, ll nd, ll l, ll r){
    if(lazy[nd]!=0){
        ll temp=lazy[nd];
        lazy[nd]=0;
        if(st!=en){
            ll mid=(st+en)/2;
            lef[nd]=propogate(st, mid, lef[nd], temp);
            rig[nd]=propogate(mid+1, en, rig[nd], temp);
        }
    }
    if(st>r || en<l){
        return 0;
    }
    if(st>=l && en<=r){
        return seg[nd];
    }
    ll mid=(st+en)/2;
    return query(st, mid, lef[nd], l, r) + query(mid+1, en, rig[nd], l, r);
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