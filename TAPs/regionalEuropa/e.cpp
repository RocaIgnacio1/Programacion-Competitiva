#include <bits/stdc++.h>
using namespace std;
#define fora(p, i,n) for(int i = p; i < n; i++)
#define forn(i,n) for(int i = 0; i < n; i++)
#define pb push_back
typedef long long ll;
typedef long double ld;
const ld EPS = 1e-9; 
const ll INF = 1e18+100;

string u, v, uaux, vaux;
bool cmpdv(deque<char> d, string v){
    forn(i, d.size()){
        if(d[i] != v[i]){
            return false;
        }
    }
    return true;
}
string solve(string a, string v){
    deque<char> aux;
    string res;
    if(v.size()>a.size()) return a;
    forn(i, v.size()){
        aux.push_back(a[i]);
    }
    forn(i, a.size() - v.size()){
        if(!cmpdv(aux, v)){
            res.push_back(a[i]);
        }
        aux.pop_front();
        aux.push_back(a[i + v.size()]);
    }
    if(!cmpdv(aux, v)){
        fora(a.size()-v.size(), i, a.size()){
            res.push_back(a[i]);
        }        
    }
    return res;
}
#ifdef EBUG
//local
#else
//judge
#endif

int main(){
    #ifdef EBUG
        freopen("input.txt", "r", stdin);
    #endif

    int t;
    cin >> t;
    forn(i, t){
        cin >> u;
        cin >> v;
        uaux = solve(u, "ABAB");
        vaux = solve(v, "ABAB");
        u = uaux;
        v = vaux;
        uaux = solve(u, "BCBC");
        vaux = solve(v, "BCBC");
        u = uaux;
        v = vaux;
        uaux = solve(u, "BB");
        vaux = solve(v, "BB");
        u = uaux;
        v = vaux;
        uaux = solve(u, "AA");
        vaux = solve(v, "AA");
        u = uaux;
        v = vaux;
        uaux = solve(u, "CC");
        vaux = solve(v, "CC");
        u = uaux;
        v = vaux;
        if(u == v){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }


    }

}