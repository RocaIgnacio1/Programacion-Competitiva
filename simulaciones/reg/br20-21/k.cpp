#include <bits/stdc++.h>
#include <bitset>
#include <iostream>
#include <string>
using namespace std;
#define forn(i,n) for(ll i = 0; i < n; i++)
#define fora(p, i,n) for(ll i = p; i < n; i++)
#define pb push_back
typedef long long ll;
#ifdef EBUG
//local
#else
//judge
#endif

const int MOD = 1e9+7;

ll k, l;
int N;
vector<vector<ll>> times;
vector<int> dists;

int bs_min(vector<ll> &v, int val){
    int l = 0, r = v.size() - 1, mid = (l+r)/2;
    while(l <= r){
        if(val <= v[mid]){
            r = mid - 1;
        }else{
            l = mid + 1;
        }
        mid = (l+r)/2;
    }
    if(val <= v[mid]){
        mid --;
    }

    //if (mid < 0) return 0;
    return mid;
}

int bs_max(vector<ll> &v, int val){
    int l = 0, r = v.size() - 1, mid = (l+r)/2;
    while(l <= r){
        if(val >= v[mid]){
            l = mid + 1;
        }else{
            r = mid - 1;
        }
        mid = (l+r)/2;
    }
    if(val >= v[mid]){
        mid ++;
    }

    if (mid < 0) return k;
    return mid;
}

ll dp[10005][755];
ll solve(int p, int n){
    //cout << "p: " << p << " n: " << n << " " << dp[p][n] << endl;
    if (dp[p][n] != -1) return dp[p][n];
    if (p == N-1) return dp[p][n] = 1;

    int men = bs_min(times[n], dists[p]-l);
    int may = bs_max(times[n], dists[p]+l);

    ll acum = 0;
    for(int i = men+1; i < may; i++){
        if(dp[p+1][i] != -1) acum += dp[p+1][i];
        else acum += (solve(p+1, i) % MOD);
    }
    return dp[p][n] = acum % MOD;
}

int main(){
    #ifdef EBUG
        freopen("input.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin >> k >> l;
    forn(i, 10005){
        forn(j, 755){
            dp[i][j] = -1;
        }
    }
    forn(i, k){
        vector<ll> aux;
        forn(j, k){
            ll p;
            cin >> p;
            aux.push_back(p);
        }
        times.push_back(aux);
    }
    cin >> N;
    forn(i, N-1){
        int p;
        cin >> p;
        dists.push_back(p);
    }

    /*forn(j, k){
        cout << j << ": ";
        cout << bs_min(times[j], 2) << ' ' << bs_max(times[j], 1) << endl; 
    }*/

    ll ans = 0;
    forn(i, k){
        ans += (solve(0, i) % MOD);
    }
    cout << ans % MOD << '\n';
    /*
    forn(i, k){
        forn(j, N-1){
            cout << dp[i][j] << '\t';
        }
        cout << endl;
    }

    
    vector<ll> aux = {3,4,5,19,20};
    forn(i,aux.size()){
        cout << aux[i] << " ";
    }
    cout << endl;
    forn(i,23){
        cout << "Buscando " << i << "   rta:" << bs_min(aux, i) << endl;
    }
    
    forn(i,aux.size()){
        cout << aux[i] << " ";
    }
    cout << endl;
    forn(i,22){
        cout << "Buscando " << i << "   rta:" << bs_max(aux, i) << endl;
    }
    */ 
    return 0;
}