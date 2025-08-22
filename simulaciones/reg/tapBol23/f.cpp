#include <bits/stdc++.h>
#define forr(i, a, b) for (int i = (a); i < (b); i++)
#define forn(i, n) forr(i, 0, n)
#define dforn(i, n) for (int i = (n) - 1; i >= 0; i--)
#define all(v) v.begin(), v.end()
#define HOLA ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
const ll MAXN = 10000000000;

int main() {
    HOLA;
    #ifdef EBUG
    freopen("f.txt", "r", stdin);
    #endif
    int t;
    cin >> t;
    while(t--){
        int n;
        vector<ll> h, x;
        cin >> n;
        forn(i, n){
            ll k;
            cin >> k;
            h.push_back(k);
        }
        forn(i, n-1){
            ll k;
            cin >> k;
            x.push_back(k);
        }
        vector<ll> pos;
        bool ban = true;
        ll mx = h[0];
        ll acum = 0;
        forn(i, n-1){
            pos.push_back(acum);
            acum += x[i];
        }
        pos.push_back(acum);
        forn(i, n){
            //cout << pos[i] << " " << mx << endl;
            if(pos[i] >= mx) ban = false;
            mx = max(mx, pos[i] + h[i]);
        }
        reverse(h.begin(), h.end());
        reverse(x.begin(), x.end());
        bool ban2 = true;
        mx = h[0];
        acum = 0;
        forn(i, n-1){
            pos[i] = acum;
            acum += x[i];
        }
        pos[n-1] = acum;
        forn(i, n){
            if(pos[i] >= mx) ban2 = false;
            mx = max(mx, pos[i] + h[i]);
        }
        if(ban || ban2) cout << "habibi" << endl;
        else cout << "which" << endl;
        
    }
    
    return 0;
}