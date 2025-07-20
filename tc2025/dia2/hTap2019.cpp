#include <bits/stdc++.h>
#define forr(i, a, b) for (int i = (a); i < (b); i++)
#define forn(i, n) forr(i, 0, n)
#define dforn(i, n) for (int i = (n) - 1; i >= 0; i--)
#define forall(it, v) for (auto it = v.begin(); it != v.end(); it++)

#define ll long long

#ifdef EBUG
// local
#else
// judge
#endif

using namespace std;
struct Hash {
    ll MOD = 999727999;
    ll BASE = 325255434;
    //ll MOD = 97;
    //ll BASE = 3;
    vector<ll> h, pot;
    string str;

    Hash(string& s) {
        int n = s.size();
        str = s;
        h.resize(n + 1);
        pot.resize(n + 1);
        h[0] = s[0];
        pot[0] = 1;
        for (int i = 0; i < n; i++) {
            h[i + 1] = (h[i] * BASE + s[i]) % MOD;
            pot[i + 1] = (pot[i] * BASE) % MOD;
        }
    }

    // Devuelve el hash del substring s[s..e] en O(1)
    ll get(int s, int e) {
        ll hash_val = (h[e + 1] - h[s] * pot[e - s + 1]) % MOD;
        if (hash_val < 0) hash_val += MOD;
        return hash_val;
    }

    //devuelve el hash del string cambiando en la iesima posicion de c1 a c2.
    // s: inicio del string, e: fin, i: posicion a cambiar, c1: old char, c2: new char
    ll get_change(int s, int e, int i, int c1, int c2) {
        ll original_hash = get(s, e);
        int exp = e - i;
        ll diff = ((c2 - c1) * pot[exp]) % MOD;
        ll changed_hash = (original_hash + diff) % MOD;
        if (changed_hash < 0) changed_hash += MOD;
        return changed_hash;
    }
};

int main() {
#ifdef EBUG
    freopen("input.txt", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
   
    
   int n;
    cin >> n;
    string s;
    cin >> s;
    int r, m;
    cin >> r >> m;
 
    unordered_map<ll,ll> tabla;
    string abecedario = "abcdefghijklmnopqrstuvwxyz,._";
    forn(i,r){
        string palabra;
        cin >> palabra;
        Hash p(palabra);
        tabla[p.get(0,palabra.size()-1)]++;
 
        forn(j,m){
            forn(k, abecedario.size()){
                if(palabra[j] == abecedario[k])continue;
                tabla[p.get_change(0, m-1 , j, palabra[j], abecedario[k])]++;
            }
        }
 
    }
 
    Hash secuencia(s);
    ll ans = 0;
    for(int i=0 ; i+m <= s.size() ; i++){
        ll valor = secuencia.get(i,i+m-1);
 
        if(tabla.count(valor)>0){
            ans += tabla[valor];
        }
    }
    cout << ans << endl;
    return 0;
}