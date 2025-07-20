#include <bits/stdc++.h>
#define forr(i, a, b) for (int i = (a); i < (b); i++)
#define forn(i, n) forr(i, 0, n)
#define dforn(i, n) for (int i = (n) - 1; i >= 0; i--)
#define forall(it, v) for (auto it = v.begin(); it != v.end(); it++)

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n; cin >> n;
    int p=0;
    int color = 0;
    int i_color = 0;
    forn(i, n){ 
        if (i%8==0) i_color=color;
        color=i_color;
        forn(j, n){
            if (j%8==0) color++;



            cout << color << ' ';
        }
        cout << '\n';
    }

    return 0;
}