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




struct node{
    bool end;
    node* next[26];
    node(){
        end=false;
        for(ll i=0; i<26; i++){
            next[i]=NULL;
        }
    }
}*root;

void insert(string str, ll len){
    node* curr=root;
    for(ll i=0; i<len; i++){
        ll ch=str[i]-'a';
        if(curr->next[ch]==NULL){
            curr->next[ch]=new node();
        }
        curr=curr->next[ch];
    }
    curr->end=true;
}

bool search(string str, ll len){
    node* curr=root;
    for(ll i=0; i<len; i++){
        ll ch=str[i]-'a';
        if(curr->next[ch]==NULL){
            return false;
        }
        curr=curr->next[ch];
    }
    return curr->end;
}

void del(node* curr){
    for(ll i=0; i<26; i++){
        if(curr->next[i]) del(curr->next[i]);
    }
    delete(curr);
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