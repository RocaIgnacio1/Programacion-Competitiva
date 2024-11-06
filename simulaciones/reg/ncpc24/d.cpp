#include <bits/stdc++.h>
#include <bitset>
#include <iostream>
#include <string>
using namespace std;
#define forn(i,n) for(ll i = 0; i < n; i++)
#define fora(p, i,n) for(ll i = p; i < n; i++)
#define pb push_back
typedef long long ll;
#define MAXN 1000000010
#ifdef EBUG
//local
#else
//judge
#endif

int N, K;
int dp[10003][17];
vector<int> visitas[10003];
vector<int> v;
int solve(int i, int j){
    if(dp[i][j] != -1) return dp[i][j];
    cout << i << " " << j << endl;
    int maxi = 0;
    cout << 1+i << " " <<  N*K << endl;
    if(1+i != (N*K)){
        cout << "hola" << endl << endl;
        forn(p, K){
            if(visitas[v[i]][j] > visitas[v[i+1]][p]){
                maxi = max(maxi, 1+solve(i+1, p));
            }else{
                maxi = max(maxi, solve(i+1, p));
            }
        }
    }
    return dp[i][j] = maxi;
}

int main(){
    #ifdef EBUG
        freopen("input.txt", "r", stdin);
    #endif
    ios :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> K;
    forn(i, N*K){
        int p;
        cin >> p;
        v.push_back(p);
    }
    forn(i, N*K){
        int p;
        cin >> p;
        visitas[p].push_back(i);
    }
    forn(i, N){
        forn(j, K){
            dp[i][j] = -1;
        }
    }
    cout << solve(0,0) << endl;

    forn(i, N){
        forn(j, K){
            cout << i << " " << j << ": " << visitas[i][j] << endl;
        }
    }
}