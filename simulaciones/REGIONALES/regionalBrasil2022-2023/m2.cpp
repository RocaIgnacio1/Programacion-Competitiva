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
    bool visitado[1001][101];
    bool visitado2[1001][101];
    int R, C;
    bitset<100> a1, a2;
    vector<bitset<100>> b1;

    void movDer(bitset<100> &a1){
        bool w = false;
        if(a1[0]) w = true;
        a1 >>= 1;
        if(w)a1.set(C-1, true);
    }
    bool cmp(int fila, bitset<100> &a1){
        return (b1[fila] & a1).none();
    }
    int path[1001][101];
    int path2[1001][101];
    bool dfs(int x, int y, bool dp[1001][101], int path[1001][101], bool visitado[1001][101]){
        visitado[x][y] = true;
        if(path[x][y] != -1) return path[x][y];
        if(x == R-1) return true;
        int a = x, b = y;
        if(y > 0) b = y-1; else b = C-1;
        if(!visitado[a][b] && dp[a][b] && dfs(a, b, dp, path, visitado)) return path[x][y] = 1;
        a = x, b = y;
        if(y == C-1) b = 0; 
        else b = y+1;
        if(!visitado[a][b] && dp[a][b] && dfs(a, b, dp, path, visitado)) return path[x][y] = 1;
        a = x, b = y;
        if(x > 0) a = x-1;
        if(!visitado[a][b] && dp[a][b] && dfs(a, b, dp, path, visitado)) return path[x][y] = 1;
        a = x+1, b = y;
        if(!visitado[a][b] && dp[a][b] && dfs(a, b, dp, path, visitado)) return path[x][y] = 1;
        return path[x][y] = 0;
    }
    int main(){
        #ifdef EBUG
            freopen("input.txt", "r", stdin);
        #endif
        ios :: sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        cin >> R >> C;
        a1.reset();
        a2.reset();
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
                visitado[j][i] = false;
                visitado2[j][i] = false;
                dp[j][i] = false;
                dp2[j][i] = false;
                path[j][i] = -1;
                path2[j][i] = -1;
                if(a == '1') aux1[i] = 1;
                
            }
            c.push_back(l);
            b1.push_back(aux1);
        }
        forn(j, R){
            forn(i, C){
                dp[j][i] = cmp(j, a1);
                movDer(a1);
            }
        }
        forn(j, R){
            forn(i, C){
                dp2[j][i] = cmp(j, a2);
                movDer(a2);
            }
        }
        forn(i, C){
            if(dp[0][i] && dfs(0,i,dp,path, visitado)){
                cout << "Y\n";
                return 0;
            } 
        }
        forn(i, C){
            if(dp2[0][i] && dfs(0,i,dp2,path2, visitado2)){
                cout << "Y\n";
                return 0;
            } 
        }
        cout << "N\n";
    }