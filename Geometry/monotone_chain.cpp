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




struct pt{
    ll x, y;
};

bool cmp(pt a, pt b){
    return a.x < b.x || (a.x == b.x && a.y < b.y);
}

ll cross(pt a, pt b, pt c){
    return (b.y - a.y) * (c.x - b.x) - (b.x - a.x) * (c.y - b.y);
}

//Use </> instead of <=/>= to include collinear points
vector<pt> convex_hull(vector<pt> hull, ll n){
    if(n <= 1) return hull;
    sort(hull.begin(), hull.end(), cmp);

    vector<pt> up, down;
    for(ll i = 0; i < n; i++){
        while(up.size() > 1 && cross(up[up.size() - 2], up[up.size() - 1], hull[i]) <= 0) up.pop_back();
        while(down.size() > 1 && cross(down[down.size() - 2], down[down.size() - 1], hull[i]) >= 0) down.pop_back();
        up.push_back(hull[i]);
        down.push_back(hull[i]);
    }

    for(ll i = down.size() - 2; i > 0; i--) up.push_back(down[i]);
    return up;
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
