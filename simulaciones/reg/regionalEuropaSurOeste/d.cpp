#include <bits/stdc++.h>
#define forn(i,n) for(int i = 0; i < n; i++)
#define pb push_back

using namespace std;
typedef long long ll;

#define MAXN 200000

ll bs_ls(vector<ll> &v, ll val){
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
    
    return v[mid];
}
ll bs_gt(vector<ll> &v, ll val){
    int l = 0, r = v.size() - 1, mid = (l+r)/2;
    while(l <= r){
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

    return v[mid];
}

bool ord(pair<ll, ll> &a, pair<ll, ll> &b) {
    return a.first < b.first;
}

int main(){
    #ifdef EBUG
        freopen("input.txt", "r", stdin);
    #endif

    vector<ll> X;
    vector<ll> P;

    int n, m;
    cin >> n >> m;
    forn(i, n){
        ll p;
        cin >> p;
        P.push_back(p);
    }
    forn(i, m){
        ll x;
        cin >> x;
        X.push_back(x);
    }

    sort(X.begin(), X.end());

    vector<pair<ll, ll>> inter;
    forn(i, n){
        ll pos = i*100;
        ll a = bs_ls(X, pos);        
        ll b = bs_gt(X, pos); 
        ll r = min(pos-a, b-pos);
        cerr << a << ", " << b << endl;

        inter.push_back({pos-r, P[i]});
        inter.push_back({pos+r, -P[i]});
    }
    cout << "=========" << endl;

    sort(inter.begin(), inter.end(), ord);

    ll max_ice = 0;
    ll prefix_sum = 0;
    for (auto i : inter) {
        cerr << i.first << ": " << i.second << endl;
        prefix_sum += i.second;
        max_ice = max(prefix_sum, max_ice);
    }

    cout << max_ice << endl;

    return 0;
}
