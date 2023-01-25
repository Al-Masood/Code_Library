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
			


            
ll base1 = 1e9+21, base2 = 1e9+181, MOD=2000000063;
string s;
ll pw1[maxn], pw2[maxn], len;

void pw_calc() {
    pw1[0] = pw2[0] = 1;
    for(int i = 1; i < maxn; i++) {
        pw1[i] = (pw1[i-1] * base1) % MOD;
        pw2[i] = (pw2[i-1] * base2) % MOD;
    }
}

struct hash {
    ll h1[maxn], h2[maxn];

    void init() {
        h1[0] = h2[0] = 0;
        for(int i = 1; i <= len; i++) {
            h1[i] = (h1[i-1] * base1 + s[i]) % MOD;
            h2[i] = (h2[i-1] * base2 + s[i]) % MOD;
        }
    }

    inline ll hashval(int l, int r) {
        ll hsh1 = (h1[r] - h1[l-1] * pw1[r-l+1]) % MOD;
        if(hsh1 < 0) hsh1 += MOD;
        ll hsh2 = (h2[r] - h2[l-1] * pw2[r-l+1]) % MOD;
        if(hsh2 < 0) hsh2 += MOD;
        return (hsh1 << 32) | hsh2;
    }

    inline ll hashone(int l, int r) {
        ll hsh1 = (h1[r] - h1[l-1] * pw1[r-l+1]) % MOD;
        if(hsh1 < 0) hsh1 += MOD;
        return hsh1;
    }

    inline ll hashtwo(int l, int r) {
        ll hsh2 = (h2[r] - h2[l-1] * pw2[r-l+1]) % MOD;
        if(hsh2 < 0) hsh2 += MOD;
        return hsh2;
    }
} h;


 
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
 
    pw_calc();
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
    }
    return 0;
}
