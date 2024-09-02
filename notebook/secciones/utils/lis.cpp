#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll INF = 1;

int lis(vector<ll> const& a) { //longest increasing subsequence
    int n = a.size();
    vector<ll> d(n+1, INF);
    d[0] = -INF;

    for (int i = 0; i < n; i++) {
        ll l = upper_bound(d.begin(), d.end(), a[i]) - d.begin();
        if (d[l-1] <= a[i] && a[i] <= d[l] && a[i] >= 0)
            d[l] = a[i];
    }
    ll ans = 0;
    for (int l = 0; l <= n; l++) {
        if (d[l] < INF)
            ans = l;
    }
    return ans-1;
}