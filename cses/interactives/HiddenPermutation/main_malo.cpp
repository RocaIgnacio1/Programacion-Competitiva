#include <bits/stdc++.h>
#define forr(i, a, b) for (int i = (a); i < (b); i++)
#define forn(i, n) forr(i, 0, n)
#define dforn(i, n) for (int i = (n) - 1; i >= 0; i--)
#define forall(it, v) for (auto it = v.begin(); it != v.end(); it++)
#define dbg(v) cerr << #v << ": " << v << endl;
#define pb push_back

using namespace std;

const int MAXN = 1010;

unordered_set<int> G[MAXN];
int l[MAXN];

// bool is_less(int i, int j){
//     cout << "? " << i+1 << ' ' << j+1 << endl;
//     cout.flush();
//     string ans; cin >> ans;
//     return ans == "YES";
// }

bool is_less(int i, int j){
    return l[i] < l[j];
}

bool v[MAXN];
// bool path(int a, int b){
//     v[a] = true;
//     if (a == b) return true;
//     bool is_path = false;
//     for(auto adj : G[a]){
//         if (!v[adj]){
//             is_path = path(adj, b);
//             if (is_path) break;
//         }
//     }
//     return is_path;
// }

bool path(int a, int b){
    vector<bool> visited(MAXN, false);
    queue<int> q;
    q.push(a);
    visited[a] = true;

    while (!q.empty()) {
        int u = q.front(); q.pop();
        if (u == b) return true;
        for (int v : G[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
    return false;
}

void show_g(int n){
    forn(i, n){
        cout << i+1 << ": ";
        for(auto adj : G[i]) cout << adj+1 << ' ';
        cout << endl;
    }
}

int myrandom (int i) { return rand()%i;}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int n; cin >> n;
    forn(i, n) cin >> l[i];

    vector<int> m;
    forn(i, n) m.pb(i);
    random_shuffle(m.begin(), m.end());

    forn(idx, n){
        int i = m[idx];
        forn(j, n){
            if (i == j) continue;
            if (path(i, j)){ // si hay camino 
                G[i].insert(j);
            }else if(path(j, i)){
                G[j].insert(i);
            }else{ // si no => pregunto
                if (is_less(i, j)){
                    G[i].insert(j);
                }else{
                    G[j].insert(i);
                }
            }
        }
    }

    vector<int> grade(n, 0);
    forn(i, n) for(auto adj : G[i]) {
        grade[adj] += 1;
    }
    cout << "! ";
    forn(i, n){
        cout << grade[i]+1 << ' ';
    }
    cout << endl;

    return 0;
}
