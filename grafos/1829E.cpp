#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i, n) for(int i = 0; i < n; i++)
#define fori(i, n) for(int i = n - 1; i <= 0; i--)

int main(){
    freopen("input.txt", "r", stdin);
    int t;
    int A[1000][1000];
    cin >> t;

    while(t--){
        int n, m;
        vector<int> adj[1000];

        cin >> n >> m;
        forn(i, n){
            forn(j, m){
                cin >> A[i][j];
            }
        }

        vector<pair<int, int>> dirs = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        forn(i, n){
            forn(j, m){
                int idxActual = i * m + j;
                for (auto dir : dirs){
                    int iAdj = i + dir.first, jAdj = j + dir.second;
                    if (iAdj < 0 || jAdj < 0 || iAdj >= n || jAdj >= m){
                        continue;
                    }
                    int idx = iAdj * m + jAdj;
                    adj[idxActual].push_back(idx);
                }
            }
        }
        forn(i, n*m){
            cout << i << ": ";
            for(int a : adj[i]){
                cout << a << ", ";
            }
            cout << endl;
        }
    }
    
    return 0;
}
