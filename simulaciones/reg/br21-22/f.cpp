#include <bits/stdc++.h>
using namespace std;
#define forn(i,n) for(int i = 0; i < n; i++)
#define pb push_back
typedef long long ll;
#define MAXN 300010
#ifdef EBUG
//local
#else
//judge
#endif

int N, M;

int main(){
    #ifdef EBUG
        freopen("input.txt", "r", stdin);
    #endif

    vector<int> G[MAXN];

    cin >> N >> M;
    forn(i, M){
        int u, v;
        cin >> u >> v; u--; v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    vector<char> color(N, '*');
    color[N-1] = 'A';
    color[N-2] = 'B';

    queue<int> q;

    q.push(N-2);
    while(!q.empty()){
        int actual = q.front();
        q.pop();

        for (int vecino : G[actual]){
            if (color[vecino] != 'A' && color[vecino] != 'B'){
                color[vecino] = 'B';
                q.push(vecino);
            }
        }
    }

    for(char c : color){
        if (c == '*') c = 'A';
        cout << c;
    }
    cout << endl;

    return 0;
}