#include <bits/stdc++.h>
#define forr(i, a, b) for (int i = (a); i < (b); i++)
#define forn(i, n) forr(i, 0, n)
#define dforn(i, n) for (int i = (n) - 1; i >= 0; i--)
#define forall(it, v) for (auto it = v.begin(); it != v.end(); it++)
#define dbg(v) cerr << #v << ": " << v << endl;

using namespace std;
typedef long long ll;
const int MAXN = 2*1e5+10;
const int MAX = INT_MAX;

int main() {
#ifdef EBUG
    freopen("input.txt", "r", stdin);
#endif
    int n, m, r, c;
    ll x, y;
    cin >> n >> m;
    cin >> r >> c;
    cin >> x >> y;

    pair<int, int> t[n+1][m+1]; // izq, der

    forn(i, n) forn(j, m){
        char c; cin >> c;
        if (c == '*'){
            t[i][j] = {MAX, MAX};
        }else{
            t[i][j] = {0, 0};
        }
    }
    t[r-1][c-1] = {x+1, y+1};

    queue<pair<int, int>> q;
    q.push({r-1, c-1});
    vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    while (!q.empty()){
        auto p = q.front(); q.pop();
        int i = p.first;
        int j = p.second;
        forn(dir_i, dirs.size()){
            int adj_i = dirs[dir_i].first + i;
            int adj_j = dirs[dir_i].second + j;
            if (adj_i < 0 || adj_j < 0 || adj_i >= n || adj_j >= m){
                continue;
            }
            if (dir_i == 2){ // izquierda
                //cout << adj_i << ' ' << adj_j << endl;
                //cout << t[i][j].first-1 << ' ' << t[adj_i][adj_j].first << endl;
                if (t[i][j].first-1 > t[adj_i][adj_j].first){
                    t[adj_i][adj_j].first = t[i][j].first-1;
                    t[adj_i][adj_j].second = t[i][j].second;
                    q.push({adj_i, adj_j});
                }
            }else if (dir_i == 3){ // derecha
                if (t[i][j].second-1 > t[adj_i][adj_j].second){
                    t[adj_i][adj_j].second = t[i][j].second-1;
                    t[adj_i][adj_j].first = t[i][j].first;
                    q.push({adj_i, adj_j});
                }
            }else{
                if (
                    t[i][j].first > t[adj_i][adj_j].first ||
                    t[i][j].second > t[adj_i][adj_j].second
                ){
                    t[adj_i][adj_j].first = t[i][j].first;
                    t[adj_i][adj_j].second = t[i][j].second;
                    q.push({adj_i, adj_j});
                }
            }
        }

        /*cout << "IZQ:" << endl;
        forn(i, n){
            forn(j, m){
            if (t[i][j].first > MAX){cout << "# "; continue;}
            cout << t[i][j].first<< ' ';
            } cout << endl;
        }
        cout << endl;
        cout << "DER:" << endl;
        forn(i, n){
            forn(j, m){
            if (t[i][j].second > MAX){cout << "# "; continue;}
            cout << t[i][j].second<< ' ';
            } cout << endl;
        }
        cout << endl;*/
    }

    int ans = 0;
    forn(i, n){
        forn(j, m){
            if ((t[i][j].first > 0 && t[i][j].first < MAX) || 
                (t[i][j].second > 0 && t[i][j].second < MAX)) ans++;
        } 
    }
    cout << ans << endl;
    
    return 0;
}