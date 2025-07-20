#include <bits/stdc++.h>
#define forr(i, a, b) for (int i = (a); i < (b); i++)
#define forn(i, n) forr(i, 0, n)
#define dforn(i, n) for (int i = (n) - 1; i >= 0; i--)
#define forall(it, v) for (auto it = v.begin(); it != v.end(); it++)
#define HOLA ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
 
using namespace std;

 
int main() {
#ifdef EBUG
    freopen("input.txt", "r", stdin);
#endif
    HOLA
    
    ll n;
    cin >> n;

    vector<ll> nums(n);
    vector<ll> prefix(n);
    ll total=0, acum=0;
    forn(i,n){
        cin >> nums[i];
        acum+=nums[i];
        prefix[i]=acum;
        total += nums[i]*(i+1);
    }
    ll res=0;
    forn(i,n-1){
        //cout << (prefix[i+1]-prefix[0])  << " " << nums[0]*(i+1) << " " << i+1 << endl;
        res = max(res, total-(prefix[i+1]-prefix[0])+nums[0]*(i+1));
    }
    forn(i,n-1){
        //cout << (n-(i+1)) << " " << nums[0]*(i+1) << " " << i+1 << endl;
        res = max(res, total-nums[n-1]*(n-(i+1))+(prefix[n-1]-prefix[i]));
    }

    cout << res << endl;

    
    
    return 0;
}
