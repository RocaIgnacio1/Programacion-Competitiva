#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    vector<vector<int>> G(n);

    // ...input the graph

    queue<int> q; vector<int> dist(n, -1); vector<int> parent(n, -1);
    
    q.push(0);
    dist[0] = 0;
    while(!q.empty()){
        int n = q.front(); q.pop();
 
        for (int adj : G[n]) {
            if (dist[adj] == -1) {
                dist[adj] = dist[n] + 1;
                parent[adj] = n;
                q.push(adj);
            }
        }
    }
 
    if (dist[n-1] == -1) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
 
    // recorrer el padre de cada nodo hsata llegar
    vector<int> path;
    int currentNode = n-1;
    path.push_back(n-1);
    while (parent[currentNode] != -1) {
        path.push_back(parent[currentNode]);
        currentNode = parent[currentNode];
    }
 
    // printing path from source to destination, path its reversed
    cout << path.size() << '\n';
    for (int i = path.size() - 1; i >= 0; i--) {
        cout << path[i] + 1 << " ";
    }
}
