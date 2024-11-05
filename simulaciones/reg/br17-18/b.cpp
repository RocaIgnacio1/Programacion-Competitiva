#include <bits/stdc++.h>
#include <bitset>
#include <iostream>
#include <string>
using namespace std;
#define forn(i,n) for(ll i = 0; i < n; i++)
#define fora(p, i,n) for(ll i = p; i < n; i++)
#define dforn(i, n) for(int i=n-1; i>=0; i--)
#define pb push_back
typedef long long ll;
#ifdef EBUG
//local
#else
//judge
#endif

const int MAXN = 1e5 + 1;

int n, m, A, B;
vector<int> adj[MAXN];
int gr[MAXN];
set<int> s;

void borrar(int nodo){
    cout << "i:" << nodo+1 << endl;
    if (s.find(nodo) == s.end()) return;
    else cout << "HOLAAAA" << endl;
    for(int i : adj[nodo]){
        cout << "entro " <<  i  << endl;
        cout << "gr:" << gr[i] << endl;
        if(gr[i] < A){
            borrar(i);
        }else gr[i]--;
    }
    s.erase(nodo);
}

void borrar_inv(int nodo){
    cout << "i:" << nodo+1 << endl;
    if (s.find(nodo) == s.end()) return;
    s.erase(nodo);
    for(int i : adj[nodo]){
        if(n - 1 - gr[i] < B){
            borrar_inv(i);
        }else gr[i]--;
    }
}

int main(){
    #ifdef EBUG
        freopen("b.in1", "r", stdin);
    #endif
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m >> A >> B;
    forn(i, m){
        int x, y;
        cin >> x >> y; x--; y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    forn(i, n){
        s.insert(i);
    }

    forn(i, n){
        gr[i] = adj[i].size();
    }
    /*forn(i, n){
        cout << i+1 << ": " << gr[i] << endl;
    }*/

    int prev_n = s.size();
    while(s.size() > 0){
        int i;
        int min = *s.begin();
        int max = *s.rbegin();
        cout << min << ' ' << max << endl;

        if(n - 1 - gr[max] < B){
            i = max;
        }else if(gr[i] < A){
            i = min;
        }else{
            break;
        }
        cout << i+1 << endl;

        for(auto u : adj[i]){
            s.erase(u);
            gr[u]--;
            s.insert(u);
        }
    }
    cout << n << '\n';
    
    return 0;
}