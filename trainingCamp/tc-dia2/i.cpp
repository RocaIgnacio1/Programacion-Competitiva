#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i, n) for(int i = 0; i < n; i++)
#define fori(i, n) for(int i = n - 1; i < 1; i--)

vector<vector<int>> v;

int main(){
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin >> n >> m;
    forn(i, n){
        vector<int> aux;
        forn(j, m){
            int p;
            cin >> p;
            aux.push_back(p);
        }
        v.push_back(aux);
    }
    ll sum;

    for(int i = n - 1; i > 0 ; i--){
        for(int j = m - 1; j > 0 ; j--){
            if(v[i - 1][j - 1] == 0){
                int a = min(v[i][j - 1], v[i - 1][j]);
                v[i-1][j-1] = a - 1;
            }
        }
    }
    forn(i, n-1){
        forn(j, m-1){
            if(v[i][j] >= v[i][j+1] || v[i][j] >= v[i+1][j]){
                cout << "-1" << endl;
                return 0;
            }
        }
    }

    if(v[n-2][m-1] >= v[n-1][m-1] || v[n-1][m-2] >= v[n-1][m-1]){
                cout << "-1" << endl;
                return 0;
            }
    sum = 0;
    forn(i, n){
        forn(j, m){
            sum += v[i][j];
        }
    }

    cout << sum;


}