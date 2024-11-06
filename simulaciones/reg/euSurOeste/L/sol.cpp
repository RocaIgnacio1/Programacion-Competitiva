#include <bits/stdc++.h>
using namespace std;
#define forn(i,n) for(int i = 0; i < n; i++)
typedef long long ll;

int main(){
    int t; cin >> t;

    while(t--){
        int n; cin >> n;

        vector<vector<int>> blocked(42, vector<int>(721, false));
        forn(i, n){
            char l;
            cin >> l;
            if (l == 'C') {
                int r, o1, o2;
                cin >> r >> o1 >> o2;
                for (int i = o1*2; i != o2*2; i = (i + 1) % 720) blocked[r*2][i] = true;
                blocked[r*2][o2*2] = true;
            } else {
                int r1, r2, o;
                cin >> r1 >> r2 >> o;
                for (int i = r1*2; i <= r2*2; i++) blocked[i][o*2] = true;
            }
        }

        vector<vector<bool>> visited(44, vector<bool>(721, false));

        queue<pair<int, int>> q; // r, o
        forn(o, 720){
            q.push({0, o});
            visited[0][o] = true;
        }

        bool yes = false;

        while(!q.empty()) {
            auto [r, o] = q.front(); q.pop();

            if (r >= 40) {
                yes = true;
                break;
            }

            // Ir para arriba
            if (!blocked[r + 1][o] && !visited[r + 1][o]) {
                q.push({r + 1, o});
                visited[r + 1][o] = true;
            }

            if (r - 1 >= 0 && !blocked[r - 1][o] && !visited[r - 1][o]) {
                q.push({r - 1, o});
                visited[r - 1][o] = true;
            }

            //Ir para derecha
            int next_o = (o + 1) % 720;
            if (!blocked[r][next_o] && !visited[r][next_o]) {
                q.push({r, next_o});
                visited[r][next_o] = true;
            }

            // Ir para izquierda
            next_o = (o - 1 + 720) % 720;
            if (!blocked[r][next_o] && !visited[r][next_o]) {
                q.push({r, next_o});
                visited[r][next_o] = true;
            }
        }
        /*forn(i, 20){*/
        /*    forn(j, 100){*/
        /*        //if (visited[i][j]) cout << 'O';*/
        /*        if (blocked[i][j]) cout << '#';*/
        /*        else cout << '.';*/
        /*    }*/
        /*    cout << endl;*/
        /*}*/

        cout << (yes ? "YES" : "NO") << '\n';
    }

    return 0;
}
