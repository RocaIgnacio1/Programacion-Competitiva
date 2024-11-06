#include <bits/stdc++.h>
#include <bitset>
#include <iostream>
#include <string>
using namespace std;
#define forn(i,n) for(ll i = 0; i < n; i++)
#define fora(p, i,n) for(ll i = p; i < n; i++)
#define pb push_back
typedef long long ll;
#define MAXN 100000000
#ifdef EBUG
//local
#else
//judge
#endif

bool orden(pair<ll, ll> &a, pair<ll, ll> &b){
    if (a.first == b.first) return a.second < b.second;
    return a.first < b.second;
}

ll dist(pair<ll, ll> a, pair<ll, ll> b){
    return abs(a.first - b.first) + abs(a.second - b.second);
}

int main(){
    #ifdef EBUG
        freopen("c.in1", "r", stdin);
    #endif
    ios :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    ll n;
    cin >> n;

    map<ll, ll> cants;
    map<ll, ll> maxs;
    map<ll, ll> mins;
    forn(i, n){
        ll x, y;   
        cin >> x >> y;
        cants[x]++;
        if (maxs.find(x) == maxs.end()) maxs[x] = y;
        else maxs[x] = max(maxs[x], y);

        if (mins.find(x) == mins.end()) mins[x] = y;
        else mins[x] = min(mins[x], y);
    }

    vector<ll> X;
    for(auto x : cants){
        X.push_back(x.first);
    }

    sort(X.begin(), X.end());
    ll ans_bottom = 0;
    bool bottom = true;
    for(ll i = 0; i < X.size() - 1; i++){
        ll x = X[i];
        ll xx = X[i+1];
        ans_bottom += abs(maxs[x] - mins[x]);
        if (cants[x] == 1){
            ans_bottom += min(
                dist({xx, maxs[xx]}, {x, mins[x]}),
                dist({xx, mins[xx]}, {x, mins[x]})
            );
            continue;
        }
        if (!bottom){
            ans_bottom += dist({x, mins[x]}, {xx, mins[xx]});
        }else {
            ans_bottom += dist({x, maxs[x]}, {xx, maxs[xx]});
        }
        bottom = !bottom;
    }
    ll x = X.size()-1;
    ans_bottom += abs(maxs[x] - mins[x]);

    ll ans_upper = 0;
    bottom = false;
    for(ll i = 0; i < X.size() - 1; i++){
        ll x = X[i];
        ll xx = X[i+1];
        ans_upper += abs(maxs[x] - mins[x]);
        if (cants[x] == 1){
            ans_upper += min(
                dist({xx, maxs[xx]}, {x, mins[x]}),
                dist({xx, mins[xx]}, {x, mins[x]})
            );
            continue;
        }
        if (!bottom){
            ans_upper += dist({x, mins[x]}, {xx, mins[xx]});
        }else {
            ans_upper += dist({x, maxs[x]}, {xx, maxs[xx]});
        }
        bottom = !bottom;
    }
    ans_upper += abs(maxs[X.size()-1] - mins[X.size()-1]);
    cout << min(ans_bottom, ans_upper) << endl;
    
    return 0;
}
