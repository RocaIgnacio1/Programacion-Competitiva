#include <bits/stdc++.h>
#include <bitset>
#include <iostream>
#include <string>
using namespace std;
#define forn(i,n) for(ll i = 0; i < n; i++)
#define fora(p, i,n) for(ll i = p; i < n; i++)
#define pb push_back
typedef long long ll;

const int MAXN = 300010;

#ifdef EBUG
//local
#else
//judge
#endif

int main(){
    #ifdef EBUG
        freopen("input.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int N, X;
    map<int, int> eventos;
    cin >> N >> X;
    forn(i, N){
        int s, d;
        cin >> s >> d;
        eventos[s] += 1;
        eventos[s+d+1] -= 1;
    } 
    vector<int> cant(MAXN, 0);
    cout << eventos[2e5+1] << endl;
    
    int prefix_sum = 0;
    forn(i, MAXN){
        if (eventos.find(i) != eventos.end()){
            prefix_sum += eventos[i];
        }
        cant[i] = prefix_sum;
    }

    ll ans = LONG_LONG_MAX;
    int t_ans = 1;
    forn(T, 480){
        int x = T;
        ll C = 0;
        while(x <= MAXN){
            C += cant[x];
            x += X;
        }
        if (C < ans){
            t_ans = T;
            ans = C;
        }
    }

    cout << t_ans << ' ' << ans << '\n';
    
    return 0;
}