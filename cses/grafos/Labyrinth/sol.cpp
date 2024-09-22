#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for(int i = 0; i < n; i++)
#define DBG(x) cerr << #x << ": " << x << endl;
#define MAXN 1000000
 
typedef long long ll;
typedef pair<int, int> ii;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int start, end;
    char mat[1000][1000];
    int n, m;
    vector<ii> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
 
    cin >> n >> m;
    forn(i, n){
        forn(j, m){
            cin >> mat[i][j];
            if (mat[i][j] == 'A') {
                start = m*i+j;
            }
            if (mat[i][j] == 'B') {
                end = m*i+j;
            }
        }
    }
    vector<vector<int>> G(n * m);
    /*vector<int> G[9000];*/

    // Armar el grafo
    forn(i, n){
        forn(j, m){
            if (mat[i][j] == '#') continue;
            for(ii dir : dirs){
                if (i+dir.first < 0 || i+dir.first > n-1 || j+dir.second < 0 || j+dir.second > m-1) continue;
                if (mat[i+dir.first][j+dir.second] != '#') {
                    G[m*i+j].push_back(m*(i+dir.first)+j+dir.second);
                }
            }
        }
    }

    // La PQ esta ordenada de menor a mayor
    priority_queue<ii, vector<ii>, greater<ii>> q;
    vector<bool> visited(n*m);
    vector<int> distance(n*m, MAXN);
    vector<int> parent(n*m, -1);  // Para reconstruir el camino
    distance[start] = 0;
    q.push({0, start});

    while (!q.empty()) {
        int a = q.top().second; q.pop();
        if (visited[a]) continue;
        visited[a] = true;

        for (auto b : G[a]) {
            if (distance[a]+1 < distance[b]) {
                distance[b] = distance[a]+1;
                parent[b] = a;
                q.push({distance[b], b});
            }
        }
    }

    if (distance[end] != MAXN) {
        cout << "YES" << '\n';
        cout << distance[end] << '\n';
        // Reconstruir el camino
        vector<int> path;
        for (int v = end; v != -1; v = parent[v]) {
            path.push_back(v);
        }

        reverse(path.begin(), path.end()); // El camino está al revés, lo invertimos<< '\n';
        for (int i = 0; i < path.size() - 1; i++) {
            int x1 = path[i] / m, y1 = path[i] % m;
            int x2 = path[i+1] / m, y2 = path[i+1] % m;

            if (x1 == x2 && y2 > y1) { //i a la izq de i+1
                cout << 'R';
            }
            else if (x1 == x2 && y1 > y2) { //i a la der de i+1
                cout << 'L';
            }
            else if (y1 == y2 && x2 > x1) { //i abajo de i+1
                cout << 'D';
            }
            else if (y1 == y2 && x1 > x2) {
                cout << 'U';
            }
        }
    }else{
        cout << "NO" << '\n';
    }
 
    return 0;
}
