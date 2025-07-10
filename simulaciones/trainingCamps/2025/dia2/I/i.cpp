#include <bits/stdc++.h>
#define forn(i, n) for(int i = 0; i < n; i++)
#define DBG(x) cerr << #x << ": " << x << endl;

const int MAXN = 1e5+1;

using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;
    vector<vector<int>> G(n);
    vector<int> A(n);
    vector<bool> visited(n);

    forn(i, n-1){
        int a, b;
        cin >> a >> b; a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    forn(i, n){
        cin >> A[i];
        A[i]--;
    }

    vector<int> level(n, 0);
    unordered_map<int, int> levelSize;
    queue<int> q;

    if (A[0] != 0){
        cout << "No\n"; return 0;
    }
    int a_i = 1;

    q.push(0);
    while(!q.empty()){
        int i = q.front(); q.pop();
        visited[i] = true;
        vector<int> realChilds;

        // cant hijos no visitados
        int childCount = 0;
        forn(j, G[i].size()) {
            if(!visited[G[i][j]]){
                childCount ++;
                realChilds.push_back(G[i][j]);
            }
        }

        vector<int> childs(A.begin()+a_i, A.begin()+a_i+childCount);
        
#ifdef EBUG
        cout << i+1 << ": " << G[i].size() << endl;
        forn(j, childs.size()){
            cout << childs[j]+1 << ' ';
        }cout << endl;
        forn(j, realChilds.size()){
            cout << realChilds[j]+1 << ' ';
        }cout << endl;
#endif

        sort(childs.begin(), childs.end());
        sort(realChilds.begin(), realChilds.end());

        if (childs.size() != childCount) {
#ifdef EBUG
            cout << "no igual largo" << endl;
#endif
            cout << "No\n"; return 0;
        }

        forn(j, childs.size()){ // comparamos los hijos verdaderos con los hijos dados
            if (childs[j] != realChilds[j]) { 
#ifdef EBUG
            cout << "no iguales " << childs[j]+1 << ' ' << realChilds[j]+1 << endl;
#endif
                cout << "No\n"; return 0;
            }
        }
        
        // cout << "pushing: ";
        for (auto it = A.begin()+a_i; it < A.begin()+a_i+childCount; it++) {
            // cout << *it << ' ';
            if (!visited[*it]) q.push(*it);
        }
        // cout << endl;

        a_i += childCount;  // indice comienzo del subarray
    }
    
    cout << "Yes\n";
    return 0;
}
