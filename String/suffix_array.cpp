/*
s=banana, s=banana$, m=7
sa={$, a$, ana$, anana$, banana$, na$, nana$} = {6, 5, 3, 1, 0, 4, 2}
lcp={0, 0, 1, 3, 0, 0, 2}
*/

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
#define maxn            200005




string s;
ll m, ra[maxn], tempra[maxn], sa[maxn], tempsa[maxn], lcp[maxn], plcp[maxn], phi[maxn], cnt[maxn];

void countingsort(ll k){
    memset(cnt, 0, sizeof cnt);
    for(ll i=0; i<m; i++){
        if(i+k<m) cnt[ra[i+k]]++;
        else cnt[0]++;
    }
    ll mx=max(m, 300ll);
    ll sum=0;
    for(ll i=0; i<mx; i++){
        ll temp=cnt[i];
        cnt[i]=sum;
        sum+=temp;
    }
    for(ll i=0; i<m; i++){
        if(sa[i]+k<m) tempsa[cnt[ra[sa[i]+k]]++]=sa[i];
        else tempsa[cnt[0]++]=sa[i];
    }
    for(ll i=0; i<m; i++) sa[i]=tempsa[i];
}

 
void suffixarray(){
    for(ll i=0; i<m; i++) ra[i]=s[i];
    for(ll i=0; i<m; i++) sa[i]=i;
    for(ll k=1; k<m; k<<=1){
        countingsort(k);
        countingsort(0);
        ll r=0;
        tempra[sa[0]]=r;
        for(ll i=1; i<m; i++){
            if(ra[sa[i]]==ra[sa[i-1]] && ra[sa[i]+k]==ra[sa[i-1]+k]) tempra[sa[i]]=r;
            else tempra[sa[i]]=++r;
        }
        for(ll i=0; i<m; i++) ra[i]=tempra[i];
        if(ra[sa[m-1]]==m-1) break;
    }

}

void lcprefix(){
    phi[sa[0]]=-1;
    for(ll i=1; i<m; i++) phi[sa[i]]=sa[i-1];
    for(ll i=0, len=0; i<m; i++){
        if(phi[i]==-1){
            plcp[i]=0;
            continue;
        }
        while(s[i+len]==s[phi[i]+len]) len++;
        plcp[i]=len;
        len=max(len-1, 0ll);
    }

    for(ll i=0; i<m; i++) lcp[i]=plcp[sa[i]];
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
        m=s.size();
        suffixarray();
        lcprefix();
    }
    return 0;
}