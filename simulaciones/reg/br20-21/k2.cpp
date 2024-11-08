#include <bits/stdc++.h>
#include <bitset>
#include <iostream>
#include <string>
using namespace std;
#define forn(i,n) for(ll i = 0; i < n; i++)
#define fora(p, i,n) for(ll i = p; i < n; i++)
#define dforn(i,n) for(int i=n-1; i>=0; i--)
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
vector<ll> dists;

int bs_min(vector<ll> &v, ll val){
    int l = 0, r = v.size() - 1, mid = (l+r)/2;
    while(l <= r){
        if(val < v[mid]){
            r = mid - 1;
        }else{
            l = mid + 1;
        }
        mid = (l+r)/2;
    }
    if(val < v[mid]){
        mid --;
    }

    return mid;
}

int bs_max(vector<ll> &v, ll val){
    int l = 0, r = v.size() - 1, mid = (l+r)/2;
    while(l < r){
        if(val > v[mid]){
            l = mid + 1;
        }else{
            r = mid - 1;
        }
        mid = (l+r)/2;
    }
    if(val > v[mid]){
        mid ++;
    }

    if (mid < 0) return k;
    return mid;
}

ll dp[10005][755];
void calc(int p, int i){
    int men = bs_min(times[i], dists[p]-l-1);
    int may = bs_min(times[i], dists[p]+l)+1;
    if(may > men+1){ dp[p][i] = may - men - 1;return;}
    dp[p][i] = 0;
    return;
}
void calc2(int p, int i){
    int men = bs_min(times[i], dists[p]-l-1);
    int may = bs_min(times[i], dists[p]+l)+1;
    //cout << p << " " << i << " " << may << " " << men<< endl;
    if(may > men+1){dp[p][i] = dp[p+1][may-1] - ((men>-1)?dp[p+1][men]:0);return;}
    dp[p][i] = 0;
    return;
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
        ll p;
        cin >> p;
        dists.push_back(p);
    }

    /*forn(j, k){
        cout << j << ": ";
        cout << bs_min(times[j], 2) << ' ' << bs_max(times[j], 1) << endl; 
    }*/

    dforn(i, N-1){
        forn(j, k){
            if(i == N-2) calc(i, j);
            else calc2(i, j);
        }
        ll acum = 0;
        forn(j, k){
            acum += dp[i][j] + MOD;
            acum %= MOD;
            dp[i][j] = acum;
        }
    }
    cout << dp[0][k-1] << endl;

/*
    forn(j, k){
        forn(i, N-1){
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