/*
 |f_n  | = |1 1| * |f_n-1|
 |f_n-1|   |1 0|   |f_n-2|
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
#define maxn            200001




#define row 2
#define col 2
ll exponents[64][row][col];
ll ident[row][col]={{1, 0}, {0, 1}};
ll base[row][col]={{1, 1}, {1, 0}};
ll mat[row][col], res[row][col];

void calcexpo(){
    memcpy(exponents[0], base, sizeof(base));
    for(ll p=1; p<64; p++){
        for(ll i=0; i<row; i++){
            for(ll j=0; j<col; j++){
                ll sum=0;
                for(ll k=0; k<col; k++){
                    sum+=(exponents[p-1][i][k]*exponents[p-1][k][j])%mod;
                    sum%=mod;
                }
                exponents[p][i][j]=sum;
            }
        }
    }
}

ll matexpo(ll n){
    if(n<2) return 1;
    memcpy(mat, ident, sizeof(ident));
    n--;
    ll b=1;
    for(ll p=0; p<64; p++){
        if(n&b){
            for(ll i=0; i<row; i++){
                for(ll j=0; j<col; j++){
                    ll sum=0;
                    for(ll k=0; k<col; k++){
                        sum+=(mat[i][k]*exponents[p][k][j])%mod;
                        sum%=mod;
                    }
                    res[i][j]=sum;
                }
            } 
            memcpy(mat, res, sizeof(res));   
        }
        b<<=1;
    }
    return (1*mat[0][0]+1*mat[0][1])%mod;
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
        calcexpo();
        matexpo(n);
    }
    return 0;
}

