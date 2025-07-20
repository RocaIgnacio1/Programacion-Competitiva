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
   
    string s, t;
    cin >> s >> t;
    int ceros=0, unos=0;
    forn(i,s.size()){
        if(s[i]=='1')unos++;
        else ceros++;
    }
    vector<int> r0, r1;
    forn(i,t.size()){
        if(((t.size() - (i+1)*ceros) % unos) != 0)continue;
        if(t.size() <= (i+1)*ceros)continue;
        r0.push_back(i+1);
        r1.push_back((t.size() - (i+1)*ceros) / unos);
    }
    Hash h(t);
    //cout << "probando:  " << h.get(0,3) << " " << h.get(4,7) << endl;
    int res = 0;
    forn(i,r0.size()){
        int str0=0,str1=0, j=0;
        bool valid = true;
        int newh;
        forn(k,s.size()){
            if(s[k]=='0'){
                newh = h.get(j,j+r0[i]-1);
                //cout << r0[i] << " " << j << " " << j+r0[i]-1 << "newh:  " << newh << endl;
                j+=r0[i];
                if(str0==0)str0=newh;
                else if(newh!=str0){
                    //cout << j << " " << r0[i] << " " << newh << " " << str0 << endl;
                    valid = false;
                    break;
                }
            }else{
                newh = h.get(j,j+r1[i]-1);
                j+=r1[i];
                if(str1==0)str1=newh;
                else if(newh!=str1){
                    valid = false;
                    break;
                }
            }
            //cout << "Largo " << r0[i] << " " << str0 << " " << str1 << " " << newh << endl;
            
        }
        if(str0!=str1)res += valid;
        //cout << valid << endl;
    }
    cout << res << endl;
    return 0;
}