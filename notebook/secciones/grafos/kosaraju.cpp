#include <bits/stdc++.h>
using namespace std;
#define forr(i, a, b) for(int i = (int) a; i < (int) b; i++)
#define forn(i, n) forr(i, 0, n)
#define dforn(i, n) for(int i = (int)(n-1); i >= 0; i--)
#define pb push_back

// Sacado del olaf
// Not tested, not even a bit
struct Korasaju {
  static const int default_sz = 1000001;
  int n;
  vector< vector<int> > G, revG, C, ady; // ady is the condensed graph
  vector<int> used, where;
  Korasaju(int sz = default_sz){
    n = sz;
    G.assign(sz, vector<int>());
    revG.assign(sz, vector<int>());
    used.assign(sz, 0);
    where.assign(sz, -1);
  }
  void addEdge(int a, int b){ G[a].pb(b); revG[b].pb(a); }
  void dfsNormal(vector<int> &F, int v){
    used[v] = true;
    forn(i, G[v].size()) if(!used[ G[v][i] ])
      dfsNormal(F, G[v][i]);
    F.pb(v);
  }
  void dfsRev(vector<int> &F, int v){
    used[v] = true;
    forn(i, revG[v].size()) if(!used[ revG[v][i] ])
      dfsRev(F, revG[v][i]);
    F.pb(v);
  }
  void build(){
    vector<int> T;
    fill(used.begin(), used.end(), 0);
    forn(i, n) if(!used[i]) dfsNormal(T, i);
    reverse(T.begin(), T.end());
    fill(used.begin(), used.end(), 0);
    forn(i, T.size()) if(!used[ T[i] ]){
      vector<int> F;
      dfsRev(F, T[i]);
      forn(i, F.size()) where[ F[i] ] = C.size();
      C.pb(F);
    }
    ady.resize(C.size()); // Create edges between condensed nodes
    forn(i, n) forn(j, G[i].size()){
      if(where[i] != where[ G[i][j] ]){
        ady[ where[i] ].pb( where[ G[i][j] ] );
      }
    }
    forn(v, C.size()){
      sort(ady[v].begin(), ady[v].end());
      ady[v].erase(unique(ady[v].begin(), ady[v].end()), ady[v].end());
    }
  }
};
