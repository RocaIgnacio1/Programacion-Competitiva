#include <bits/stdc++.h>
#define forr(i, a, b) for (int i = (a); i < (b); i++)
#define forn(i, n) forr(i, 0, n)
#define dforn(i, n) for (int i = (n) - 1; i >= 0; i--)
#define forall(it, v) for (auto it = v.begin(); it != v.end(); it++)

typedef long long ll;

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

    // devuelve el hash del string cambiando en la iesima posicion de c1 a c2.
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
