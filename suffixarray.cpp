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
			

string s;
ll n;
ll ra[maxn], tempra[maxn];
ll sa[maxn], tempsa[maxn];
ll lcp[maxn], plcp[maxn];
ll phi[maxn];
ll cnt[maxn];

void countingsort(ll k){
    memset(cnt, 0, sizeof cnt);
    for(ll i=0; i<n; i++){
        if(i+k<n) cnt[ra[i+k]]++;
        else cnt[0]++;
    }
    ll mx=max(n, 300ll);
    ll sum=0;
    for(ll i=0; i<mx; i++){
        ll temp=cnt[i];
        cnt[i]=sum;
        sum+=temp;
    }
    for(ll i=0; i<n; i++){
        if(sa[i]+k<n) tempsa[cnt[ra[sa[i]+k]]++]=sa[i];
        else tempsa[cnt[0]++]=sa[i];
    }
    for(ll i=0; i<n; i++) sa[i]=tempsa[i];
}

 
void suffixarray(){
    for(ll i=0; i<n; i++) ra[i]=s[i];
    for(ll i=0; i<n; i++) sa[i]=i;
    for(ll k=1; k<n; k<<=1){
        countingsort(k);
        countingsort(0);
        ll r=0;
        tempra[sa[0]]=r;
        for(ll i=1; i<n; i++){
            if(ra[sa[i]]==ra[sa[i-1]] && ra[sa[i]+k]==ra[sa[i-1]+k]) tempra[sa[i]]=r;
            else tempra[sa[i]]=++r;
        }
        for(ll i=0; i<n; i++) ra[i]=tempra[i];
        if(ra[sa[n-1]]==n-1) break;
    }

}

void lcprefix(){
    phi[sa[0]]=-1;
    for(ll i=1; i<n; i++) phi[sa[i]]=sa[i-1];
    for(ll i=0, len=0; i<n; i++){
        if(phi[i]==-1){
            plcp[i]=0;
            continue;
        }
        while(s[i+len]==s[phi[i]+len]) len++;
        plcp[i]=len;
        len=max(len-1, 0ll);
    }

    for(ll i=0; i<n; i++) lcp[i]=plcp[sa[i]];
}
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
 

    ll t;
    t=1;
    while(t--){
        cin>>s;
        s+='$';
        n=s.size();
        suffixarray();
        lcprefix();
    }
    return 0;
}