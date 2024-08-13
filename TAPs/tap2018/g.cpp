#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i, n) for(int i = 0; i < n; i++)
#define fora(p, i, n) for(int i = p; i < n; i++)
#define fori(i, n) for(int i = n - 1; i <= 0; i--)

bool solve(int xa, int ya, int xb, int yb, int xc, int yc){
    ll sum = (xc-xa) * (xb-xa) + (yc - ya) * (yb - ya);
    return (sum == 0);
}

int main(){
    //freopen("input.txt","r",stdin);
    int n;
    vector<pair<int, int>> v;
    cin >> n;
    forn(i, n){
        int x, y;
        cin >> x >> y;
        v.push_back(make_pair(x, y));
    }
    int con = 0;
    forn(i, n){
        forn(j, n){
            fora(j, k, n){
                if(i != j && i != k && j != k){
                    if(solve(v[i].first, v[i].second, v[j].first, v[j].second, v[k].first, v[k].second)){
                        con++;
                    }
                }
            }
        }
    }
    cout << con << endl;
}