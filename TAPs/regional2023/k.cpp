#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fora(p, i, n) for(int i = p; i < n; i++)
#define forn(i, n) for(int i = 0; i < n; i++)
#define fori(i, n) for(int i = n - 1; i <= 0; i--)
#define forall(it, v) for (auto it = v.begin(); it != v.end(); it++)

#ifdef EBUG
#else
#endif
vector<int> v;
int n, k;
vector<int> dp(1 << k);

void solve25(){
    vector<bool> visitado, guardado;
    vector<int> res;
    forn(i, k){
        visitado.push_back(false);
        guardado.push_back(false);
    }
    int aux = k;
    int j = 0;
    forn(i, n){
        if(j < aux){
            if(visitado[v[i]] == false){
                visitado[v[i]] = true;
                j++;
            }
            if(j==aux){
                res.push_back(v[i]);
                guardado[v[i]] = true;
                visitado[v[i]] = true;
                forn(f,k){
                    if(guardado[f] == false){
                        visitado[f] = false;
                    }
                }
                j=0;
                aux--;
            }
        }
    }
    forn(i, k){
        if(visitado[i] == false){
            res.push_back(i);
            guardado[i] = true;
        }
    }
    forn(i, k){
        if(guardado[i] == false){
            res.push_back(i);
            guardado[i] = true;
        }
    }
    for(auto i: res){
        cout << i+1 << " ";
    }
}

int mini[301][25];
bool visitado[301][25];
int dp[1 << 26][26];

int main(){
    #ifdef EBUG
        freopen("input.txt", "r", stdin);
    #endif
    cin >> n >> k;
    forn(i, n){
        int p;
        cin >> p;
        v.push_back(p-1);
    }

    if(k >= 25){
        solve25();
        return 0;
    }

    forn(i, n){
        fora(i, j, n){
            if(!visitado[i][v[j]]){
                visitado[i][v[j]] = true;
                mini[i][v[j]] = j;
            }
        }
    }
    forn(i, n){
        fora(i, j, n){
            if(!visitado[i][v[j]]){
                visitado[i][v[j]] = true;
                mini[i][v[j]] = j;
            }
        }
    }

}