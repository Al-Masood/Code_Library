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




ll phi[maxn];
ll chk[maxn];

void EulerTotient() {
    phi[1]=1;
    for(ll i=2; i<maxn; i++){
        if(!chk[i]){
            phi[i]=i-1;
            for(ll j=i; j<maxn; j+=i)
                if(!chk[j]) chk[j]=i;
        }
        else{
            phi[i]=phi[chk[i]]*phi[i/chk[i]];
            if(i%(chk[i]*chk[i])==0){
                phi[i]*=chk[i];
                phi[i]/=phi[chk[i]];
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
