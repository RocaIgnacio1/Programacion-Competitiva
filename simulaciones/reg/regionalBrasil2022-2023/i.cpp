#include <bits/stdc++.h>
using namespace std;
#define forn(i,n) for(int i = 0; i < n; i++)
#define fora(p, i,n) for(int i = p; i < n; i++)
#define pb push_back
typedef long long ll;
#define MAXN 1000000010
#ifdef EBUG
//local
#else
//judge
#endif

int r, c;
int mat[101][101];
vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int bfs(int i, int j){
    priority_queue<pair<int, int>> q;
    bool visited[101][101];
    memset(visited, false, sizeof(visited));

    q.push({i, j});
    int count = 0;
    while(!q.empty()){
        pair<int, int> actual = q.top(); q.pop();

        int a = mat[actual.first][actual.second];
        for(auto dir : dirs){
            pair<int, int> neigh = {actual.first + dir.first, actual.second + dir.second};
            if (neigh.first < 0 || 
                neigh.first > r-1 || 
                neigh.second < 0 ||
                neigh.second > c-1
            ) continue;
            //cout << neigh.first << ", " << neigh.second << ": " << mat[neigh.first][neigh.second] << endl;

            if (mat[neigh.first][neigh.second] > a) { //Existe un camino
                 if (!visited[neigh.first][neigh.second]){
                    visited[neigh.first][neigh.second] = true;
                    count ++;
                    q.push(neigh);
                };
            }
        }
    }
    return count + 1;
}

int main(){
    #ifdef EBUG
        freopen("input.txt", "r", stdin);
    #endif
    ios :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin >> r >> c;

    forn(i, r){
        forn(j, c){
            cin >> mat[i][j];
        }
    }

    int res = 0;
    forn(i, r){
        forn(j, c){
            res = max(res, bfs(i, j));
        }
    }

    cout << res << '\n';

    return 0;
}