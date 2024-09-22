    #include <bits/stdc++.h>
    #include <bitset>
    #include <iostream>
    #include <string>
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

    unordered_set<int> s, s2;
    vector<unordered_set<int>> c;

    bool dp[1001][101], dp2[1001][101];
    bool visitado[1001][101], visitado2[1001][101];
    int R, C;
    bitset<100> a1, a2;
    vector<bitset<100>> b1;

    void movDer(){
        bool w;
        if(a1[0]) w = true;
        a1 >>= 1;
        if(w)a1.set(C-1, true);
    }

    void movDer2(){
        bool w;
        if(a2[0]) w = true;
        a2 >>= 1;
        if(w)a2.set(C-1, true);
    }

    bool cmp2(int fila){
        return (b1[fila] & a2).none();
    }
    bool cmp(int fila){
        return (b1[fila] & a1).none();
    }


    vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    int path[1001][101];
    int dfs(pair<int, int> actual){
        visitado[actual.first][actual.second] = true;
        if (path[actual.first][actual.second] != -1) return path[actual.first][actual.second];
        if (actual.first == R-1) return true;

        int have_path = 0;
        for(auto dir : dirs){
            pair<int, int> neigh = {actual.first + dir.first, actual.second + dir.second};
            if (neigh.first < 0 || neigh.first > R-1) continue;
            if (neigh.second < 0) neigh.second = R-1;
            if (neigh.second > C-1) neigh.second = 0;
            //cout << neigh.first << ", " << neigh.second << ": " << dp[neigh.first][neigh.second] << endl;

            if (dp[neigh.first][neigh.second] && !visitado[neigh.first][neigh.second]) { //Existe un camino
                have_path = dfs(neigh);
                if (have_path == 1) return true;
            }
        }
        return path[actual.first][actual.second] = have_path;
    }

    int path2[1001][101];
    int dfs2(pair<int, int> actual){
        visitado2[actual.first][actual.second] = true;
        if (path2[actual.first][actual.second] != -1) return path2[actual.first][actual.second];
        if (actual.first == R-1) return true;

        int have_path = 0;
        for(auto dir : dirs){
            pair<int, int> neigh = {actual.first + dir.first, actual.second + dir.second};
            if (neigh.first < 0 || neigh.first > R-1) continue;
            if (neigh.second < 0) neigh.second = R-1;
            if (neigh.second > C-1) neigh.second = 0;
            //cout << neigh.first << ", " << neigh.second << ": " << dp[neigh.first][neigh.second] << endl;

            if (dp2[neigh.first][neigh.second] && !visitado2[neigh.first][neigh.second]) { //Existe un camino
                have_path = dfs2(neigh);
                if (have_path == 1) return true;
            }
        }
        return path2[actual.first][actual.second] = have_path;
    }


    int main(){
        #ifdef EBUG
            freopen("input.txt", "r", stdin);
        #endif
        ios :: sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        cin >> R >> C;
        a1 = 0;
        a2 = 0;
        forn(i, C){
            char a;
            cin >> a;
            if(a == '1') a1[i] = 1;
            if(a == '1') a2[C-i-1] = 1;
        }
        forn(j, R){
            unordered_set<int> l;
            bitset<100> aux1;
            forn(i, C){
                char a;
                cin >> a;
                dp[j][i] = -1;
                dp2[j][i] = -1;
                path[j][i] = -1;
                path2[j][i] = -1;
                if(a == '1') aux1[i] = 1;
                
            }
            c.push_back(l);
            b1.push_back(aux1);
        }
        forn(j, R){
            forn(i, C){
                dp[j][i] = cmp(j);
                movDer();
            }
        }
        forn(j, R){
            forn(i, C){
                dp2[j][i] = cmp2(j);
                movDer2();
            }
        }

        /*forn(i, R){
            forn(j, C){
                cout << dp[i][j];
            }cout << endl;
        }*/
        forn(i, C){
            if (dp[0][i] && dfs({0, i})){
                cout << "Y\n";
                return 0;
            }
        }
        forn(i, C){
            if (dp2[0][i] && dfs2({0, i})){
                cout << "Y\n";
                return 0;
            }
        }
        cout << "N\n";
    }