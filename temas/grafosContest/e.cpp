#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<int> grafo[10000];

int main(){

    freopen("input.txt","r", stdin);
    cin >> n >> m;
    int a,b;
     cin >> n >> m;
    for(int i=0;i<n;i++) grafo[i] = {};
    for(int i=0;i<m;i++){
        int x,y;
        cin >> x >> y;
        grafo[x - 1].push_back(y - 1);
        grafo[y - 1].push_back(x - 1);
    }

    for(int i=0; i < n; i++){
        cout << "NODO: " << i+1;
        cout << " VECINOS: " << i+1;
        for(int j=0; j < grafo[i].size(); j++){
            cout << " " << grafo[i][j];
        }
         cout << endl;
    }



    return 0;
}