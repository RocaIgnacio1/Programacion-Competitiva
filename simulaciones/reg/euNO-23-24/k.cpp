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

int N;
bool visited[503][503][3];
vector<pair<int, int>> moves;

void solve(int i, int j, int m){
    if (i < 0 || j < 0 || i >= N || j >= N){
        return;
    }
    if (visited[i][j][m]) return;
    visited[i][j][m] = true;

    int next_m = (m+1)%2;
    solve(i + moves[m].first,  j + moves[m].second, next_m);
    solve(i - moves[m].first,  j - moves[m].second, next_m);
    solve(i - moves[m].first,  j + moves[m].second, next_m);
    solve(i + moves[m].first,  j - moves[m].second, next_m);
    solve(i + moves[m].second,  j + moves[m].first, next_m);
    solve(i - moves[m].second,  j - moves[m].first, next_m);
    solve(i - moves[m].second,  j + moves[m].first, next_m);
    solve(i + moves[m].second,  j - moves[m].first, next_m);
}

int main(){
    #ifdef EBUG
        freopen("input.txt", "r", stdin);
    #endif
    ios :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    int a, b, c, d;
    cin >> a >> b;
    cin >> c >> d;
    moves.push_back({a, b});
    moves.push_back({c, d});

    forn(i, N){
        forn(j, N){
            visited[i][j][0] = false;
            visited[i][j][1] = false;
        }
    }
    solve(0, 0, 0);
    solve(0, 0, 1);

    int ans = 0;
    forn(i, N){
        forn(j, N){
            ans = ans + (visited[i][j][0] || visited[i][j][1]);
        }
    }
    cout << ans << '\n';
    
    return 0;
}