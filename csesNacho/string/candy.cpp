
#include <bits/stdc++.h>
#include <bitset>
#include <iostream>
#include <string>
using namespace std;
#define forn(i,n) for(ll i = 0; i < n; i++)
#define fora(p, i,n) for(ll i = p; i < n; i++)
#define pb push_back
typedef long long ll;
//#define MAXN 1000000010
#ifdef EBUG
//local
#else
//judge
#endif
#define forr(i,s,n) for(int i=s; i<n; i++)
struct Hash{
    int P=1777771, MOD[2], PI[2];
    vector<int> h[2], pi[2];
    vector<ll> primos[2];
    Hash(vector<int>& s){
        MOD[0]=999727999; MOD[1]=1070777777;
        PI[0]=325255434; PI[1]=10018302;
        forr(k,0,2){
           h[k].resize(s.size()+1), pi[k].resize(s.size()+1), primos[k].resize(s.size()+1);
        }
        forr(k,0,2){
            h[k][0]=0;
            pi[k][0]=1;
            ll p=1;
            primos[0][0]=p;
            primos[1][0]=p;
            forr(i,1,s.size()+1){
                h[k][i]=(h[k][i-1]+p*s[i-1])%MOD[k];
                pi[k][i]=(1LL* pi[k][i-1]* PI[k])%MOD[k];
                p=(p*P)%MOD[k];
                primos[k][i]=p;
            }
        }
    }
    ll get(int s, int e){
        ll h0=(h[0][e]-h[0][s]+MOD[0])%MOD[0];
        h0 =(1LL*h0*pi[0][s])%MOD[0];
        ll h1=(h[1][e]-h[1][s]+MOD[1])%MOD[1];
        h1 =(1LL*h1*pi[1][s])%MOD[1];
        return (h0<<32)|h1;
    }
    
    //devuelve el hash del string cambiando en la iesima posicion a c1 por c2.
    // s: inicio del string, e: fin, i: posicion a cambiar, c1: old char, c2: new char
    ll get_change(int s, int e, int i, int c1, int c2){ 
 
        ll h0=(h[0][e]-h[0][s]+MOD[0])%MOD[0];
        h0 =(1LL*h0*pi[0][s])%MOD[0];
        h0 = ((h0 - c1*primos[0][i] % MOD[0]) + MOD[0])%MOD[0];
        h0 = (h0 + c2*primos[0][i])%MOD[0];
 
        ll h1=(h[1][e]-h[1][s]+MOD[1])%MOD[1];
        h1 =(1LL*h1*pi[1][s])%MOD[1];
        h1=( (h1 - c1*primos[1][i])%MOD[1] + MOD[1])%MOD[1];
        h1=(h1 + c2*primos[1][i])%MOD[1];
        return (h0<<32)|h1;
    }
 
    void set_change(int s, int e, int i, int c1, int c2) {
        for (int k = 0; k < 2; ++k) {
            h[k][e] = (h[k][e] - c1 * primos[k][i] % MOD[k] + MOD[k]) % MOD[k];
            h[k][e] = (h[k][e] + c2 * primos[k][i]) % MOD[k];
        }
    }
};


int main(){
    #ifdef EBUG
        freopen("input.txt", "r", stdin);
    #endif
    ios :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n >> k;
    vector<int> c(n);
    forn(i,n){
        cin >> c[i];
    }
    if(k>n){
        cout << 0 << endl;
        return 0;
    }
    
    vector<ll> normales((n/k)+1);
    forn(i,normales.size()){
        if(i==0)normales[i]=0;
        else{
            vector<int> q(k+1,i);
            q[0]=0;
            Hash normalHash(q);
            normales[i] = normalHash.get(0,k+1);
        }
    }
   
    vector<int> prefix(k+1,0);
    vector<int> kas(k+1,0);
    map<ll,vector<int>> tabla;
    Hash hashval(prefix);
    int cont=1;
    
    forn(i,n){
        prefix[c[i]]++;
        kas[prefix[c[i]]]++;
        if(kas[cont]==k) cont++;
        hashval.set_change(0, k+1, c[i], prefix[c[i]]-1, prefix[c[i]]);
        ll a = hashval.get(0,k+1) - (normales[cont-1]);
        tabla[a].pb(i);
    }
    
    if(n%k==0 && kas[n/k]==k){
        cout << n << endl;
        return 0;
    }
    int ans=0;
    for(auto i: tabla){
        if(i.second.size()>1){
            ans = max(ans, i.second[i.second.size()-1]-i.second[0]);
        }
    }
    cout << ans << endl;

    return 0;
}
